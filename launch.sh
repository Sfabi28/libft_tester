#!/bin/bash

TIMEOUT_TIME=5
VALGRIND_TARGETS="calloc strdup substr strjoin strtrim split itoa strmapi lstnew lstdelone lstclear lstmap"

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
RESET='\033[0m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'

check_dev_mode() {
    CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD 2>/dev/null)

    if [ "$CURRENT_BRANCH" == "dev" ]; then
        echo -e "\n${MAGENTA}⚠️  WARNING: YOU ARE IN DEVELOPER MODE (dev branch) ⚠️${NC}"
        echo -e "${MAGENTA}This version might be unstable.${NC}"
        echo -e "If you are a student, please switch to stable: ${CYAN}git checkout main${NC}\n"
        sleep 5
    fi
}

check_dev_mode

FUNCTIONS=(
    "1 15 isalpha" "16 30 isdigit" "31 45 isalnum" "46 60 isascii"
    "61 75 isprint" "76 90 strlen" "91 115 memset" "116 130 bzero"
    "131 150 memcpy" "151 170 memmove" "171 190 strlcpy" "191 210 strlcat"
    "211 220 toupper" "221 230 tolower" "231 240 strchr" "241 250 strrchr"
    "251 265 strncmp" "266 280 memchr" "281 300 memcmp" "301 315 strnstr"
    "316 330 atoi" "331 340 calloc" "341 360 strdup" "361 375 substr"
    "376 390 strjoin" "391 410 strtrim" "411 430 split" "431 450 itoa"
    "451 470 strmapi" "471 490 striteri" "491 500 putchar_fd" "501 510 putstr_fd"
    "511 520 putendl_fd" "521 530 putnbr_fd" "531 540 lstnew" "541 550 lstadd_front"
    "551 560 lstsize" "561 570 lstlast" "571 580 lstadd_back" "581 590 lstdelone"
    "591 600 lstclear" "601 610 lstiter" "611 620 lstmap"
)

check_updates() {
    if [ -d ".git" ]; then
        echo -n -e "${CYAN}Checking for updates... ${NC}"
        
        git fetch origin > /dev/null 2>&1
        
        LOCAL=$(git rev-parse HEAD)
        REMOTE=$(git rev-parse @{u} 2>/dev/null)

        if [ -z "$REMOTE" ]; then
            return
        fi

        if [ "$LOCAL" != "$REMOTE" ]; then
            echo -e "${RED}[UPDATE FOUND]${NC}"
            echo -e "\n${YELLOW}🚨  A NEW VERSION IS AVAILABLE!  🚨${NC}"
            echo -e "You are using an old version of the tester."
            echo -e "Do you want to update it now? (Recommended) [y/N]"
            read -r -p "Select: " RESPONSE
            
            if [[ "$RESPONSE" =~ ^[yY]$ ]]; then
                echo -e "${GREEN}Downloading updates...${NC}"
                git pull
                echo -e "\n${GREEN}✅ Update successful!${NC}"
                echo -e "${CYAN}Please restart the tester to apply changes.${NC}"
                exit 0
            else
                echo -e "${YELLOW}Update skipped. Continuing with current version...${NC}\n"
            fi
        else
            echo -e "${GREEN}[UP TO DATE]${NC}"
        fi
    fi
}

get_function_name() {
    local id=$1
    for func in "${FUNCTIONS[@]}"; do
        set -- $func
        local start=$1
        local end=$2
        local name=$3
        if [ $id -ge $start ] && [ $id -le $end ]; then
            echo "$name"
            return
        fi
    done
    echo "unknown"
}

rm -f tests_log.log valgrind_tmp.log
touch tests_log.log

print_header() {
    for func in "${FUNCTIONS[@]}"; do
        set -- $func
        if [ $1 -eq $i ]; then echo -e "\n${YELLOW}$3${NC}"; fi
    done
}

