/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** ft_strlen
*/

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
