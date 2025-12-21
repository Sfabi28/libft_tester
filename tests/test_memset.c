#include "header.h"

void test_memset(int n)
{
    char b1[100];
    char b2[100];

    if (n == 91) { ft_memset(b1, 'A', 10); memset(b2, 'A', 10); TEST_MEM(b1, b2, 10); }
    else if (n == 92) { ft_memset(b1, 'B', 0); memset(b2, 'B', 0); TEST_MEM(b1, b2, 0); }
    else if (n == 93) { ft_memset(b1, 0, 50); memset(b2, 0, 50); TEST_MEM(b1, b2, 50); }
    else if (n == 94) { ft_memset(b1, 255, 20); memset(b2, 255, 20); TEST_MEM(b1, b2, 20); }
    else if (n == 95) { ft_memset(b1, '1', 1); memset(b2, '1', 1); TEST_MEM(b1, b2, 1); }
    else if (n == 96) { ft_memset(b1, -1, 10); memset(b2, -1, 10); TEST_MEM(b1, b2, 10); }
    else if (n == 97) { ft_memset(b1, '*', 100); memset(b2, '*', 100); TEST_MEM(b1, b2, 100); }
    else if (n == 98) { char *p1 = ft_memset(b1, 'C', 5); TEST_INT(p1 == b1, 1); }
    else if (n == 99) { ft_memset(b1, 'D', 10); memset(b2, 'D', 10); TEST_MEM(b1, b2, 10); }
    else if (n == 100) { ft_memset(b1, 127, 10); memset(b2, 127, 10); TEST_MEM(b1, b2, 10); }
    else if (n == 101) { ft_memset(b1, 'x', 5); memset(b2, 'x', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 102) { ft_memset(b1, 'y', 5); memset(b2, 'y', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 103) { ft_memset(b1, 'z', 5); memset(b2, 'z', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 104) { ft_memset(b1, '0', 5); memset(b2, '0', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 105) { ft_memset(b1, '1', 5); memset(b2, '1', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 106) { ft_memset(b1, '2', 5); memset(b2, '2', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 107) { ft_memset(b1, '3', 5); memset(b2, '3', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 108) { ft_memset(b1, '4', 5); memset(b2, '4', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 109) { ft_memset(b1, '5', 5); memset(b2, '5', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 110) { ft_memset(b1, '6', 5); memset(b2, '6', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 111) { ft_memset(b1, '7', 5); memset(b2, '7', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 112) { ft_memset(b1, '8', 5); memset(b2, '8', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 113) { ft_memset(b1, '9', 5); memset(b2, '9', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 114) { ft_memset(b1, 'a', 5); memset(b2, 'a', 5); TEST_MEM(b1, b2, 5); }
    else if (n == 115) { ft_memset(b1, 'b', 5); memset(b2, 'b', 5); TEST_MEM(b1, b2, 5); }
}