#include "../header.h"

void test_isalpha(int n)
{
    if (n == 1)       TEST_INT(ft_isalpha('a'), 1);
    else if (n == 2)  TEST_INT(ft_isalpha('z'), 1);
    else if (n == 3)  TEST_INT(ft_isalpha('A'), 1);
    else if (n == 4)  TEST_INT(ft_isalpha('Z'), 1);
    else if (n == 5)  TEST_INT(ft_isalpha('m'), 1);
    else if (n == 6)  TEST_INT(ft_isalpha('Q'), 1);
    else if (n == 7)  TEST_INT(ft_isalpha('0'), 0);
    else if (n == 8)  TEST_INT(ft_isalpha('9'), 0);
    else if (n == 9)  TEST_INT(ft_isalpha(' '), 0);
    else if (n == 10) TEST_INT(ft_isalpha('!'), 0);
    else if (n == 11) TEST_INT(ft_isalpha('\n'), 0);
    else if (n == 12) TEST_INT(ft_isalpha(0), 0);
    else if (n == 13) TEST_INT(ft_isalpha(127), 0);
    else if (n == 14) TEST_INT(ft_isalpha(128), 0);
    else if (n == 15) TEST_INT(ft_isalpha(-1), 0);
}