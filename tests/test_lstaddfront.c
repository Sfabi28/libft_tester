#include "../header.h"

void test_lstadd_front(int n)
{
    t_list *lst = NULL;
    t_list *n1 = ft_lstnew("first");
    t_list *n2 = ft_lstnew("new_head");

    if (n == 541) { ft_lstadd_front(&lst, n1); TEST_INT(lst == n1, 1); free(n1); }
    else if (n == 542) { lst = n1; ft_lstadd_front(&lst, n2); TEST_INT(lst == n2, 1); free(n2); free(n1); }
    else if (n == 543) { lst = n1; ft_lstadd_front(&lst, n2); TEST_INT(lst->next == n1, 1); free(n2); free(n1); }
    else if (n == 544) { lst = n1; ft_lstadd_front(&lst, n2); TEST_STR(lst->next->content, "first"); free(n2); free(n1); }
    else if (n == 545) { ft_lstadd_front(&lst, NULL); TEST_INT(lst == NULL, 1); }
    else if (n == 546) { t_list **ptr = NULL; ft_lstadd_front(ptr, n1); TEST_INT(n1 != NULL, 1); free(n1); }
    else if (n == 547) { lst = n1; ft_lstadd_front(&lst, n2); TEST_INT(lst->next->next == NULL, 1); free(n2); free(n1); }
    else if (n == 548) { char *s = "test"; t_list *tmp = ft_lstnew(s); ft_lstadd_front(&lst, tmp); TEST_INT(lst->content == s, 1); free(tmp); }
    else if (n == 549) { lst = n1; ft_lstadd_front(&lst, n2); TEST_INT(ft_lstsize(lst), 2); free(n2); free(n1); }
    else if (n == 550) { ft_lstadd_front(&lst, n1); TEST_INT(lst->next == NULL, 1); free(n1); }
}