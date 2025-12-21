#include "../header.h"


void test_putendl_fd(int n)
{
    int fd = open("test_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[100]; memset(buf, 0, 100);
    if (n == 511) { ft_putendl_fd("hello", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 6); TEST_STR(buf, "hello\n"); }
    else if (n == 512) { ft_putendl_fd("", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 1); TEST_STR(buf, "\n"); }
    else if (n == 513) { ft_putendl_fd("42", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 3); TEST_STR(buf, "42\n"); }
    else if (n == 514) { ft_putendl_fd(" ", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 2); TEST_STR(buf, " \n"); }
    else if (n == 515) { ft_putendl_fd("abc", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 4); TEST_STR(buf, "abc\n"); }
    else if (n == 516) { ft_putendl_fd("123", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 4); TEST_STR(buf, "123\n"); }
    else if (n == 517) { ft_putendl_fd("test", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 5); TEST_STR(buf, "test\n"); }
    else if (n == 518) { ft_putendl_fd("ok", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 3); TEST_STR(buf, "ok\n"); }
    else if (n == 519) { ft_putendl_fd("!", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 2); TEST_STR(buf, "!\n"); }
    else if (n == 520) { ft_putendl_fd("end", fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 4); TEST_STR(buf, "end\n"); }
    close(fd); unlink("test_file");
}
