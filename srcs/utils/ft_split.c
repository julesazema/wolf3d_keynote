/*
** EPITECH PROJECT, 2024
** minishell_1
** File description:
** ft_split
*/

#include "wolf.h"
#include <stdlib.h>

void ft_freesplit(char **split)
{
    int i;

    if (!split)
        return;
    i = 0;
    while (split[i]) {
        free(split[i]);
        i++;
    }
    free(split);
}

static int is_sep(char c, char *sep)
{
    int i;

    i = 0;
    while (sep[i] && sep[i] != c)
        i++;
    return (sep[i] == c);
}

static int count_args(char *str, char *sep)
{
    int result;
    int i;

    result = 0;
    i = 0;
    while (str[i]) {
        while (str[i] && is_sep(str[i], sep))
            i++;
        if (str[i])
            result++;
        while (str[i] && !is_sep(str[i], sep))
            i++;
    }
    return (result);
}

static int get_len_until(char *str, char *sep)
{
    int i;

    i = 0;
    while (str[i] && !is_sep(str[i], sep))
        i++;
    return (i);
}

char **ft_split(char *str, char *sep)
{
    char **result;
    int i = 0;
    int j = 0;

    if (!str)
        return (NULL);
    result = malloc(sizeof(char *) * (count_args(str, sep) + 1));
    while (str[i]) {
        while (str[i] && is_sep(str[i], sep))
            i++;
        if (!str[i])
            break;
        result[j] = malloc(sizeof(char) * (get_len_until(&str[i], sep) + 1));
        ft_strncpy(result[j], &str[i], get_len_until(&str[i], sep));
        i += get_len_until(&str[i], sep);
        j++;
    }
    result[j] = NULL;
    return (result);
}
