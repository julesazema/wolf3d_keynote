/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** run_launcher
*/

#include <stdio.h>

#include "actionbar.h"
#include "player.h"
#include "raycaster.h"
#include "run.h"
#include "stats.h"
#include "wolf.h"

static void update_textures(room_type_t type)
{
    if (type == SACRIFICE_ROOM) {
        get_ray()->texture_wall = get_resource("wall_texture_sacrifice")->data;
        get_ray()->texture_floor =
            get_resource("floor_texture_sacrifice")->data;
        get_ray()->texture_door = get_resource("door_texture_sacrifice")->data;
    } else if (type == ITEM_ROOM) {
        get_ray()->texture_door = get_resource("door_texture_item")->data;
    } else {
        get_ray()->texture_wall = get_resource("wall_texture")->data;
        get_ray()->texture_floor = get_resource("floor_texture")->data;
        get_ray()->texture_door = get_resource("door_texture")->data;
    }
    sfImage_destroy((sfImage *) get_ray()->floor_image);
    get_ray()->floor_image = sfTexture_copyToImage(get_ray()->texture_floor);
    get_ray()->floor_pixels_ptr = sfImage_getPixelsPtr(get_ray()->floor_image);
}

void launch_room(int room_index)
{
    room_t *room;
    room_t *old_room;
    double *new_x = &get_player()->x;
    double *new_y = &get_player()->y;

    room = &get_run()->floors[get_run()->current_floor].rooms[room_index];
    old_room = get_current_room(get_run());
    if (room->type == BOSS_ROOM && !room->visited)
        play_sound("castleportcullis");
    *new_x = (double) room->width / 2 * TILE_SIZE;
    *new_y = (double) room->height / 2 * TILE_SIZE;
    if (room_index != old_room->id) {
        if (old_room->floor_x != room->floor_x)
            *new_x *= old_room->floor_x > room->floor_x ? 2 : 0;
        if (old_room->floor_y != room->floor_y)
            *new_y *= old_room->floor_y > room->floor_y ? 2 : 0;
    }
    get_run()->current_room = room_index;
    room->visited = 1;
    update_textures(room->type);
}

void launch_floor(int floor_index)
{
    get_run()->current_floor = floor_index;
    if (get_run()->nb_floors <= 0)
        return (ft_putstr_fd(2, "no_floors_defined: Cannot launch player"));
    display_action("BASEMENT I", 1.5);
    launch_room(0);
}

void launch_run(void)
{
    add_stat(NB_GAME);
    generate_run();
    launch_floor(0);
}
