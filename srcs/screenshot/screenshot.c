/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** screenshot
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

#include "wolf.h"

static char *set_current_time(void)
{
    time_t l_time = time(NULL);
    struct tm *tm = localtime(&l_time);
    char *str_time = asctime(tm);
    int i = 0;

    for (i = 0; str_time[i] != '\n'; i++)
        if (str_time[i] == ' ')
            str_time[i] = '_';
    str_time[i] = '\0';
    return str_time;
}

void set_screenshot(void)
{
    sfImage *image = NULL;
    sfTexture *screen = sfTexture_create
    (get_window_width(), get_window_height());
    char *str_time = set_current_time();
    char name[128];

    play_sound("screenshot");
    mkdir("Screenshots", 0775);
    sprintf(name, "Screenshots/screenshot_%s.png", str_time);
    sfTexture_updateFromRenderWindow(screen, get_window(),
        0, 0);
    image = sfTexture_copyToImage(screen);
    sfImage_saveToFile(image, name);
    sfTexture_destroy(screen);
    sfImage_destroy(image);
}
