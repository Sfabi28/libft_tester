#include "../header.h"

void test_strlen(int n)
{
    if (n == 76)      TEST_INT(ft_strlen(""), 0);
    else if (n == 77) TEST_INT(ft_strlen("a"), 1);
    else if (n == 78) TEST_INT(ft_strlen("abc"), 3);
    else if (n == 79) TEST_INT(ft_strlen("42 toscana"), 10);
    else if (n == 80) TEST_INT(ft_strlen(" "), 1);
    else if (n == 81) TEST_INT(ft_strlen("\n"), 1);
    else if (n == 82) TEST_INT(ft_strlen("\0"), 0);
    else if (n == 83) TEST_INT(ft_strlen("0123456789"), 10);
    else if (n == 84) TEST_INT(ft_strlen("Lorem ipsum dolor sit amet"), 26);
    else if (n == 85) TEST_INT(ft_strlen("Special chars: !@#$%^&*()"), 25);
    else if (n == 86) TEST_INT(ft_strlen("Long string test for buffer check............................"), 61);
    else if (n == 87) TEST_INT(ft_strlen("\t\v\f\r"), 4);
    else if (n == 88) TEST_INT(ft_strlen("    "), 4);
    else if (n == 89) TEST_INT(ft_strlen("Testing..."), 10);
    else if (n == 90) TEST_INT(ft_strlen("Final test"), 10);
}