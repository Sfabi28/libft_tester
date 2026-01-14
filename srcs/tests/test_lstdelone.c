#include "../header.h"

static int g_cnt = 0;
static void del_t(void *c) { free(c); g_cnt++; }

void test_lstdelone(int n)
{
    g_cnt = 0;
    if (n == 581) { t_list *l = ft_lstnew(malloc(1)); ft_lstdelone(l, free); TEST_INT(1, 1); }
    else if (n == 582) { t_list *l = ft_lstnew(malloc(1)); ft_lstdelone(l, del_t); TEST_INT(g_cnt, 1); }
    else if (n == 583) { ft_lstdelone(NULL, free); TEST_INT(1, 1); }
    else if (n == 584) { t_list *l = ft_lstnew(malloc(1)); ft_lstdelone(l, NULL); TEST_INT(1, 1); free(l->content); free(l); }
    else if (n == 585) { t_list *l = ft_lstnew(malloc(1)); ft_lstdelone(l, del_t); TEST_INT(g_cnt, 1); }
    else if (n == 586) { t_list *l = ft_lstnew(malloc(1)); ft_lstdelone(l, free); TEST_INT(1, 1); }
    else if (n == 587) { t_list *l = ft_lstnew(malloc(1)); ft_lstdelone(l, del_t); TEST_INT(g_cnt, 1); }
    else if (n == 588) { t_list *l = ft_lstnew(malloc(1)); ft_lstdelone(l, del_t); TEST_INT(g_cnt, 1); }
    else if (n == 589) { t_list *l = ft_lstnew(malloc(1)); ft_lstdelone(l, del_t); TEST_INT(g_cnt, 1); }
    else if (n == 590) { t_list *l = ft_lstnew(malloc(1)); ft_lstdelone(l, del_t); TEST_INT(g_cnt, 1); }
}