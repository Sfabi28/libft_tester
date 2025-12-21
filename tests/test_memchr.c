#include "../header.h"

void test_memchr(int n)
{
    char s[] = "42 Firenze";
    if (n == 266) TEST_INT(ft_memchr(s, 'F', 10) == s + 3, 1);
    else if (n == 267) TEST_INT(ft_memchr(s, 'z', 10) == s + 8, 1);
    else if (n == 268) TEST_INT(ft_memchr(s, '4', 10) == s, 1);
    else if (n == 269) TEST_INT(ft_memchr(s, 'x', 10) == NULL, 1);
    else if (n == 270) TEST_INT(ft_memchr(s, 'e', 5) == NULL, 1);
    else if (n == 271) TEST_INT(ft_memchr(s, '\0', 11) == s + 10, 1);
    else if (n == 272) { int i[] = {1, 2, 42, 4}; TEST_INT(ft_memchr(i, 42, 16) != NULL, 1); }
    else if (n == 273) TEST_INT(ft_memchr("abcdef", 'c', 2) == NULL, 1);
    else if (n == 274) TEST_INT(ft_memchr("abcdef", 'c', 3) != NULL, 1);
    else if (n == 275) TEST_INT(ft_memchr("abc", 'a', 0) == NULL, 1);
    else if (n == 276) TEST_INT(ft_memchr("abc", 'c', 3) != NULL, 1);
    else if (n == 277) TEST_INT(ft_memchr("abc", 'd', 3) == NULL, 1);
    else if (n == 278) { char str[] = {0, 1, 2, 3}; TEST_INT(ft_memchr(str, 2, 4) == str + 2, 1); }
    else if (n == 279) TEST_INT(ft_memchr("aaa", 'a', 1) != NULL, 1);
    else if (n == 280) TEST_INT(ft_memchr("aaa", 'b', 3) == NULL, 1);
}
