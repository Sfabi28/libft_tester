#include "header.h"

void test_memcmp(int n)
{
    if (n == 281) TEST_INT(ft_memcmp("abc", "abc", 3), 0);
    else if (n == 282) TEST_INT(ft_memcmp("abc", "abd", 3) < 0, 1);
    else if (n == 283) TEST_INT(ft_memcmp("abd", "abc", 3) > 0, 1);
    else if (n == 284) TEST_INT(ft_memcmp("abc", "abc", 2), 0);
    else if (n == 285) TEST_INT(ft_memcmp("abc", "abd", 2), 0);
    else if (n == 286) TEST_INT(ft_memcmp("abc", "abd", 0), 0);
    else if (n == 287) { int a[] = {1, 2, 3}; int b[] = {1, 2, 3}; TEST_INT(ft_memcmp(a, b, 12), 0); }
    else if (n == 288) { int a[] = {1, 2, 3}; int b[] = {1, 2, 4}; TEST_INT(ft_memcmp(a, b, 12) < 0, 1); }
    else if (n == 289) TEST_INT(ft_memcmp("atoms\0tail", "atoms\0head", 10) != 0, 1);
    else if (n == 290) TEST_INT(ft_memcmp("\200", "\0", 1) > 0, 1);
    else if (n == 291) TEST_INT(ft_memcmp("a", "b", 1) < 0, 1);
    else if (n == 292) TEST_INT(ft_memcmp("b", "a", 1) > 0, 1);
    else if (n == 293) TEST_INT(ft_memcmp("abc", "abc", 1), 0);
    else if (n == 294) TEST_INT(ft_memcmp("abc", "acc", 2) < 0, 1);
    else if (n == 295) TEST_INT(ft_memcmp("abc", "abb", 3) > 0, 1);
    else if (n == 296) TEST_INT(ft_memcmp("test", "test", 4), 0);
    else if (n == 297) TEST_INT(ft_memcmp("test", "tost", 1), 0);
    else if (n == 298) TEST_INT(ft_memcmp("test", "tost", 2) < 0, 1);
    else if (n == 299) TEST_INT(ft_memcmp("123", "124", 3) < 0, 1);
    else if (n == 300) TEST_INT(ft_memcmp("123", "123", 3), 0);
}