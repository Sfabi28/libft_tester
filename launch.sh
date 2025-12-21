#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
YELLOW='\033[1;33m'

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

rm -f tests_log.log valgrind_tmp.log
touch tests_log.log

print_header() {
    for func in "${FUNCTIONS[@]}"; do
        set -- $func
        if [ $1 -eq $i ]; then echo -e "\n${YELLOW}$3${NC}"; fi
    done
}

run_test_range() {
    START=$1
    END=$2
    PASSED=0
    TOTAL=$((END - START + 1))

    for ((i=START; i<=END; i++)); do
        print_header $i
        
        valgrind --quiet --leak-check=full --error-exitcode=42 ./tester $i > /dev/null 2> valgrind_tmp.log
        STATUS=$?

        if [ $STATUS -eq 0 ]; then
            echo -n -e "$i:${GREEN}[OK]${NC} "
            ((PASSED++))
        elif [ $STATUS -eq 42 ]; then
            echo -n -e "$i:${YELLOW}[LEAK]${NC} "
            echo "-------------------------------------" >> tests_log.log
            echo "Test ID: $i" >> tests_log.log
            echo "Result:  MEMORY LEAK DETECTED" >> tests_log.log
            echo "-------------------------------------" >> tests_log.log
        elif [ $STATUS -eq 139 ]; then
            echo -n -e "$i:${RED}[CRASH]${NC} "
            echo "-------------------------------------" >> tests_log.log
            echo "Test ID: $i" >> tests_log.log
            echo "Result:  SEGMENTATION FAULT (CRASH)" >> tests_log.log
            echo "-------------------------------------" >> tests_log.log
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
}

echo -e "${YELLOW}--- Norminette ---${NC}"
norminette ../*.c ../*.h | grep -E "Error|Warning"
if [ $? -eq 0 ]; then
    echo -e "${RED}Norminette Error!${NC}"
else
    echo -e "${GREEN}Norminette OK!${NC}"
fi

echo -e "\n${YELLOW}--- Compiling Libft ---${NC}"
make -C ../ re > /dev/null

cc -w main.c tests/test_*.c -L../ -lft -o tester
if [ $? -ne 0 ]; then echo -e "${RED}Error!${NC}"; exit 1; fi

arg1=$1

if [ -z "$arg1" ]; then
    run_test_range 1 620
else
    FOUND=0
    for func in "${FUNCTIONS[@]}"; do
        set -- $func
        if [ "$3" == "$arg1" ] || [ "$3" == "ft_$arg1" ]; then
            run_test_range $1 $2
            FOUND=1
            break
        fi
    done
    if [ $FOUND -eq 0 ]; then
        echo -e "${RED}Function '$arg1' not found.${NC}"
    fi
fi