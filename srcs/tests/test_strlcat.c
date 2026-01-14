#include "../header.h"

void test_strlcat(int n)
{
    char dest[100];

    if (n == 191) { memset(dest, 0, 100); strcpy(dest, "hello"); TEST_INT(ft_strlcat(dest, " world", 15), 11); }
    else if (n == 192) { memset(dest, 0, 100); strcpy(dest, "hello"); ft_strlcat(dest, " world", 15); TEST_STR(dest, "hello world"); }
    else if (n == 193) { memset(dest, 0, 100); strcpy(dest, "hello"); TEST_INT(ft_strlcat(dest, " world", 8), 11); }
    else if (n == 194) { memset(dest, 0, 100); strcpy(dest, "hello"); ft_strlcat(dest, " world", 8); TEST_STR(dest, "hello w"); }
    else if (n == 195) { memset(dest, 0, 100); strcpy(dest, "hello"); TEST_INT(ft_strlcat(dest, " world", 3), 9); }
    else if (n == 196) { memset(dest, 0, 100); strcpy(dest, "hello"); ft_strlcat(dest, " world", 3); TEST_STR(dest, "hello"); }
    else if (n == 197) { memset(dest, 0, 100); TEST_INT(ft_strlcat(dest, "abc", 5), 3); }
    else if (n == 198) { memset(dest, 0, 100); ft_strlcat(dest, "abc", 5); TEST_STR(dest, "abc"); }
    else if (n == 199) { memset(dest, 'A', 5); dest[5] = '\0'; TEST_INT(ft_strlcat(dest, "B", 0), 1); }
    else if (n == 200) { memset(dest, 'A', 5); dest[5] = '\0'; TEST_INT(ft_strlcat(dest, "B", 2), 3); }
    else if (n == 201) { memset(dest, 0, 100); strcpy(dest, "123"); TEST_INT(ft_strlcat(dest, "456", 10), 6); }
    else if (n == 202) { memset(dest, 0, 100); strcpy(dest, "123"); TEST_INT(ft_strlcat(dest, "456", 3), 6); }
    else if (n == 203) { memset(dest, 0, 100); strcpy(dest, "123"); ft_strlcat(dest, "456", 3); TEST_STR(dest, "123"); }
    else if (n == 204) { memset(dest, 0, 100); strcpy(dest, "123"); ft_strlcat(dest, "456", 4); TEST_STR(dest, "123"); }
    else if (n == 205) { memset(dest, 0, 100); strcpy(dest, "123"); ft_strlcat(dest, "456", 5); TEST_STR(dest, "1234"); }
    else if (n == 206) { memset(dest, 0, 100); TEST_INT(ft_strlcat(dest, "", 10), 0); }
    else if (n == 207) { memset(dest, 0, 100); strcpy(dest, "A"); TEST_INT(ft_strlcat(dest, "", 10), 1); }
    else if (n == 208) { memset(dest, 0, 100); strcpy(dest, "A"); ft_strlcat(dest, "B", 10); TEST_STR(dest, "AB"); }
    else if (n == 209) { memset(dest, 0, 100); strcpy(dest, "1"); TEST_INT(ft_strlcat(dest, "2345", 2), 5); }
    else if (n == 210) { memset(dest, 0, 100); strcpy(dest, "1"); ft_strlcat(dest, "2345", 2); TEST_STR(dest, "1"); }
}