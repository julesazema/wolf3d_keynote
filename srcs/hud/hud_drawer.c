/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** hud_drawer
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Types.h>

#include "minimap.h"
#include "player.h"
#include "wolf.h"

static void draw_hearth(sfRectangleShape *shape, int index)
{
    if (index < get_player()->life / 2)
        sfRectangleShape_setTextureRect(shape,
            (sfIntRect) {0, 0, 16, 16});
    else if (index < (get_player()->life + 1) / 2)
        sfRectangleShape_setTextureRect(shape,
            (sfIntRect) {16, 0, 16, 16});
    else
        sfRectangleShape_setTextureRect(shape,
            (sfIntRect) {32, 0, 16, 16});
    sfRectangleShape_setPosition(shape,
        (sfVector2f) {120 + ((index % 6) * 34), 42 + (34 * (index / 6))});
    sfRenderWindow_drawRectangleShape(get_window(), shape, NULL);
}

static void draw_blue_hearth(sfRectangleShape *shape, int index, int jndex)
{
    if (jndex < get_player()->blue_hearth / 2)
        sfRectangleShape_setTextureRect(shape,
            (sfIntRect) {0, 16, 16, 16});
    else
        sfRectangleShape_setTextureRect(shape,
            (sfIntRect) {16, 16, 16, 16});
    sfRectangleShape_setPosition(shape,
        (sfVector2f) {120 + (((index + jndex) % 6) * 34),
            42 + (34 * ((index + jndex) / 6))});
    sfRenderWindow_drawRectangleShape(get_window(), shape, NULL);
}

static void draw_life(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    int i = 0;
    int j = 0;

    sfRectangleShape_setTexture(shape,
        get_resource("life_sheet")->data, sfTrue);
    sfRectangleShape_setSize(shape, (sfVector2f) {48, 48});
    while (i < (get_player()->max_life / 2)) {
        draw_hearth(shape, i);
        i++;
    }
    j = 0;
    while (j * 2 < (get_player()->blue_hearth)) {
        draw_blue_hearth(shape, i, j);
        j++;
    }
    sfRectangleShape_destroy(shape);
}

static void place_pickups(sfRectangleShape *shape)
{
    sfRectangleShape_setTexture(shape, get_resource("coin_hud")->data, sfTrue);
    sfRectangleShape_setSize(shape, (sfVector2f) {32, 32});
    sfRectangleShape_setPosition(shape, (sfVector2f) {24, 120});
    sfRenderWindow_drawRectangleShape(get_window(), shape, NULL);
    sfRectangleShape_setTexture(shape, get_resource("bomb_hud")->data, sfTrue);
    sfRectangleShape_setSize(shape, (sfVector2f) {32, 32});
    sfRectangleShape_setPosition(shape, (sfVector2f) {24 - 2, 120 + 32 - 4});
    sfRenderWindow_drawRectangleShape(get_window(), shape, NULL);
    sfRectangleShape_setTexture(shape, get_resource("key_hud")->data, sfTrue);
    sfRectangleShape_setSize(shape, (sfVector2f) {32, 32});
    sfRectangleShape_setPosition(shape, (sfVector2f) {24, 120 + 64});
    sfRenderWindow_drawRectangleShape(get_window(), shape, NULL);
}

static void draw_pickups(void)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    char tmp[16];

    place_pickups(shape);
    sfRectangleShape_destroy(shape);
    change_text("coins_text",
        ft_itoad(get_player()->inventory.coins, tmp, 16));
    change_text("bombs_text",
        ft_itoad(get_player()->inventory.bombs, tmp, 16));
    change_text("keys_text",
        ft_itoad(get_player()->inventory.keys, tmp, 16));
    draw_text("coins_text");
    draw_text("bombs_text");
    draw_text("keys_text");
}

void draw_hud(void)
{
    resize_sprite("vignette", get_window_width(), get_window_height());
    draw_sprite("vignette");
    draw_life();
    draw_pickups();
    draw_player_stats();
    draw_inventory();
    draw_minimap();
    draw_sprite("crosshair");
}
