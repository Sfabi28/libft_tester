#include "header.h"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: ./tester <test_id>\n");
        return (1);
    }

    int n = atoi(argv[1]);

    if (n <= 15) test_isalpha(n);
    else if (n <= 30) test_isdigit(n);
    else if (n <= 45) test_isalnum(n);
    else if (n <= 60) test_isascii(n);
    else if (n <= 75) test_isprint(n);
    else if (n <= 90) test_strlen(n);
    else if (n <= 115) test_memset(n);
    else if (n <= 130) test_bzero(n);
    else if (n <= 150) test_memcpy(n);
    else if (n <= 170) test_memmove(n);
    /////////
    else if (n <= 190) test_strlcpy(n);
    else if (n <= 210) test_strlcat(n);
    else if (n <= 220) test_toupper(n);
    else if (n <= 230) test_tolower(n);
    else if (n <= 240) test_strchr(n);
    else if (n <= 250) test_strrchr(n);
    else if (n <= 265) test_strncmp(n);
    else if (n <= 280) test_memchr(n);
    else if (n <= 300) test_memcmp(n);
    else if (n <= 315) test_strnstr(n);
    else if (n <= 330) test_atoi(n);
    else if (n <= 340) test_calloc(n);
    else if (n <= 360) test_strdup(n);

    else if (n <= 375) test_substr(n);
    else if (n <= 390) test_strjoin(n);
    else if (n <= 410) test_strtrim(n);
    else if (n <= 430) test_split(n);
    else if (n <= 450) test_itoa(n);
    else if (n <= 470) test_strmapi(n);
    else if (n <= 490) test_striteri(n);
    else if (n <= 500) test_putchar_fd(n);
    else if (n <= 510) test_putstr_fd(n);
    else if (n <= 520) test_putendl_fd(n);
    else if (n <= 530) test_putnbr_fd(n);

    else if (n <= 540) test_lstnew(n);
    else if (n <= 550) test_lstadd_front(n);
    else if (n <= 560) test_lstsize(n);
    else if (n <= 570) test_lstlast(n);
    else if (n <= 580) test_lstadd_back(n);
    else if (n <= 590) test_lstdelone(n);
    else if (n <= 600) test_lstclear(n);
    else if (n <= 610) test_lstiter(n);
    else if (n <= 620) test_lstmap(n);

    else
        printf("Test ID non valido!\n");

    return (0);
}