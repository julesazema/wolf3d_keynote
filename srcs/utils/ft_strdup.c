/*
** EPITECH PROJECT, 2025
** minishell_1
** File description:
** ft_strdup
*/

#include "wolf.h"
#include <stdlib.h>

char *ft_strdup(char *src)
{
    char *result;

    result = malloc(sizeof(char) * ft_strlen(src) + 1);
    if (!result)
        return (NULL);
    ft_strcpy(result, src);
    return (result);
}

char *ft_strndup(char *src, int n)
{
    char *result;

    result = malloc(sizeof(char) * (n + 1));
    if (!result)
        return (NULL);
    ft_strncpy(result, src, n);
    return (result);
}
