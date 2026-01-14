#include "../header.h"

static void ft_free_split(char **split)
{
    int i = 0;
    if (!split) return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void test_split(int n)
{
    char **res;

    if (n == 406) { res = ft_split("hello world", ' '); TEST_STR(res[0], "hello"); TEST_STR(res[1], "world"); TEST_INT(res[2] == NULL, 1); ft_free_split(res); }
    else if (n == 407) { res = ft_split("   hello   world   ", ' '); TEST_STR(res[0], "hello"); TEST_STR(res[1], "world"); TEST_INT(res[2] == NULL, 1); ft_free_split(res); }
    else if (n == 408) { res = ft_split("split", ' '); TEST_STR(res[0], "split"); TEST_INT(res[1] == NULL, 1); ft_free_split(res); }
    else if (n == 409) { res = ft_split("", ' '); TEST_INT(res[0] == NULL, 1); ft_free_split(res); }
    else if (n == 410) { res = ft_split("   ", ' '); TEST_INT(res[0] == NULL, 1); ft_free_split(res); }
    else if (n == 411) { res = ft_split("a,b,c,d", ','); TEST_STR(res[3], "d"); ft_free_split(res); }
    else if (n == 412) { res = ft_split("lorem ipsum dolor sit amet", ' '); TEST_INT(res[5] == NULL, 1); ft_free_split(res); }
    else if (n == 413) { res = ft_split("xxxxxxxxhello", 'x'); TEST_STR(res[0], "hello"); ft_free_split(res); }
    else if (n == 414) { res = ft_split("helloxxxxxxx", 'x'); TEST_STR(res[0], "hello"); TEST_INT(res[1] == NULL, 1); ft_free_split(res); }
    else if (n == 415) { res = ft_split("--1--2--3--4--5--", '-'); TEST_STR(res[4], "5"); ft_free_split(res); }
    else if (n == 416) { res = ft_split("0 0 0 0", ' '); TEST_STR(res[0], "0"); ft_free_split(res); }
    else if (n == 417) { res = ft_split("hello", '\0'); TEST_STR(res[0], "hello"); TEST_INT(res[1] == NULL, 1); ft_free_split(res); }
    else if (n == 418) { res = ft_split("     ", ' '); TEST_INT(res[0] == NULL, 1); ft_free_split(res); }
    else if (n == 419) { res = ft_split("word", 'w'); TEST_STR(res[0], "ord"); ft_free_split(res); }
    else if (n == 420) { res = ft_split("word", 'd'); TEST_STR(res[0], "wor"); ft_free_split(res); }
    else if (n == 421) { res = ft_split("      split       test  ", ' '); TEST_STR(res[1], "test"); ft_free_split(res); }
    else if (n == 422) { res = ft_split("1-2-3", '-'); TEST_STR(res[1], "2"); ft_free_split(res); }
    else if (n == 423) { res = ft_split("z", 'z'); TEST_INT(res[0] == NULL, 1); ft_free_split(res); }
    else if (n == 424) { res = ft_split("abz", 'z'); TEST_STR(res[0], "ab"); ft_free_split(res); }
    else if (n == 425) { res = ft_split("zab", 'z'); TEST_STR(res[0], "ab"); ft_free_split(res); }
    else if (n == 426) { res = ft_split("  a  b  c  ", ' '); TEST_INT(res[3] == NULL, 1); ft_free_split(res); }
    else if (n == 427) { res = ft_split("a b c d e f", ' '); TEST_STR(res[5], "f"); ft_free_split(res); }
    else if (n == 428) { res = ft_split("---a---b---", '-'); TEST_STR(res[1], "b"); ft_free_split(res); }
    else if (n == 429) { res = ft_split("hello world", 'z'); TEST_STR(res[0], "hello world"); ft_free_split(res); }
    else if (n == 430) { res = ft_split("! ! !", ' '); TEST_STR(res[2], "!"); ft_free_split(res); }
}