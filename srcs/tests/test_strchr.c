#include "../header.h"


void test_strchr(int n)
{
    char s[] = "42 Firenze";
    if (n == 231) TEST_INT(ft_strchr(s, 'F') == s + 3, 1);
    else if (n == 232) TEST_INT(ft_strchr(s, 'z') == s + 8, 1);
    else if (n == 233) TEST_INT(ft_strchr(s, '4') == s, 1);
    else if (n == 234) TEST_INT(ft_strchr(s, 'x') == NULL, 1);
    else if (n == 235) TEST_INT(ft_strchr(s, '\0') == s + 10, 1);
    else if (n == 236) TEST_INT(ft_strchr("", 'a') == NULL, 1);
    else if (n == 237) TEST_INT(ft_strchr("abc", 'a') == "abc", 1);
    else if (n == 238) TEST_INT(ft_strchr("aaa", 'a') == "aaa", 1);
    else if (n == 239) TEST_INT(ft_strchr("hello", 'o') == "hello" + 4, 1);
    else if (n == 240) { char s2[] = "test"; TEST_INT(ft_strchr(s2, 't') == s2, 1); }
}
