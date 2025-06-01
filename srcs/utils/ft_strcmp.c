/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** ft_strcmp
*/

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int ft_strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while (s1[i] && s1[i] == s2[i] && s2[i] && i < n)
        i++;
    if (i == n)
        return (0);
    return (s1[i] - s2[i]);
}
