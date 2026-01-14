#include "../header.h"

void test_isalnum(int n)
{
    if (n == 31)      TEST_INT(ft_isalnum('a'), 1);
    else if (n == 32) TEST_INT(ft_isalnum('z'), 1);
    else if (n == 33) TEST_INT(ft_isalnum('A'), 1);
    else if (n == 34) TEST_INT(ft_isalnum('Z'), 1);
    else if (n == 35) TEST_INT(ft_isalnum('0'), 1);
    else if (n == 36) TEST_INT(ft_isalnum('9'), 1);
    else if (n == 37) TEST_INT(ft_isalnum('5'), 1);
    else if (n == 38) TEST_INT(ft_isalnum(' '), 0);
    else if (n == 39) TEST_INT(ft_isalnum('!'), 0);
    else if (n == 40) TEST_INT(ft_isalnum('\n'), 0);
    else if (n == 41) TEST_INT(ft_isalnum(0), 0);
    else if (n == 42) TEST_INT(ft_isalnum(127), 0);
    else if (n == 43) TEST_INT(ft_isalnum(128), 0);
    else if (n == 44) TEST_INT(ft_isalnum(-1), 0);
    else if (n == 45) TEST_INT(ft_isalnum('?'), 0);
}