#include "header.h"

void test_isdigit(int n)
{
    if (n == 16)      TEST_INT(ft_isdigit('0'), 1);
    else if (n == 17) TEST_INT(ft_isdigit('1'), 1);
    else if (n == 18) TEST_INT(ft_isdigit('2'), 1);
    else if (n == 19) TEST_INT(ft_isdigit('3'), 1);
    else if (n == 20) TEST_INT(ft_isdigit('4'), 1);
    else if (n == 21) TEST_INT(ft_isdigit('5'), 1);
    else if (n == 22) TEST_INT(ft_isdigit('6'), 1);
    else if (n == 23) TEST_INT(ft_isdigit('7'), 1);
    else if (n == 24) TEST_INT(ft_isdigit('8'), 1);
    else if (n == 25) TEST_INT(ft_isdigit('9'), 1);
    else if (n == 26) TEST_INT(ft_isdigit('a'), 0);
    else if (n == 27) TEST_INT(ft_isdigit(' '), 0);
    else if (n == 28) TEST_INT(ft_isdigit(0), 0);
    else if (n == 29) TEST_INT(ft_isdigit(127), 0);
    else if (n == 30) TEST_INT(ft_isdigit(-1), 0);
}