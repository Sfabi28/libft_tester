#include "header.h"

void test_strlcpy(int n)
{
    char dest[100];
    memset(dest, 'A', 20);
    dest[20] = '\0';

    if (n == 171) TEST_INT(ft_strlcpy(dest, "hello", 10), 5);
    else if (n == 172) { ft_strlcpy(dest, "hello", 10); TEST_STR(dest, "hello"); }
    else if (n == 173) TEST_INT(ft_strlcpy(dest, "hello", 3), 5);
    else if (n == 174) { ft_strlcpy(dest, "hello", 3); TEST_STR(dest, "he"); }
    else if (n == 175) TEST_INT(ft_strlcpy(dest, "hello", 0), 5);
    else if (n == 176) { memset(dest, 'A', 5); dest[5] = '\0'; ft_strlcpy(dest, "hello", 0); TEST_STR(dest, "AAAAA"); }
    else if (n == 177) TEST_INT(ft_strlcpy(dest, "", 10), 0);
    else if (n == 178) { ft_strlcpy(dest, "", 10); TEST_STR(dest, ""); }
    else if (n == 179) TEST_INT(ft_strlcpy(dest, "12345", 5), 5);
    else if (n == 180) { ft_strlcpy(dest, "12345", 5); TEST_STR(dest, "1234"); }
    else if (n == 181) TEST_INT(ft_strlcpy(dest, "abc", 1), 3);
    else if (n == 182) { ft_strlcpy(dest, "abc", 1); TEST_STR(dest, ""); }
    else if (n == 183) TEST_INT(ft_strlcpy(dest, "toscana", 100), 7);
    else if (n == 184) { ft_strlcpy(dest, "toscana", 100); TEST_STR(dest, "toscana"); }
    else if (n == 185) TEST_INT(ft_strlcpy(dest, "copy", 2), 4);
    else if (n == 186) TEST_INT(ft_strlcpy(dest, "42", 2), 2);
    else if (n == 187) { ft_strlcpy(dest, "42", 2); TEST_STR(dest, "4"); }
    else if (n == 188) TEST_INT(ft_strlcpy(dest, "long string", 5), 11);
    else if (n == 189) { ft_strlcpy(dest, "long string", 5); TEST_STR(dest, "long"); }
    else if (n == 190) TEST_INT(ft_strlcpy(dest, "a", 10), 1);
}