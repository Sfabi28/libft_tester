#include "../header.h"

static void *map_test_dup(void *content) { return (ft_strdup((char *)content)); }

void test_lstmap(int n)
{
    t_list *l1 = ft_lstnew(ft_strdup("1"));
    l1->next = ft_lstnew(ft_strdup("2"));
    t_list *new_list = NULL;

    if (n == 611) { new_list = ft_lstmap(l1, map_test_dup, free); TEST_INT(new_list != NULL, 1); }
    else if (n == 612) { new_list = ft_lstmap(l1, map_test_dup, free); TEST_INT(new_list != l1, 1); }
    else if (n == 613) { new_list = ft_lstmap(l1, map_test_dup, free); TEST_STR(new_list->content, "1"); }
    else if (n == 614) { new_list = ft_lstmap(l1, map_test_dup, free); TEST_STR(new_list->next->content, "2"); }
    else if (n == 615) { new_list = ft_lstmap(NULL, map_test_dup, free); TEST_INT(new_list == NULL, 1); }
    else if (n == 616) { new_list = ft_lstmap(l1, map_test_dup, free); TEST_INT(new_list->next != l1->next, 1); }
    else if (n == 617) { new_list = ft_lstmap(l1, map_test_dup, free); TEST_INT(new_list->next->next == NULL, 1); }
    else if (n == 618) { new_list = ft_lstmap(l1, NULL, free); TEST_INT(new_list == NULL, 1); }
    else if (n == 619) { new_list = ft_lstmap(l1, map_test_dup, NULL); TEST_INT(new_list != NULL, 1); }
    else if (n == 620) { new_list = ft_lstmap(l1, map_test_dup, free); TEST_INT(ft_lstsize(new_list), 2); }

    ft_lstclear(&l1, free);
    if (new_list) ft_lstclear(&new_list, free);
}