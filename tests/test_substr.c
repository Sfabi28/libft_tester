#include "header.h"

void test_substr(int n)
{
    char *s = "lorem ipsum dolor sit amet";
    char *res;

    if (n == 361) { res = ft_substr(s, 0, 10); TEST_STR(res, "lorem ipsu"); free(res); }
    else if (n == 362) { res = ft_substr(s, 6, 5); TEST_STR(res, "ipsum"); free(res); }
    else if (n == 363) { res = ft_substr(s, 12, 40); TEST_STR(res, "dolor sit amet"); free(res); }
    else if (n == 364) { res = ft_substr(s, 30, 5); TEST_STR(res, ""); free(res); }
    else if (n == 365) { res = ft_substr(s, 0, 0); TEST_STR(res, ""); free(res); }
    else if (n == 366) { res = ft_substr("test", 1, 2); TEST_STR(res, "es"); free(res); }
    else if (n == 367) { res = ft_substr("42", 0, 2); TEST_STR(res, "42"); free(res); }
    else if (n == 368) { res = ft_substr("42", 0, 1); TEST_STR(res, "4"); free(res); }
    else if (n == 369) { res = ft_substr("abc", 2, 1); TEST_STR(res, "c"); free(res); }
    else if (n == 370) { res = ft_substr("toscana", 10, 5); TEST_STR(res, ""); free(res); }
    else if (n == 371) { res = ft_substr("", 0, 5); TEST_STR(res, ""); free(res); }
    else if (n == 372) { res = ft_substr("abc", 1, 0); TEST_STR(res, ""); free(res); }
    else if (n == 373) { res = ft_substr("hola", 4, 1); TEST_STR(res, ""); free(res); }
    else if (n == 374) { res = ft_substr("lorem", 2, 3); TEST_STR(res, "rem"); free(res); }
    else if (n == 375) { res = ft_substr("lorem", 0, 42); TEST_STR(res, "lorem"); free(res); }
}
