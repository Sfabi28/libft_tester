#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

# define TEST_INT(func, expected) \
    do { \
        int res = func; \
        printf("%s: ", #func); \
        if (res == expected) \
            printf(GREEN "[OK]\n" RESET); \
        else \
            printf(RED "[KO]\n" RESET); \
    } while (0)


# define TEST_STR(func, expected) \
    do { \
        char *res = func; \
        printf("%s: ", #func); \
        if (res && expected && strcmp(res, expected) == 0) \
            printf(GREEN "[OK]\n" RESET); \
        else if (!res && !expected) \
            printf(GREEN "[OK]\n" RESET); \
        else \
            printf(RED "[KO]\n" RESET); \
    } while (0)

# define TEST_MEM(func, expected, n) \
    do { \
        void *res = func; \
        printf("%s (%zu bytes): ", #func, (size_t)n); \
        if (memcmp(res, expected, n) == 0) \
            printf(GREEN "[OK]\n" RESET); \
        else \
            printf(RED "[KO]\n" RESET); \
    } while (0)

void test_isalpha(); void test_isdigit(); void test_isalnum();
void test_isascii(); void test_isprint(); void test_strlen();
void test_memset();  void test_bzero();   void test_memcpy();
void test_memmove(); void test_strlcpy(); void test_strlcat();
void test_toupper(); void test_tolower(); void test_strchr();
void test_strrchr(); void test_strncmp(); void test_memchr();
void test_memcmp();  void test_strnstr(); void test_atoi();
void test_calloc();  void test_strdup();

void test_substr();  void test_strjoin(); void test_strtrim();
void test_split();   void test_itoa();    void test_strmapi();
void test_striteri();void test_putchar_fd(); void test_putstr_fd();
void test_putendl_fd(); void test_putnbr_fd();

void test_lstnew();  void test_lstadd_front(); void test_lstsize();
void test_lstlast(); void test_lstadd_back();  void test_lstdelone();
void test_lstclear();void test_lstiter();      void test_lstmap();

#endif