/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** file_utils
*/

#include "wolf.h"
#include <fcntl.h>
#include <unistd.h>

int exists_file(char *file_path)
{
    int fd;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return (0);
    close(fd);
    return (1);
}
