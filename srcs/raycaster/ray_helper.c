/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** ray_helper
*/

#include "raycaster.h"
#include "run.h"

obstacle_type_t get_door_from_room(room_type_t type)
{
    if (type == ITEM_ROOM)
        return (O_ITEM_DOOR);
    if (type == SHOP)
        return (O_SHOP_DOOR);
    if (type == BOSS_ROOM)
        return (O_BOSS_DOOR);
    return (O_DOOR);
}

obstacle_type_t parse_obstacle_type(int x, int y)
{
    if (is_door(x, y)) {
        if (get_door_from_room(get_current_room(get_run())->type) != O_DOOR)
            return (get_door_from_room(get_current_room(get_run())->type));
        return (get_door_from_room(get_door_room(x, y)->type));
    }
    if (contains_obstacle(x, y))
        return (O_WALL);
    return (O_NONE);
}
