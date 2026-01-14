#include "../header.h"

void test_lstlast(int n)
{
    t_list *l1 = ft_lstnew("1");
    t_list *l2 = ft_lstnew("2");
    t_list *l3 = ft_lstnew("3");

    if (n == 561) TEST_INT(ft_lstlast(NULL) == NULL, 1);
    else if (n == 562) TEST_INT(ft_lstlast(l1) == l1, 1);
    else if (n == 563) { l1->next = l2; TEST_INT(ft_lstlast(l1) == l2, 1); }
    else if (n == 564) { l1->next = l2; l2->next = l3; TEST_INT(ft_lstlast(l1) == l3, 1); }
    else if (n == 565) { l1->next = l2; l2->next = l3; TEST_STR(ft_lstlast(l1)->content, "3"); }
    else if (n == 566) { l1->next = l2; TEST_INT(ft_lstlast(l1)->next == NULL, 1); }
    else if (n == 567) { TEST_INT(ft_lstlast(l2) == l2, 1); }
    else if (n == 568) { l2->next = l3; TEST_INT(ft_lstlast(l2) == l3, 1); }
    else if (n == 569) { t_list *tmp = ft_lstnew("tmp"); TEST_INT(ft_lstlast(tmp) == tmp, 1); free(tmp); }
    else if (n == 570) { l1->next = l3; TEST_INT(ft_lstlast(l1) == l3, 1); }

    if (l1) { l1->next = NULL; free(l1); }
    if (l2) { l2->next = NULL; free(l2); }
    if (l3) free(l3);
}