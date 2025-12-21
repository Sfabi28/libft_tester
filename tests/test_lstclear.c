#include "../header.h"

static int g_del_count_clear = 0;
static void del_test_clear(void *content) { (void)content; g_del_count_clear++; }

void test_lstclear(int n)
{
    g_del_count_clear = 0;
    t_list *l1 = ft_lstnew(ft_strdup("1"));
    t_list *l2 = ft_lstnew(ft_strdup("2"));
    t_list *l3 = ft_lstnew(ft_strdup("3"));
    l1->next = l2; l2->next = l3;

    if (n == 591) { ft_lstclear(&l1, free); TEST_INT(l1 == NULL, 1); }
    else if (n == 592) { ft_lstclear(&l1, del_test_clear); TEST_INT(g_del_count_clear, 3); }
    else if (n == 593) { ft_lstclear(&l2, del_test_clear); TEST_INT(g_del_count_clear, 2); free(l1->content); free(l1); }
    else if (n == 594) { t_list *empty = NULL; ft_lstclear(&empty, free); TEST_INT(empty == NULL, 1); }
    else if (n == 595) { ft_lstclear(NULL, free); TEST_INT(1, 1); }
    else if (n == 596) { ft_lstclear(&l3, del_test_clear); TEST_INT(g_del_count_clear, 1); free(l1->content); free(l1); free(l2->content); free(l2); }
    else if (n == 597) { ft_lstclear(&l1, del_test_clear); TEST_INT(l1 == NULL, 1); }
    else if (n == 598) { t_list *single = ft_lstnew(ft_strdup("s")); ft_lstclear(&single, free); TEST_INT(single == NULL, 1); }
    else if (n == 599) { l1->next = NULL; ft_lstclear(&l1, del_test_clear); TEST_INT(g_del_count_clear, 1); free(l2->content); free(l2); free(l3->content); free(l3); }
    else if (n == 600) { ft_lstclear(&l1, del_test_clear); TEST_INT(g_del_count_clear, 3); }
}