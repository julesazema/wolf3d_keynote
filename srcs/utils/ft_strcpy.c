/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** ft_strcpy
*/

void ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void ft_strncpy(char *dest, char *src, int n)
{
    int i;

    i = 0;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
}
