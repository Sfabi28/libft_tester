#include "../header.h"

void test_isprint(int n)
{
    if (n == 61)      TEST_INT(ft_isprint(32), 1);
    else if (n == 62) TEST_INT(ft_isprint(126), 1);
    else if (n == 63) TEST_INT(ft_isprint('A'), 1);
    else if (n == 64) TEST_INT(ft_isprint('0'), 1);
    else if (n == 65) TEST_INT(ft_isprint('~'), 1);
    else if (n == 66) TEST_INT(ft_isprint(31), 0);
    else if (n == 67) TEST_INT(ft_isprint(127), 0);
    else if (n == 68) TEST_INT(ft_isprint('\n'), 0);
    else if (n == 69) TEST_INT(ft_isprint('\t'), 0);
    else if (n == 70) TEST_INT(ft_isprint(0), 0);
    else if (n == 71) TEST_INT(ft_isprint(128), 0);
    else if (n == 72) TEST_INT(ft_isprint(-1), 0);
    else if (n == 73) TEST_INT(ft_isprint(1), 0);
    else if (n == 74) TEST_INT(ft_isprint(255), 0);
    else if (n == 75) TEST_INT(ft_isprint(' '), 1);
}