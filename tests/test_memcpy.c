#include "../header.h"

void test_memcpy(int n)
{
    char s[] = "42 Firenze";
    char b1[100];
    char b2[100];

    if (n == 131) { ft_memcpy(b1, s, 11); memcpy(b2, s, 11); TEST_MEM(b1, b2, 11); }
    else if (n == 132) { ft_memcpy(b1, s, 0); memcpy(b2, s, 0); TEST_MEM(b1, b2, 0); }
    else if (n == 133) { ft_memcpy(b1, s, 5); memcpy(b2, s, 5); TEST_MEM(b1, b2, 5); }
    else if (n == 134) { char *p1 = ft_memcpy(b1, s, 2); TEST_INT(p1 == b1, 1); }
    else if (n == 135) { int i1[5] = {1, 2, 3, 4, 5}; int i2[5], i3[5]; ft_memcpy(i2, i1, 20); memcpy(i3, i1, 20); TEST_MEM(i2, i3, 20); }
    else if (n == 136) { ft_memcpy(b1, "hidden\0terminator", 20); memcpy(b2, "hidden\0terminator", 20); TEST_MEM(b1, b2, 20); }
    else if (n == 137) { ft_memcpy(b1, s, 1); memcpy(b2, s, 1); TEST_MEM(b1, b2, 1); }
    else if (n == 138) { ft_memcpy(b1, s, 2); memcpy(b2, s, 2); TEST_MEM(b1, b2, 2); }
    else if (n == 139) { ft_memcpy(b1, s, 3); memcpy(b2, s, 3); TEST_MEM(b1, b2, 3); }
    else if (n == 140) { ft_memcpy(b1, s, 4); memcpy(b2, s, 4); TEST_MEM(b1, b2, 4); }
    else if (n == 141) { ft_memcpy(b1, s, 6); memcpy(b2, s, 6); TEST_MEM(b1, b2, 6); }
    else if (n == 142) { ft_memcpy(b1, s, 7); memcpy(b2, s, 7); TEST_MEM(b1, b2, 7); }
    else if (n == 143) { ft_memcpy(b1, s, 8); memcpy(b2, s, 8); TEST_MEM(b1, b2, 8); }
    else if (n == 144) { ft_memcpy(b1, s, 9); memcpy(b2, s, 9); TEST_MEM(b1, b2, 9); }
    else if (n == 145) { ft_memcpy(b1, "abc", 3); memcpy(b2, "abc", 3); TEST_MEM(b1, b2, 3); }
    else if (n == 146) { ft_memcpy(b1, "def", 3); memcpy(b2, "def", 3); TEST_MEM(b1, b2, 3); }
    else if (n == 147) { ft_memcpy(b1, "ghi", 3); memcpy(b2, "ghi", 3); TEST_MEM(b1, b2, 3); }
    else if (n == 148) { ft_memcpy(b1, "jkl", 3); memcpy(b2, "jkl", 3); TEST_MEM(b1, b2, 3); }
    else if (n == 149) { ft_memcpy(b1, "mno", 3); memcpy(b2, "mno", 3); TEST_MEM(b1, b2, 3); }
    else if (n == 150) { ft_memcpy(b1, "pqr", 3); memcpy(b2, "pqr", 3); TEST_MEM(b1, b2, 3); }
}