check_allowed_function() {
    echo -e "\n${BLUE}=== ALLOWED FUNCTIONS CHECK ===${RESET}"
    
    WHITELIST_FILE="srcs/.whitelist.txt"
    LIB_PATH="${SOURCE_PATH:-../}"
    BINARY="${LIB_PATH%/}/libft.a"

    if [ ! -f "$BINARY" ]; then
        echo -e "${RED}Error: Library file '$BINARY' not found!${RESET}"
        return
    fi

    UNDEFINED_FUNCS=$(nm -u "$BINARY" | grep -v ":" | awk '{print $NF}' | sort | uniq)
    MY_FUNCS=$(nm "$BINARY" | grep -v ":" | grep -E " [Tt] " | awk '{print $NF}' | sed 's/^_//' | sort | uniq)

    VIOLATION=0
    
    if [ ! -f "$WHITELIST_FILE" ]; then
        echo -e "${YELLOW}Warning: $WHITELIST_FILE not found. Skipping check.${RESET}"
        return
    fi

    ALLOWED_FUNCS=$(cat "$WHITELIST_FILE")

    for func in $UNDEFINED_FUNCS; do
        clean_func=${func%%@*}
        clean_func=${clean_func#_}

        if [[ -z "$clean_func" || "$clean_func" == .* ]]; then continue; fi

        if [[ "$clean_func" == "dyld_stub_binder" || "$clean_func" == "gmon_start" || \
              "$clean_func" == "data_start" || "$clean_func" == "edata" || \
              "$clean_func" == "end" || "$clean_func" == "bss_start" || \
              "$clean_func" == "stack_chk_fail" || "$clean_func" == "_stack_chk_fail" ]]; then
            continue
        fi

        if echo "$MY_FUNCS" | grep -F -x -q "$clean_func"; then continue; fi

        if ! echo "$ALLOWED_FUNCS" | grep -F -x -q "$clean_func"; then
            echo -e "${RED}Forbidden function used: $clean_func${RESET}"
            VIOLATION=1
        fi
    done

    if [ $VIOLATION -eq 0 ]; then
        echo -e "No Forbidden Functions. ${GREEN}[OK]${RESET}"
    else
        echo -e "${RED}Forbidden functions detected!${RESET}"
        if [ -n "$LOG_FILE" ]; then
            echo "FORBIDDEN FUNCTIONS DETECTED" >> "$LOG_FILE"
        fi
    fi
}

run_test_range() {
    START=$1
    END=$2
    PASSED=0
    TOTAL=$((END - START + 1))

    for ((i=START; i<=END; i++)); do
        print_header $i
        
        CURRENT_FUNC=$(get_function_name $i)
        
        if [[ " $VALGRIND_TARGETS " =~ " $CURRENT_FUNC " ]]; then
            LOG=$(timeout ${TIMEOUT_TIME}s valgrind --quiet --leak-check=full --error-exitcode=42 ./tester $i 2>&1 1>/dev/null)
            STATUS=$?
            MODE="VALGRIND"
        else
            LOG=$(timeout ${TIMEOUT_TIME}s ./tester $i 2>&1 1>/dev/null)
            STATUS=$?
            MODE="FAST"
        fi
        
        echo "$LOG" > valgrind_tmp.log

        if [ $STATUS -eq 0 ]; then
            echo -n -e "$i:${GREEN}[OK]${NC} "
            ((PASSED++))
        
        elif [ $STATUS -eq 42 ]; then
            if grep -qE "Invalid|Uninitialised" valgrind_tmp.log; then
                echo -n -e "$i:${RED}[MEM ERR]${NC} "
                echo "-------------------------------------" >> tests_log.log
                echo "Test ID: $i (Function: $CURRENT_FUNC)" >> tests_log.log
                cat valgrind_tmp.log >> tests_log.log
            else
                echo -n -e "$i:${YELLOW}[LEAK]${NC} "
                echo "-------------------------------------" >> tests_log.log
                echo "Test ID: $i (Function: $CURRENT_FUNC)" >> tests_log.log
                echo "Result:  MEMORY LEAK DETECTED" >> tests_log.log
            fi

        elif [ $STATUS -eq 139 ]; then
            echo -n -e "$i:${RED}[CRASH]${NC} "
            echo "-------------------------------------" >> tests_log.log
            echo "Test ID: $i (Function: $CURRENT_FUNC)" >> tests_log.log
            echo "Result:  SEGMENTATION FAULT (CRASH)" >> tests_log.log
            if [ "$MODE" == "VALGRIND" ]; then cat valgrind_tmp.log >> tests_log.log; fi

        elif [ $STATUS -eq 124 ]; then
            echo -n -e "$i:${RED}[TIMEOUT]${NC} "
            echo "-------------------------------------" >> tests_log.log
            echo "Test ID: $i (Function: $CURRENT_FUNC)" >> tests_log.log
            echo "Result:  TIMEOUT (Infinite Loop)" >> tests_log.log

        else
            echo -n -e "$i:${RED}[KO]${NC} "
        fi
    done
    
    rm -f valgrind_tmp.log

    echo -e "\n\n${YELLOW}Results: $PASSED/$TOTAL${NC}"
    if [ $PASSED -lt $TOTAL ]; then
        echo -e "${RED}Check 'tests_log.log' for details.${NC}"
    fi
    make -C ../ fclean > /dev/null
    rm -f tester
}

echo -e "${YELLOW}--- Norminette ---${NC}"
norminette ../*.c ../*.h | grep -E "Error|Warning"
if [ $? -eq 0 ]; then
    echo -e "${RED}Norminette Error!${NC}"
else
    echo -e "${GREEN}Norminette OK!${NC}"
fi

compile_tester() {
    cc -w srcs/main.c srcs/tests/test_*.c -L../ -lft -I../ -o tester
    if [ $? -ne 0 ]; then echo -e "${RED}Tester Compilation Error!${NC}"; exit 1; fi
}

arg1=$1

check_updates

echo -e "${CYAN}Running Smart-Mode: Valgrind enabled only for allocating functions.${RESET}"

if [ -z "$arg1" ]; then
    echo -e "\n${YELLOW}--- Compiling Libft (ALL) ---${NC}"
    make -C ../ bonus > /dev/null 2>&1 || make -C ../ all > /dev/null
    if [ $? -ne 0 ]; then echo -e "${RED}Make failed!${NC}"; exit 1; fi
    
    compile_tester
    check_allowed_function  
    run_test_range 1 620

else
    FOUND=0
    
    for func in "${FUNCTIONS[@]}"; do
        set -- $func
        NAME_NO_FT="$3"

        if [ "$NAME_NO_FT" == "$arg1" ] || [ "ft_$NAME_NO_FT" == "$arg1" ]; then
            
            if [ ! -f "../libft.a" ]; then
                 echo -e "${YELLOW}Libft archive not found. Building base first...${NC}"
                 make -C ../ bonus > /dev/null 2>&1 || make -C ../ all > /dev/null
            fi

            echo -e "${CYAN}--- Compiling only: ft_${NAME_NO_FT}.c ---${NC}"
            
            cc -Wall -Wextra -Werror -c "../ft_${NAME_NO_FT}.c" -o "ft_${NAME_NO_FT}.o" -I../
            if [ $? -ne 0 ]; then
                echo -e "${RED}Error compiling ft_${NAME_NO_FT}.c! Check your code.${NC}"
                rm -f "ft_${NAME_NO_FT}.o"
                exit 1
            fi

            ar rcs ../libft.a "ft_${NAME_NO_FT}.o"
            rm -f "ft_${NAME_NO_FT}.o"
            
            compile_tester
            check_allowed_function 
            run_test_range $1 $2
            FOUND=1
            break
        fi
    done
    if [ $FOUND -eq 0 ]; then
        echo -e "${RED}Function '$arg1' not found.${NC}"
    fi
fi