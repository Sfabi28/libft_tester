#include "header.h"

char mapi_test_func(unsigned int i, char c) { (void)i; return (c + 1); }
char mapi_test_func_idx(unsigned int i, char c) { return (c + i); }

void test_strmapi(int n)
{
    char *res;

    if (n == 451) { res = ft_strmapi("abc", mapi_test_func); TEST_STR(res, "bcd"); free(res); }
    else if (n == 452) { res = ft_strmapi("123", mapi_test_func); TEST_STR(res, "234"); free(res); }
    else if (n == 453) { res = ft_strmapi("abc", mapi_test_func_idx); TEST_STR(res, "ace"); free(res); }
    else if (n == 454) { res = ft_strmapi("", mapi_test_func); TEST_STR(res, ""); free(res); }
    else if (n == 455) { res = ft_strmapi("hello", mapi_test_func); TEST_STR(res, "ifmmp"); free(res); }
    else if (n == 456) { res = ft_strmapi("42", mapi_test_func); TEST_STR(res, "53"); free(res); }
    else if (n == 457) { res = ft_strmapi("ABC", mapi_test_func); TEST_STR(res, "BCD"); free(res); }
    else if (n == 458) { res = ft_strmapi("a", mapi_test_func_idx); TEST_STR(res, "a"); free(res); }
    else if (n == 459) { res = ft_strmapi("ab", mapi_test_func_idx); TEST_STR(res, "ac"); free(res); }
    else if (n == 460) { res = ft_strmapi("test", mapi_test_func); TEST_INT(strlen(res), 4); free(res); }
    else if (n == 461) { res = ft_strmapi("z", mapi_test_func); TEST_STR(res, "{"); free(res); }
    else if (n == 462) { res = ft_strmapi("!!!", mapi_test_func); TEST_STR(res, "\"\"\""); free(res); }
    else if (n == 463) { res = ft_strmapi("000", mapi_test_func_idx); TEST_STR(res, "012"); free(res); }
    else if (n == 464) { res = ft_strmapi("AAAA", mapi_test_func_idx); TEST_STR(res, "ABCD"); free(res); }
    else if (n == 465) { res = ft_strmapi(" ", mapi_test_func); TEST_STR(res, "!"); free(res); }
    else if (n >= 466 && n <= 470) { res = ft_strmapi("ok", mapi_test_func); TEST_STR(res, "pl"); free(res); }
}