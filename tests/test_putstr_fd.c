#include "../header.h"


void test_putstr_fd(int n)
{
    int fd = open("test_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[100]; memset(buf, 0, 100);
    if (n == 501) { ft_putstr_fd("hello", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 5); TEST_STR(buf, "hello"); }
    else if (n == 502) { ft_putstr_fd("", fd); close(fd); fd = open("test_file", O_RDONLY); TEST_INT(read(fd, buf, 1), 0); }
    else if (n == 503) { ft_putstr_fd("42 Firenze", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 10); TEST_STR(buf, "42 Firenze"); }
    else if (n == 504) { ft_putstr_fd("\t\n", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 2); TEST_STR(buf, "\t\n"); }
    else if (n == 505) { ft_putstr_fd("abc\0def", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 3); TEST_STR(buf, "abc"); }
    else if (n == 506) { ft_putstr_fd(" ", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 1); TEST_STR(buf, " "); }
    else if (n == 507) { ft_putstr_fd("long string test...", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 19); TEST_STR(buf, "long string test..."); }
    else if (n == 508) { ft_putstr_fd("!@#", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 3); TEST_STR(buf, "!@#"); }
    else if (n == 509) { ft_putstr_fd("123", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 3); TEST_STR(buf, "123"); }
    else if (n == 510) { ft_putstr_fd("last", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 4); TEST_STR(buf, "last"); }
    close(fd); unlink("test_file");
}
