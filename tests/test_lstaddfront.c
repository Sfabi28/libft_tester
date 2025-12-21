#include "../header.h"

void test_lstadd_front(int n)
{
    t_list *lst = NULL;

    if (n == 541) { t_list *n1 = ft_lstnew("first"); ft_lstadd_front(&lst, n1); TEST_INT(lst == n1, 1); free(n1); }
    else if (n == 542) { t_list *n1 = ft_lstnew("1"), *n2 = ft_lstnew("2"); lst = n1; ft_lstadd_front(&lst, n2); TEST_INT(lst == n2, 1); free(n2); free(n1); }
    else if (n == 543) { t_list *n1 = ft_lstnew("1"), *n2 = ft_lstnew("2"); lst = n1; ft_lstadd_front(&lst, n2); TEST_INT(lst->next == n1, 1); free(n2); free(n1); }
    else if (n == 544) { t_list *n1 = ft_lstnew("1"), *n2 = ft_lstnew("2"); lst = n1; ft_lstadd_front(&lst, n2); TEST_STR(lst->next->content, "1"); free(n2); free(n1); }
    else if (n == 545) { ft_lstadd_front(&lst, NULL); TEST_INT(lst == NULL, 1); }
    else if (n == 546) { t_list *n1 = ft_lstnew("1"); ft_lstadd_front(NULL, n1); TEST_INT(n1->next == NULL, 1); free(n1); }
    else if (n == 547) { t_list *n1 = ft_lstnew("1"), *n2 = ft_lstnew("2"); lst = n1; ft_lstadd_front(&lst, n2); TEST_INT(lst->next->next == NULL, 1); free(n2); free(n1); }
    else if (n == 548) { char *s = "t"; t_list *t = ft_lstnew(s); ft_lstadd_front(&lst, t); TEST_INT(lst->content == s, 1); free(t); }
    else if (n == 549) { t_list *n1 = ft_lstnew("1"), *n2 = ft_lstnew("2"); lst = n1; ft_lstadd_front(&lst, n2); TEST_INT(ft_lstsize(lst), 2); free(n2); free(n1); }
    else if (n == 550) { t_list *n1 = ft_lstnew("1"); ft_lstadd_front(&lst, n1); TEST_INT(lst->next == NULL, 1); free(n1); }
}