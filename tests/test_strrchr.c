#include "header.h"

void test_strrchr(int n)
{
    char s[] = "42 Firenze";
    if (n == 241) TEST_INT(ft_strrchr(s, 'F') == s + 3, 1);
    else if (n == 242) TEST_INT(ft_strrchr(s, 'e') == s + 9, 1);
    else if (n == 243) TEST_INT(ft_strrchr(s, '4') == s, 1);
    else if (n == 244) TEST_INT(ft_strrchr(s, 'x') == NULL, 1);
    else if (n == 245) TEST_INT(ft_strrchr(s, '\0') == s + 10, 1);
    else if (n == 246) TEST_INT(ft_strrchr("bonjour", 'o') == "bonjour" + 4, 1);
    else if (n == 247) TEST_INT(ft_strrchr("aaa", 'a') == "aaa" + 2, 1);
    else if (n == 248) TEST_INT(ft_strrchr("", 'z') == NULL, 1);
    else if (n == 249) { char s3[] = "abbbc"; TEST_INT(ft_strrchr(s3, 'b') == s3 + 3, 1); }
    else if (n == 250) TEST_INT(ft_strrchr("12321", '2') == "12321" + 3, 1);
}