/*
** EPITECH PROJECT, 2025
** secured
** File description:
** ft_itoa
*/

#include <malloc.h>

static int ft_nblen(int nb)
{
    int i;

    if (nb == 0)
        return (1);
    i = 0;
    if (nb < 0)
        i++;
    while (nb != 0) {
        i++;
        nb = nb / 10;
    }
    return (i);
}

char *ft_itoa(int nb)
{
    char *result;
    int i;

    result = malloc(sizeof(char) * (ft_nblen(nb) + 1));
    if (!result)
        return (NULL);
    if (nb < 0)
        result[0] = '-';
    i = ft_nblen(nb);
    result[i] = 0;
    if (nb == 0)
        result[0] = '0';
    while (nb != 0) {
        result[i - 1] = nb % 10 + '0';
        nb = nb / 10;
        i--;
    }
    return (result);
}

char *ft_itoad(int nb, char *buffer, int buffer_size)
{
    int i;

    i = ft_nblen(nb);
    if (buffer_size <= i)
        return (NULL);
    if (nb < 0)
        buffer[0] = '-';
    buffer[i] = 0;
    if (nb == 0)
        buffer[0] = '0';
    while (nb != 0) {
        buffer[i - 1] = nb % 10 + '0';
        nb = nb / 10;
        i--;
    }
    return (buffer);
}
