#include "../header.h"

void test_isascii(int n)
{
    if (n == 46)      TEST_INT(ft_isascii(0), 1);
    else if (n == 47) TEST_INT(ft_isascii(127), 1);
    else if (n == 48) TEST_INT(ft_isascii(65), 1);
    else if (n == 49) TEST_INT(ft_isascii(32), 1);
    else if (n == 50) TEST_INT(ft_isascii(42), 1);
    else if (n == 51) TEST_INT(ft_isascii(1), 1);
    else if (n == 52) TEST_INT(ft_isascii(126), 1);
    else if (n == 53) TEST_INT(ft_isascii(-1), 0);
    else if (n == 54) TEST_INT(ft_isascii(128), 0);
    else if (n == 55) TEST_INT(ft_isascii(256), 0);
    else if (n == 56) TEST_INT(ft_isascii(1000), 0);
    else if (n == 57) TEST_INT(ft_isascii(-128), 0);
    else if (n == 58) TEST_INT(ft_isascii(500), 0);
    else if (n == 59) TEST_INT(ft_isascii(130), 0);
    else if (n == 60) TEST_INT(ft_isascii(200), 0);
}