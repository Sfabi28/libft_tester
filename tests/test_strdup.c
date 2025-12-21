#include "header.h"

void test_strdup(int n)
{
    char *s;

    if (n == 341) { s = ft_strdup("hello"); TEST_STR(s, "hello"); free(s); }
    else if (n == 342) { s = ft_strdup(""); TEST_STR(s, ""); free(s); }
    else if (n == 343) { char *str = "42"; s = ft_strdup(str); TEST_INT(s != str, 1); free(s); }
    else if (n == 344) { s = ft_strdup("toscana"); TEST_INT(strlen(s), 7); free(s); }
    else if (n == 345) { s = ft_strdup("special\nchars\t"); TEST_STR(s, "special\nchars\t"); free(s); }
    else if (n == 346) { s = ft_strdup(" "); TEST_STR(s, " "); free(s); }
    else if (n == 347) { s = ft_strdup("1234567890"); TEST_STR(s, "1234567890"); free(s); }
    else if (n == 348) { s = ft_strdup("a"); TEST_STR(s, "a"); free(s); }
    else if (n == 349) { s = ft_strdup("longer string for testing heap allocation"); TEST_INT(s != NULL, 1); free(s); }
    else if (n == 350) { s = ft_strdup("!@#$%^&*()"); TEST_STR(s, "!@#$%^&*()"); free(s); }
    else if (n == 351) { s = ft_strdup("duplicate"); TEST_INT(strcmp(s, "duplicate"), 0); free(s); }
    else if (n == 352) { s = ft_strdup("abc\0def"); TEST_STR(s, "abc"); free(s); }
    else if (n == 353) { char src[5] = "test"; s = ft_strdup(src); TEST_INT(s[4], '\0'); free(s); }
    else if (n == 354) { s = ft_strdup("stack to heap"); TEST_INT(s != NULL, 1); free(s); }
    else if (n == 355) { s = ft_strdup("0"); TEST_STR(s, "0"); free(s); }
    else if (n == 356) { s = ft_strdup("multiple words test"); TEST_STR(s, "multiple words test"); free(s); }
    else if (n == 357) { s = ft_strdup("...///..."); TEST_STR(s, "...///..."); free(s); }
    else if (n == 358) { s = ft_strdup("42"); TEST_STR(s, "42"); free(s); }
    else if (n == 359) { s = ft_strdup("final"); TEST_INT(s != NULL, 1); free(s); }
    else if (n == 360) { s = ft_strdup("last test"); TEST_STR(s, "last test"); free(s); }
}