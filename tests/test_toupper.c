#include "header.h"

void test_toupper(int n)
{
    if (n == 211) TEST_INT(ft_toupper('a'), 'A');
    else if (n == 212) TEST_INT(ft_toupper('z'), 'Z');
    else if (n == 213) TEST_INT(ft_toupper('m'), 'M');
    else if (n == 214) TEST_INT(ft_toupper('A'), 'A');
    else if (n == 215) TEST_INT(ft_toupper('Z'), 'Z');
    else if (n == 216) TEST_INT(ft_toupper('0'), '0');
    else if (n == 217) TEST_INT(ft_toupper('!'), '!');
    else if (n == 218) TEST_INT(ft_toupper(' '), ' ');
    else if (n == 219) TEST_INT(ft_toupper(0), 0);
    else if (n == 220) TEST_INT(ft_toupper(127), 127);
}
