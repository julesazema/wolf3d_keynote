/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** run_saver
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "player.h"
#include "run.h"
#include "wolf.h"

static void add_value(int fd, char *key, int value)
{
    ft_putstr_fd(fd, key);
    ft_putstr_fd(fd, ": ");
    ft_putnbr_fd(fd, value);
    ft_putstr_fd(fd, "\n");
}

static int room_to_int(room_t *room)
{
    int result = 0;

    result |= (room->type & 0xF) << 20;
    result |= (room->floor_x & 0xF) << 16;
    result |= (room->floor_y & 0xF) << 12;
    result |= (room->width & 0xF) << 8;
    result |= (room->height & 0xF) << 4;
    return (result);
}

static int floor_to_int(floor_t *floor)
{
    int result = 0;

    result |= floor->type << 8;
    result |= floor->nb_rooms;
    return (result);
}

static int infos_to_int(run_t *run)
{
    int result = 0;

    result |= (run->current_floor & 0xF) << 8;
    result |= (run->current_room & 0xF) << 4;
    return (result);
}

static int player_to_int(player_t *player)
{
    int result = 0;
    int x = (int)(player->x);
    int y = (int)(player->y);
    int z = (int)(player->z);

    result |= (x & 0xF) << 20;
    result |= (y & 0xF) << 16;
    result |= (z & 0xF) << 12;
    result |= (player->life & 0xF) << 8;
    result |= (player->max_life & 0xF) << 4;
    return (result);
}

static void write_floor(int fd, floor_t *floor)
{
    char tmp[64];
    int i;

    ft_strcpy(tmp, "floor_");
    ft_itoad(floor->floor_id, tmp + ft_strlen(tmp), 64);
    add_value(fd, tmp, floor_to_int(floor));
    i = 0;
    while (i < floor->nb_rooms) {
        add_value(fd,
            ft_itoad(floor->rooms[i].id, tmp, 64),
            room_to_int(&floor->rooms[i]));
        i++;
    }
}

static void write_save(int fd, run_t *run)
{
    int i;

    add_value(fd, "infos", infos_to_int(run));
    add_value(fd, "player", player_to_int(get_player()));
    add_value(fd, "nb_floors", run->nb_floors);
    i = 0;
    while (i < run->nb_floors) {
        write_floor(fd, &run->floors[i]);
        i++;
    }
}

void save_run(run_t *run)
{
    int fd;

    if (!run)
        return;
    fd = open("run_saved.w3d", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (!fd) {
        ft_putstr_fd(2, "Cannot open save file: READ\n");
        return;
    }
    write_save(fd, run);
    close(fd);
}
