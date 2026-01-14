#include "../header.h"

void test_calloc(int n)
{
    void *ptr;

    if (n == 331) { ptr = ft_calloc(10, 4); TEST_INT(ptr != NULL, 1); free(ptr); }
    else if (n == 332) { ptr = ft_calloc(10, 4); char zeros[40] = {0}; TEST_MEM(ptr, zeros, 40); free(ptr); }
    else if (n == 333) { ptr = ft_calloc(0, 10); TEST_INT(ptr != NULL, 1); free(ptr); }
    else if (n == 334) { ptr = ft_calloc(10, 0); TEST_INT(ptr != NULL, 1); free(ptr); }
    else if (n == 335) { ptr = ft_calloc(SIZE_MAX, SIZE_MAX); TEST_INT(ptr == NULL, 1); }
    else if (n == 336) { ptr = ft_calloc(1, 1); TEST_INT(ptr != NULL, 1); free(ptr); }
    else if (n == 337) { ptr = ft_calloc(5, sizeof(int)); TEST_INT(ptr != NULL, 1); free(ptr); }
    else if (n == 338) { ptr = ft_calloc(2, 2); TEST_INT(((char*)ptr)[0] == 0 && ((char*)ptr)[3] == 0, 1); free(ptr); }
    else if (n == 339) { ptr = ft_calloc(1024, 1024); TEST_INT(ptr != NULL, 1); free(ptr); }
    else if (n == 340) { ptr = ft_calloc(1, 0); TEST_INT(ptr != NULL, 1); free(ptr); }
}

