#include "header.h"

void test_strtrim(int n)
{
    char *res;

    if (n == 391) { res = ft_strtrim("  hello  ", " "); TEST_STR(res, "hello"); free(res); }
    else if (n == 392) { res = ft_strtrim("...hello...", "."); TEST_STR(res, "hello"); free(res); }
    else if (n == 393) { res = ft_strtrim("abcHELLOabc", "abc"); TEST_STR(res, "HELLO"); free(res); }
    else if (n == 394) { res = ft_strtrim("123456", "123"); TEST_STR(res, "456"); free(res); }
    else if (n == 395) { res = ft_strtrim("123456", "456"); TEST_STR(res, "123"); free(res); }
    else if (n == 396) { res = ft_strtrim("   ", " "); TEST_STR(res, ""); free(res); }
    else if (n == 397) { res = ft_strtrim("hello", ""); TEST_STR(res, "hello"); free(res); }
    else if (n == 398) { res = ft_strtrim("", "abc"); TEST_STR(res, ""); free(res); }
    else if (n == 399) { res = ft_strtrim("abcd", "efgh"); TEST_STR(res, "abcd"); free(res); }
    else if (n == 400) { res = ft_strtrim("abbcccba", "abc"); TEST_STR(res, ""); free(res); }
    else if (n == 401) { res = ft_strtrim("  \t \n hello \n \t  ", " \n\t"); TEST_STR(res, "hello"); free(res); }
    else if (n == 402) { res = ft_strtrim("lorem ipsum", "l"); TEST_STR(res, "orem ipsum"); free(res); }
    else if (n == 403) { res = ft_strtrim("lorem ipsum", "m"); TEST_STR(res, "lorem ipsu"); free(res); }
    else if (n == 404) { res = ft_strtrim("xxyyzyyx", "xy"); TEST_STR(res, "z"); free(res); }
    else if (n == 405) { res = ft_strtrim("xxxx", "x"); TEST_STR(res, ""); free(res); }
}
