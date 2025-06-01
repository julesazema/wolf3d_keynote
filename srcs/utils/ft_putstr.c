/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** ft_putstr
*/

#include <unistd.h>
#include "wolf.h"

void ft_putstr_fd(int fd, char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    write(fd, str, i);
}

void ft_putnbr_fd(int fd, int nb)
{
    char c;

    if (nb < 0) {
        write(fd, "-", 1);
        nb *= -1;
    }
    if (nb == 0) {
        write(fd, "0", 1);
        return;
    }
    if (nb > 9)
        ft_putnbr_fd(fd, nb / 10);
    c = (nb % 10) + '0';
    write(fd, &c, 1);
}

void ft_putstr(char *str)
{
    ft_putstr_fd(1, str);
}
