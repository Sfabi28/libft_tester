#include "../header.h"

void test_putchar_fd(int n)
{
    int fd = open("test_file", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char c = 0;
    if (n == 491) { ft_putchar_fd('a', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, 'a'); }
    else if (n == 492) { ft_putchar_fd('Z', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, 'Z'); }
    else if (n == 493) { ft_putchar_fd('1', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, '1'); }
    else if (n == 494) { ft_putchar_fd('\n', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, '\n'); }
    else if (n == 495) { ft_putchar_fd('\t', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, '\t'); }
    else if (n == 496) { ft_putchar_fd(' ', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, ' '); }
    else if (n == 497) { ft_putchar_fd('!', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, '!'); }
    else if (n == 498) { ft_putchar_fd('0', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, '0'); }
    else if (n == 499) { ft_putchar_fd('?', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, '?'); }
    else if (n == 500) { ft_putchar_fd('~', fd); close(fd); fd = open("test_file", O_RDONLY); read(fd, &c, 1); TEST_INT(c, '~'); }
    close(fd); unlink("test_file");
}
