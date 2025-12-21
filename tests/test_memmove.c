#include "../header.h"

void test_memmove(int n)
{
    char b1[100];
    char b2[100];
    char s1[] = "1234567890";
    char s2[] = "1234567890";

    if (n == 151) { ft_memmove(b1, "hello", 5); memmove(b2, "hello", 5); TEST_MEM(b1, b2, 5); }
    else if (n == 152) { ft_memmove(b1, "hello", 0); memmove(b2, "hello", 0); TEST_MEM(b1, b2, 0); }
    else if (n == 153) { char *p = ft_memmove(b1, "test", 4); TEST_INT(p == b1, 1); }
    else if (n == 154) { ft_memmove(s1 + 2, s1, 5); memmove(s2 + 2, s2, 5); TEST_MEM(s1, s2, 10); }
    else if (n == 155) { ft_memmove(s1, s1 + 2, 5); memmove(s2, s2 + 2, 5); TEST_MEM(s1, s2, 10); }
    else if (n == 156) { char ov1[] = "overlap"; char ov2[] = "overlap"; ft_memmove(ov1 + 3, ov1, 4); memmove(ov2 + 3, ov2, 4); TEST_MEM(ov1, ov2, 7); }
    else if (n == 157) { ft_memmove(b1, "null\0mid", 8); memmove(b2, "null\0mid", 8); TEST_MEM(b1, b2, 8); }
    else if (n == 158) { ft_memmove(b1, s1, 10); memmove(b2, s1, 10); TEST_MEM(b1, b2, 10); }
    else if (n == 159) { ft_memmove(b1, "", 1); memmove(b2, "", 1); TEST_MEM(b1, b2, 1); }
    else if (n == 160) { int i1[3] = {1, 2, 3}; int i2[3], i3[3]; ft_memmove(i2, i1, 12); memmove(i3, i1, 12); TEST_MEM(i2, i3, 12); }
    else if (n == 161) { ft_memmove(b1, "a", 1); memmove(b2, "a", 1); TEST_MEM(b1, b2, 1); }
    else if (n == 162) { ft_memmove(b1, "ab", 2); memmove(b2, "ab", 2); TEST_MEM(b1, b2, 2); }
    else if (n == 163) { ft_memmove(b1, "abc", 3); memmove(b2, "abc", 3); TEST_MEM(b1, b2, 3); }
    else if (n == 164) { ft_memmove(b1, "abcd", 4); memmove(b2, "abcd", 4); TEST_MEM(b1, b2, 4); }
    else if (n == 165) { ft_memmove(b1, "abcde", 5); memmove(b2, "abcde", 5); TEST_MEM(b1, b2, 5); }
    else if (n == 166) { ft_memmove(b1, "abcdef", 6); memmove(b2, "abcdef", 6); TEST_MEM(b1, b2, 6); }
    else if (n == 167) { ft_memmove(b1, "abcdefg", 7); memmove(b2, "abcdefg", 7); TEST_MEM(b1, b2, 7); }
    else if (n == 168) { ft_memmove(b1, "abcdefgh", 8); memmove(b2, "abcdefgh", 8); TEST_MEM(b1, b2, 8); }
    else if (n == 169) { ft_memmove(b1, "abcdefghi", 9); memmove(b2, "abcdefghi", 9); TEST_MEM(b1, b2, 9); }
    else if (n == 170) { ft_memmove(b1, "abcdefghij", 10); memmove(b2, "abcdefghij", 10); TEST_MEM(b1, b2, 10); }
}