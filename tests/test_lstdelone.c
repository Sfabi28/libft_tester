#include "../header.h"

static int g_del_count_one = 0;
static void del_test_one(void *content) { (void)content; g_del_count_one++; }

void test_lstdelone(int n)
{
    g_del_count_one = 0;
    t_list *l = ft_lstnew(ft_strdup("test"));

    if (n == 581) { ft_lstdelone(l, free); TEST_INT(1, 1); }
    else if (n == 582) { ft_lstdelone(l, del_test_one); TEST_INT(g_del_count_one, 1); }
    else if (n == 583) { ft_lstdelone(NULL, free); TEST_INT(1, 1); }
    else if (n == 584) { ft_lstdelone(l, NULL); TEST_INT(1, 1); free(l->content); free(l); }
    else if (n == 585) { t_list *tmp = ft_lstnew(0); ft_lstdelone(tmp, del_test_one); TEST_INT(g_del_count_one, 1); }
    else if (n == 586) { char *s = ft_strdup("a"); t_list *tmp = ft_lstnew(s); ft_lstdelone(tmp, free); TEST_INT(1, 1); }
    else if (n == 587) { t_list *n2 = ft_lstnew("2"); ft_lstdelone(n2, del_test_one); TEST_INT(g_del_count_one, 1); }
    else if (n == 588) { t_list *n3 = ft_lstnew("3"); ft_lstdelone(n3, del_test_one); TEST_INT(g_del_count_one, 1); }
    else if (n == 589) { t_list *n4 = ft_lstnew("4"); ft_lstdelone(n4, del_test_one); TEST_INT(g_del_count_one, 1); }
    else if (n == 590) { t_list *n5 = ft_lstnew("5"); ft_lstdelone(n5, del_test_one); TEST_INT(g_del_count_one, 1); }
}