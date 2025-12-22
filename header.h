#ifndef HEADER_H
# define HEADER_H

# include "../libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>


static const char *get_function_name(int id) {
    if (id <= 15) return "isalpha";
    else if (id <= 30) return "isdigit";
    else if (id <= 45) return "isalnum";
    else if (id <= 60) return "isascii";
    else if (id <= 75) return "isprint";
    else if (id <= 90) return "strlen";
    else if (id <= 115) return "memset";
    else if (id <= 130) return "bzero";
    else if (id <= 150) return "memcpy";
    else if (id <= 170) return "memmove";
    else if (id <= 190) return "strlcpy";
    else if (id <= 210) return "strlcat";
    else if (id <= 220) return "toupper";
    else if (id <= 230) return "tolower";
    else if (id <= 240) return "strchr";
    else if (id <= 250) return "strrchr";
    else if (id <= 265) return "strncmp";
    else if (id <= 280) return "memchr";
    else if (id <= 300) return "memcmp";
    else if (id <= 315) return "strnstr";
    else if (id <= 330) return "atoi";
    else if (id <= 340) return "calloc";
    else if (id <= 360) return "strdup";
    else if (id <= 375) return "substr";
    else if (id <= 390) return "strjoin";
    else if (id <= 410) return "strtrim";
    else if (id <= 430) return "split";
    else if (id <= 450) return "itoa";
    else if (id <= 470) return "strmapi";
    else if (id <= 490) return "striteri";
    else if (id <= 500) return "putchar_fd";
    else if (id <= 510) return "putstr_fd";
    else if (id <= 520) return "putendl_fd";
    else if (id <= 530) return "putnbr_fd";
    else if (id <= 540) return "lstnew";
    else if (id <= 550) return "lstadd_front";
    else if (id <= 560) return "lstsize";
    else if (id <= 570) return "lstlast";
    else if (id <= 580) return "lstadd_back";
    else if (id <= 590) return "lstdelone";
    else if (id <= 600) return "lstclear";
    else if (id <= 610) return "lstiter";
    else if (id <= 620) return "lstmap";
    return "unknown";
}

static inline void write_error_log(int id, const char *msg, const char *expected, const char *got)
{
    FILE *f = fopen("tests_log.log", "a");
    if (f)
    {
        const char *func_name = get_function_name(id);
        fprintf(f, "Error in Test ID: %d (Function: %s)\n", id, func_name);
        fprintf(f, "Expected: [%s]\n", expected ? expected : "NULL");
        fprintf(f, "Got     : [%s]\n", got ? got : "NULL");
        fprintf(f, "-------------------------------------\n");
        fclose(f);
    }
}

# define TEST_INT(got, expected) \
    do { \
        int g = (got); \
        int e = (expected); \
        if (g != e) { \
            char sg[20], se[20]; \
            sprintf(sg, "%d", g); sprintf(se, "%d", e); \
            write_error_log(n, "INT CHECK", se, sg); \
            exit(1); \
        } \
    } while (0)


# define TEST_STR(got, expected) \
    do { \
        char *g = (got); \
        char *e = (expected); \
        if ((!g && e) || (g && !e) || (g && e && strcmp(g, e) != 0)) { \
            write_error_log(n, "STR CHECK", e, g); \
            exit(1); \
        } \
    } while (0)


# define TEST_MEM(got, expected, len) \
    do { \
        if (memcmp(got, expected, len) != 0) { \
            write_error_log(n, "MEM CHECK", "Memory match", "Memory mismatch"); \
            exit(1); \
        } \
    } while (0)


void test_isalpha(int n); void test_isdigit(int n); void test_isalnum(int n);
void test_isascii(int n); void test_isprint(int n); void test_strlen(int n);
void test_memset(int n);  void test_bzero(int n);   void test_memcpy(int n);
void test_memmove(int n); void test_strlcpy(int n); void test_strlcat(int n);
void test_toupper(int n); void test_tolower(int n); void test_strchr(int n);
void test_strrchr(int n); void test_strncmp(int n); void test_memchr(int n);
void test_memcmp(int n);  void test_strnstr(int n); void test_atoi(int n);
void test_calloc(int n);  void test_strdup(int n);
void test_substr(int n);  void test_strjoin(int n); void test_strtrim(int n);
void test_split(int n);   void test_itoa(int n);    void test_strmapi(int n);
void test_striteri(int n);void test_putchar_fd(int n); void test_putstr_fd(int n);
void test_putendl_fd(int n); void test_putnbr_fd(int n);
void test_lstnew(int n);  void test_lstadd_front(int n); void test_lstsize(int n);
void test_lstlast(int n); void test_lstadd_back(int n);  void test_lstdelone(int n);
void test_lstclear(int n);void test_lstiter(int n);      void test_lstmap(int n);

#endif