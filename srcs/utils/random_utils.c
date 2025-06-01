/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** random_utils
*/

#include <fcntl.h>
#include <unistd.h>

int get_random(int len)
{
    unsigned int num;
    int fd;

    if (len <= 0)
        return -1;
    fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0)
        return -1;
    if (read(fd, &num, sizeof(num)) != sizeof(num)) {
        close(fd);
        return -1;
    }
    close(fd);
    return (num % len);
}
