/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** clock_helper
*/

#include <stdio.h>
#include "wolf.h"

int is_clock_elapsed(char *clock_name)
{
    runnable_t *clock;
    long long elapsed;

    clock = get_clock(clock_name);
    if (!clock)
        return (0);
    elapsed = sfClock_getElapsedTime(clock->clock).microseconds;
    if ((long double) elapsed / 1000000 >= clock->time_repeat)
        sfClock_restart(clock->clock);
    return ((long double) elapsed / 1000000 >= clock->time_repeat);
}

void restart_clock(char *clock_name)
{
    runnable_t *clock;

    clock = get_clock(clock_name);
    if (!clock)
        return;
    sfClock_restart(clock->clock);
}

void change_clock_time(char *clock_name, double time)
{
    runnable_t *clock;

    clock = get_clock(clock_name);
    if (!clock)
        return;
    clock->time_repeat = time;
}
