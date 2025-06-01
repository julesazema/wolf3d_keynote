/*
** EPITECH PROJECT, 2025
** minishell_1
** File description:
** ft_atoi
*/

#include "wolf.h"

int ft_atoi(char *str)
{
    int result;
    int multiplier;
    int i;

    multiplier = 1;
    result = 0;
    i = 0;
    while (str[i] && (str[i] == '-' || str[i] == '+')) {
        multiplier *= -1;
        i++;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * multiplier);
}
