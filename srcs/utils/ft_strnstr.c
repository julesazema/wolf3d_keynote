/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** ft_strchr
*/

#include "wolf.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    if (!little[0])
        return ((char *) big);
    i = 0;
    while (big[i] && i < len) {
        j = 0;
        while (big[i + j] && big[i + j] == little[j] && i + j < len)
            j++;
        if (!little[j])
            return ((char *) &big[i]);
        i++;
    }
    return (NULL);
}
