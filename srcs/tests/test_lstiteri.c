#include "../header.h"

static void iter_test_upper(void *content)
{
    char *s = (char *)content;
    if (!s) return;
    while (*s) { if (*s >= 'a' && *s <= 'z') *s -= 32; s++; }
}

void test_lstiter(int n)
{
    t_list *l1 = ft_lstnew(ft_strdup("abc"));
    t_list *l2 = ft_lstnew(ft_strdup("def"));
    l1->next = l2;

    if (n == 601) { ft_lstiter(l1, iter_test_upper); TEST_STR(l1->content, "ABC"); }
    else if (n == 602) { ft_lstiter(l1, iter_test_upper); TEST_STR(l2->content, "DEF"); }
    else if (n == 603) { ft_lstiter(NULL, iter_test_upper); TEST_INT(1, 1); }
    else if (n == 604) { ft_lstiter(l1, NULL); TEST_INT(1, 1); }
    else if (n == 605) { ft_lstiter(l2, iter_test_upper); TEST_STR(l2->content, "DEF"); }
    else if (n == 606) { ft_lstiter(l2, iter_test_upper); TEST_STR(l1->content, "abc"); }
    else if (n == 607) { t_list *tmp = ft_lstnew(ft_strdup("1a2")); ft_lstiter(tmp, iter_test_upper); TEST_STR(tmp->content, "1A2"); ft_lstdelone(tmp, free); }
    else if (n == 608) { ft_lstiter(l1, iter_test_upper); TEST_INT(l1->next == l2, 1); }
    else if (n == 609) { ft_lstiter(l1, iter_test_upper); TEST_INT(l2->next == NULL, 1); }
    else if (n == 610) { ft_lstiter(l1, iter_test_upper); TEST_INT(ft_lstsize(l1), 2); }

    ft_lstclear(&l1, free);
}