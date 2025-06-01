/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** environment_utils
*/

#include <string.h>
#include "wolf.h"


int is_graphical(char *envp[])
{
    int i;

    i = 0;
    while (envp[i]) {
        if (strncmp(envp[i], "DISPLAY", 7) == 0)
            return (1);
        i++;
    }
    return (0);
}
