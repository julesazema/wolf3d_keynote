/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** run_loader
*/

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "run.h"
#include "wolf.h"

int count_lines(FILE *file)
{
    char *line = NULL;
    size_t size = 0;
    int i;

    i = 0;
    while (getline(&line, &size, file) != -1)
        i++;
    free(line);
    return (i);
}

static char **read_file(int fd)
{
    char **result;
    FILE *as_file;
    char *line = NULL;
    size_t size = 0;
    int i;

    as_file = fdopen(fd, "r");
    result = malloc(sizeof(char *) * (count_lines(as_file) + 1));
    if (!result)
        return (NULL);
    rewind(as_file);
    line = NULL;
    size = 0;
    i = 0;
    while (getline(&line, &size, as_file) != -1) {
        result[i] = ft_strdup(line);
        i++;
    }
    result[i] = NULL;
    return (result);
}

static char *get_value(char **contents, char *key)
{
    int i;

    i = 0;
    while (contents[i]) {
        if (ft_strncmp(contents[i], key, ft_strlen(key)) == 0)
            return (&contents[i][ft_strlen(key) + 2]);
        i++;
    }
    return (NULL);
}

static int check_run_contents(char **contents)
{
    if (!get_value(contents, "nb_floors"))
        return (0);
    if (!get_value(contents, "infos"))
        return (0);
    if (!get_value(contents, "player"))
        return (0);
    return (1);
}

static void parse_room(room_t *dest, int room_val)
{
    dest->type = (room_val >> 20) & 0xF;
    dest->floor_x = extract_signed4bit((room_val >> 16) & 0xF);
    dest->floor_y = extract_signed4bit((room_val >> 12) & 0xF);
    dest->width = (room_val >> 8) & 0xF;
    dest->height = (room_val >> 4) & 0xF;
    dest->items = NULL;
    dest->collectibles = NULL;
    dest->finished = 0;
    dest->visited = 0;
    generate_room_matrix(dest);
}

static int parse_rooms(char **content, floor_t *floor)
{
    char tmp[64];
    int i;

    i = 0;
    while (i < floor->nb_rooms) {
        ft_itoad(i, tmp, 64);
        if (!content[i] ||
            ft_strncmp(content[i], tmp, ft_strlen(tmp)) != 0)
            return (0);
        floor->rooms[i].floor_id = floor->floor_id;
        floor->rooms[i].id = i;
        parse_room(&floor->rooms[i],
            ft_atoi(content[i] + ft_strlen(tmp) + 2));
        i++;
    }
    return (1);
}

static int parse_floor(char **content, run_t *dest, int floor_id)
{
    char tmp[64];
    int floor_val;
    int i = 0;

    ft_strcpy(tmp, "floor_");
    ft_itoad(floor_id, tmp + ft_strlen(tmp), 64);
    if (!get_value(content, tmp))
        return (0);
    floor_val = ft_atoi(get_value(content, tmp));
    dest->floors[floor_id].type = (floor_val >> 8) & 0xFF;
    dest->floors[floor_id].nb_rooms = (floor_val) & 0xF;
    while (content[i] && ft_strncmp(content[i], tmp, ft_strlen(tmp)) != 0)
        i++;
    if (!content[i] || !content[i + 1])
        return (0);
    return (parse_rooms(&content[i + 1], &dest->floors[floor_id]));
}

static void parse_player(int player_val)
{
    player_t *player;

    player = get_player();
    player->x = (player_val >> 20) & 0xF;
    player->y = (player_val >> 16) & 0xF;
    player->z = (player_val >> 12) & 0xF;
    player->life = (player_val >> 8) & 0xF;
    player->max_life = (player_val >> 4) & 0xF;
}

static int parse_run(run_t *dest, int fd)
{
    char **contents = read_file(fd);
    int infos;
    int i;

    if (!contents)
        return (0);
    if (!check_run_contents(contents))
        return (ft_freesplit(contents), 0);
    dest->nb_floors = ft_atoi(get_value(contents, "nb_floors"));
    i = 0;
    while (i < dest->nb_floors) {
        if (!parse_floor(contents, dest, i))
            return (ft_freesplit(contents), 0);
        i++;
    }
    infos = ft_atoi(get_value(contents, "infos"));
    dest->current_floor = (infos >> 8) & 0xF;
    dest->current_room = (infos >> 4) & 0xF;
    parse_player(ft_atoi(get_value(contents, "player")));
    return (ft_freesplit(contents), 1);
}

int load_run(void)
{
    run_t result;
    int fd;

    fd = open("run_saved.w3d", O_RDONLY);
    if (fd == -1)
        return (ft_putstr_fd(2, "Cannot open save: READ\n"), 0);
    if (!parse_run(&result, fd))
        return (0);
    set_run(&result);
    return (1);
}
