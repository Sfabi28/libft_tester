#include "header.h"

void test_bzero(int n)
{
    char b1[100];
    char b2[100];

    if (n == 116) { ft_bzero(b1, 10); bzero(b2, 10); TEST_MEM(b1, b2, 10); }
    else if (n == 117) { ft_bzero(b1, 0); bzero(b2, 0); TEST_MEM(b1, b2, 0); }
    else if (n == 118) { ft_bzero(b1, 100); bzero(b2, 100); TEST_MEM(b1, b2, 100); }
    else if (n == 119) { memset(b1, 'A', 50); memset(b2, 'A', 50); ft_bzero(b1, 25); bzero(b2, 25); TEST_MEM(b1, b2, 50); }
    else if (n == 120) { ft_bzero(b1, 1); bzero(b2, 1); TEST_MEM(b1, b2, 1); }
    else if (n == 121) { ft_bzero(b1, 2); bzero(b2, 2); TEST_MEM(b1, b2, 2); }
    else if (n == 122) { ft_bzero(b1, 3); bzero(b2, 3); TEST_MEM(b1, b2, 3); }
    else if (n == 123) { ft_bzero(b1, 4); bzero(b2, 4); TEST_MEM(b1, b2, 4); }
    else if (n == 124) { ft_bzero(b1, 5); bzero(b2, 5); TEST_MEM(b1, b2, 5); }
    else if (n == 125) { ft_bzero(b1, 6); bzero(b2, 6); TEST_MEM(b1, b2, 6); }
    else if (n == 126) { ft_bzero(b1, 7); bzero(b2, 7); TEST_MEM(b1, b2, 7); }
    else if (n == 127) { ft_bzero(b1, 8); bzero(b2, 8); TEST_MEM(b1, b2, 8); }
    else if (n == 128) { ft_bzero(b1, 9); bzero(b2, 9); TEST_MEM(b1, b2, 9); }
    else if (n == 129) { ft_bzero(b1, 11); bzero(b2, 11); TEST_MEM(b1, b2, 11); }
    else if (n == 130) { ft_bzero(b1, 12); bzero(b2, 12); TEST_MEM(b1, b2, 12); }
}