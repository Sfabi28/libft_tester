#include "../header.h"

void test_lstnew(int n)
{
    t_list *lst;
    char *s = "42";

    if (n == 531) { lst = ft_lstnew(s); TEST_INT(lst != NULL, 1); free(lst); }
    else if (n == 532) { lst = ft_lstnew(s); TEST_INT(lst->content == s, 1); free(lst); }
    else if (n == 533) { lst = ft_lstnew(s); TEST_INT(lst->next == NULL, 1); free(lst); }
    else if (n == 534) { lst = ft_lstnew(NULL); TEST_INT(lst->content == NULL, 1); free(lst); }
    else if (n == 535) { lst = ft_lstnew(NULL); TEST_INT(lst->next == NULL, 1); free(lst); }
    else if (n == 536) { int *i = malloc(sizeof(int)); *i = 42; lst = ft_lstnew(i); TEST_INT(*(int *)(lst->content), 42); free(i); free(lst); }
    else if (n == 537) { lst = ft_lstnew("test"); TEST_STR(lst->content, "test"); free(lst); }
    else if (n == 538) { lst = ft_lstnew(""); TEST_STR(lst->content, ""); free(lst); }
    else if (n == 539) { char *ptr = "ptr"; lst = ft_lstnew(ptr); TEST_INT(lst->content == ptr, 1); free(lst); }
    else if (n == 540) { lst = ft_lstnew((void *)1); TEST_INT(lst->content == (void *)1, 1); free(lst); }
}