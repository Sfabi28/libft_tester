#include "../header.h"

static int g_cnt_c = 0;
static void del_c(void *c) { free(c); g_cnt_c++; }

void test_lstclear(int n)
{
    g_cnt_c = 0;
    if (n == 591) { t_list *l = ft_lstnew(malloc(1)); ft_lstclear(&l, free); TEST_INT(l == NULL, 1); }
    else if (n == 592) { t_list *l = ft_lstnew(malloc(1)); ft_lstclear(&l, del_c); TEST_INT(g_cnt_c, 1); }
    else if (n == 593) { t_list *l1 = ft_lstnew(malloc(1)), *l2 = ft_lstnew(malloc(1)); l1->next = l2; ft_lstclear(&l2, del_c); TEST_INT(g_cnt_c, 1); free(l1->content); free(l1); }
    else if (n == 594) { t_list *e = NULL; ft_lstclear(&e, free); TEST_INT(e == NULL, 1); }
    else if (n == 595) { ft_lstclear(NULL, free); TEST_INT(1, 1); }
    else if (n == 596) { t_list *l1=ft_lstnew(malloc(1)), *l2=ft_lstnew(malloc(1)), *l3=ft_lstnew(malloc(1)); l1->next=l2; l2->next=l3; ft_lstclear(&l3, del_c); TEST_INT(g_cnt_c, 1); free(l1->content); free(l1); free(l2->content); free(l2); }
    else if (n == 597) { t_list *l = ft_lstnew(malloc(1)); ft_lstclear(&l, del_c); TEST_INT(l == NULL, 1); }
    else if (n == 598) { t_list *l = ft_lstnew(malloc(1)); ft_lstclear(&l, free); TEST_INT(l == NULL, 1); }
    else if (n == 599) { t_list *l1=ft_lstnew(malloc(1)), *l2=ft_lstnew(malloc(1)); l1->next=l2; l1->next=NULL; ft_lstclear(&l1, del_c); TEST_INT(g_cnt_c, 1); free(l2->content); free(l2); }
    else if (n == 600) { t_list *l1=ft_lstnew(malloc(1)), *l2=ft_lstnew(malloc(1)); l1->next=l2; ft_lstclear(&l1, del_c); TEST_INT(g_cnt_c, 2); }
}