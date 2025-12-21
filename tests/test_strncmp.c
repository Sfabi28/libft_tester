#include "header.h"

void test_strncmp(int n)
{
    if (n == 251) TEST_INT(ft_strncmp("abc", "abc", 3), 0);
    else if (n == 252) TEST_INT(ft_strncmp("abc", "abd", 3) < 0, 1);
    else if (n == 253) TEST_INT(ft_strncmp("abd", "abc", 3) > 0, 1);
    else if (n == 254) TEST_INT(ft_strncmp("abc", "abc", 2), 0);
    else if (n == 255) TEST_INT(ft_strncmp("abcdef", "abc", 3), 0);
    else if (n == 256) TEST_INT(ft_strncmp("abc", "abcdef", 3), 0);
    else if (n == 257) TEST_INT(ft_strncmp("abc", "abcdef", 4) < 0, 1);
    else if (n == 258) TEST_INT(ft_strncmp("", "", 1), 0);
    else if (n == 259) TEST_INT(ft_strncmp("test", "test", 0), 0);
    else if (n == 260) TEST_INT(ft_strncmp("test", "tost", 1), 0);
    else if (n == 261) TEST_INT(ft_strncmp("tost", "test", 2) > 0, 1);
    else if (n == 262) TEST_INT(ft_strncmp("atoms\0", "atoms\0tail", 10), 0);
    else if (n == 263) TEST_INT(ft_strncmp("\200", "\0", 1) > 0, 1);
    else if (n == 264) TEST_INT(ft_strncmp("abc", "abd", 0), 0);
    else if (n == 265) TEST_INT(ft_strncmp("12345", "12344", 5) > 0, 1);
}