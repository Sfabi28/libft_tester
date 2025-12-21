#include "header.h"


void test_atoi(int n)
{
    if (n == 316) TEST_INT(ft_atoi("0"), 0);
    else if (n == 317) TEST_INT(ft_atoi("42"), 42);
    else if (n == 318) TEST_INT(ft_atoi(" -42"), -42);
    else if (n == 319) TEST_INT(ft_atoi(" +42"), 42);
    else if (n == 320) TEST_INT(ft_atoi(" \t\n\r\v\f42"), 42);
    else if (n == 321) TEST_INT(ft_atoi("2147483647"), 2147483647);
    else if (n == 322) TEST_INT(ft_atoi("-2147483648"), -2147483648);
    else if (n == 323) TEST_INT(ft_atoi("000042"), 42);
    else if (n == 324) TEST_INT(ft_atoi("42abc"), 42);
    else if (n == 325) TEST_INT(ft_atoi("abc42"), 0);
    else if (n == 326) TEST_INT(ft_atoi("++42"), 0);
    else if (n == 327) TEST_INT(ft_atoi("--42"), 0);
    else if (n == 328) TEST_INT(ft_atoi("   -00123"), -123);
    else if (n == 329) TEST_INT(ft_atoi("9999999999999"), (int)9999999999999);
    else if (n == 330) TEST_INT(ft_atoi(" - 42"), 0);
}