#include "../header.h"

void test_itoa(int n)
{
    char *res;

    if (n == 431) { res = ft_itoa(0); TEST_STR(res, "0"); free(res); }
    else if (n == 432) { res = ft_itoa(42); TEST_STR(res, "42"); free(res); }
    else if (n == 433) { res = ft_itoa(-42); TEST_STR(res, "-42"); free(res); }
    else if (n == 434) { res = ft_itoa(2147483647); TEST_STR(res, "2147483647"); free(res); }
    else if (n == 435) { res = ft_itoa(-2147483648); TEST_STR(res, "-2147483648"); free(res); }
    else if (n == 436) { res = ft_itoa(100); TEST_STR(res, "100"); free(res); }
    else if (n == 437) { res = ft_itoa(-1); TEST_STR(res, "-1"); free(res); }
    else if (n == 438) { res = ft_itoa(10); TEST_STR(res, "10"); free(res); }
    else if (n == 439) { res = ft_itoa(-10); TEST_STR(res, "-10"); free(res); }
    else if (n == 440) { res = ft_itoa(12345); TEST_STR(res, "12345"); free(res); }
    else if (n == 441) { res = ft_itoa(-12345); TEST_STR(res, "-12345"); free(res); }
    else if (n == 442) { res = ft_itoa(9); TEST_STR(res, "9"); free(res); }
    else if (n == 443) { res = ft_itoa(-9); TEST_STR(res, "-9"); free(res); }
    else if (n == 444) { res = ft_itoa(1000000); TEST_STR(res, "1000000"); free(res); }
    else if (n == 445) { res = ft_itoa(-1000000); TEST_STR(res, "-1000000"); free(res); }
    else if (n == 446) { res = ft_itoa(2147483646); TEST_STR(res, "2147483646"); free(res); }
    else if (n == 447) { res = ft_itoa(-2147483647); TEST_STR(res, "-2147483647"); free(res); }
    else if (n == 448) { res = ft_itoa(111); TEST_STR(res, "111"); free(res); }
    else if (n == 449) { res = ft_itoa(-111); TEST_STR(res, "-111"); free(res); }
    else if (n == 450) { res = ft_itoa(42); TEST_STR(res, "42"); free(res); }
}