#include "../header.h"

void test_lstadd_back(int n)
{
    t_list *lst = NULL;

    if (n == 571) { t_list *n1 = ft_lstnew("head"); ft_lstadd_back(&lst, n1); TEST_INT(lst == n1, 1); free(n1); }
    else if (n == 572) { t_list *n1 = ft_lstnew("head"), *n2 = ft_lstnew("tail"); lst = n1; ft_lstadd_back(&lst, n2); TEST_INT(lst->next == n2, 1); free(n1); free(n2); }
    else if (n == 573) { t_list *n1 = ft_lstnew("head"), *n2 = ft_lstnew("tail"); lst = n1; ft_lstadd_back(&lst, n2); TEST_INT(n2->next == NULL, 1); free(n1); free(n2); }
    else if (n == 574) { t_list *n1 = ft_lstnew("head"), *n2 = ft_lstnew("tail"); lst = n1; ft_lstadd_back(&lst, n2); TEST_STR(lst->next->content, "tail"); free(n1); free(n2); }
    else if (n == 575) { t_list *n1 = ft_lstnew("1"), *n2 = ft_lstnew("3"), *n3 = ft_lstnew("2"); lst = n1; n1->next = n3; ft_lstadd_back(&lst, n2); TEST_INT(n3->next == n2, 1); free(n1); free(n3); free(n2); }
    else if (n == 576) { ft_lstadd_back(&lst, NULL); TEST_INT(lst == NULL, 1); }
    else if (n == 577) { t_list *n1 = ft_lstnew("head"), *n2 = ft_lstnew("tail"); lst = n1; ft_lstadd_back(&lst, n2); TEST_INT(ft_lstsize(lst), 2); free(n1); free(n2); }
    else if (n == 578) { char *s = "back"; t_list *tmp = ft_lstnew(s); ft_lstadd_back(&lst, tmp); TEST_STR(ft_lstlast(lst)->content, "back"); free(tmp); }
    else if (n == 579) { t_list *n1 = ft_lstnew("head"); ft_lstadd_back(NULL, n1); TEST_INT(n1 != NULL, 1); free(n1); }
    else if (n == 580) { t_list *n1 = ft_lstnew("head"), *n2 = ft_lstnew("tail"); lst = n1; ft_lstadd_back(&lst, n2); TEST_INT(lst == n1, 1); free(n1); free(n2); }
}