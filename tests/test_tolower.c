#include "header.h"


void test_tolower(int n)
{
    if (n == 221) TEST_INT(ft_tolower('A'), 'a');
    else if (n == 222) TEST_INT(ft_tolower('Z'), 'z');
    else if (n == 223) TEST_INT(ft_tolower('Q'), 'q');
    else if (n == 224) TEST_INT(ft_tolower('a'), 'a');
    else if (n == 225) TEST_INT(ft_tolower('z'), 'z');
    else if (n == 226) TEST_INT(ft_tolower('5'), '5');
    else if (n == 227) TEST_INT(ft_tolower('@'), '@');
    else if (n == 228) TEST_INT(ft_tolower('\n'), '\n');
    else if (n == 229) TEST_INT(ft_tolower(0), 0);
    else if (n == 230) TEST_INT(ft_tolower(128), 128);
}
