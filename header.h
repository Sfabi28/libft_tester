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


static inline void write_error_log(int id, const char *msg, const char *expected, const char *got)
{
    FILE *f = fopen("tests_log.log", "a");
    if (f)
    {
        fprintf(f, "Error in Test ID: %d\n", id);
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