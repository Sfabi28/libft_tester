#include "../header.h"

void test_putnbr_fd(int n)
{
    int fd = open("test_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[100]; memset(buf, 0, 100);
    if (n == 521) { ft_putnbr_fd(0, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 1); TEST_STR(buf, "0"); }
    else if (n == 522) { ft_putnbr_fd(42, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 2); TEST_STR(buf, "42"); }
    else if (n == 523) { ft_putnbr_fd(-42, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 3); TEST_STR(buf, "-42"); }
    else if (n == 524) { ft_putnbr_fd(2147483647, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 10); TEST_STR(buf, "2147483647"); }
    else if (n == 525) { ft_putnbr_fd(-2147483648, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 11); TEST_STR(buf, "-2147483648"); }
    else if (n == 526) { ft_putnbr_fd(100, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 3); TEST_STR(buf, "100"); }
    else if (n == 527) { ft_putnbr_fd(-1, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 2); TEST_STR(buf, "-1"); }
    else if (n == 528) { ft_putnbr_fd(9, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 1); TEST_STR(buf, "9"); }
    else if (n == 529) { ft_putnbr_fd(-2147483647, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 11); TEST_STR(buf, "-2147483647"); }
    else if (n == 530) { ft_putnbr_fd(123456, fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, buf, 6); TEST_STR(buf, "123456"); }
    close(fd); unlink("test_file");
}