#include "header.h"

void test_strnstr(int n)
{
    char s[] = "lorem ipsum dolor sit amet";
    if (n == 301) TEST_INT(ft_strnstr(s, "ipsum", 15) == s + 6, 1);
    else if (n == 302) TEST_INT(ft_strnstr(s, "ipsum", 10) == NULL, 1);
    else if (n == 303) TEST_INT(ft_strnstr(s, "dolor", 15) == s + 12, 1);
    else if (n == 304) TEST_INT(ft_strnstr(s, "dolor", 16) == NULL, 1);
    else if (n == 305) TEST_INT(ft_strnstr(s, "lorem", 15) == s, 1);
    else if (n == 306) TEST_INT(ft_strnstr(s, "", 15) == s, 1);
    else if (n == 307) TEST_INT(ft_strnstr(s, "amet", 30) == s + 22, 1);
    else if (n == 308) TEST_INT(ft_strnstr(s, "z", 30) == NULL, 1);
    else if (n == 309) TEST_INT(ft_strnstr("aaabcabcd", "abcd", 9) == "aaabcabcd" + 5, 1);
    else if (n == 310) TEST_INT(ft_strnstr("aaabcabcd", "abcd", 8) == NULL, 1);
    else if (n == 311) TEST_INT(ft_strnstr("12345", "12345", 5) != NULL, 1);
    else if (n == 312) TEST_INT(ft_strnstr("12345", "12345", 4) == NULL, 1);
    else if (n == 313) TEST_INT(ft_strnstr("abc", "abcdef", 10) == NULL, 1);
    else if (n == 314) TEST_INT(ft_strnstr("hello", "he", 1) == NULL, 1);
    else if (n == 315) TEST_INT(ft_strnstr("hello", "hello", 10) != NULL, 1);
}
