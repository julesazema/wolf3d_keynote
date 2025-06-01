/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** hud_initializer
*/

#include "wolf.h"

static void init_sprite_stats(void)
{
    load_resource("speed", "assets/stats/speed.png", TEXTURE);
    create_sprite("speed", 0, 260, "speed");
    scale_sprite("speed", 0.1f);
    load_resource("shoot_speed", "assets/stats/shoot_speed.png", TEXTURE);
    create_sprite("shoot_speed", 0, 300, "shoot_speed");
    scale_sprite("shoot_speed", 0.1f);
    load_resource("dammage", "assets/stats/dammage.png", TEXTURE);
    create_sprite("dammage", 0, 340, "dammage");
    scale_sprite("dammage", 0.1f);
    load_resource("range", "assets/stats/range.png", TEXTURE);
    create_sprite("range", 0, 380, "range");
    scale_sprite("range", 0.1f);
    load_resource("ball_speed", "assets/stats/ball_speed.png", TEXTURE);
    create_sprite("ball_speed", 0, 420, "ball_speed");
    scale_sprite("ball_speed", 0.1f);
    load_resource("luck", "assets/stats/luck.png", TEXTURE);
    create_sprite("luck", 0, 460, "luck");
    scale_sprite("luck", 0.1f);
}

static void text_loader_stats(char *text_name, int x, int y)
{
    create_text(text_name, "0.00", "font");
    center_text(text_name, x, y);
    colorize_text(text_name, sfColor_fromRGB(160, 160, 160));
    sfText_setScale(get_text(text_name)->text, (sfVector2f) {0.7f, 1.0f});
}

static void load_hud_stats(void)
{
    init_sprite_stats();
    text_loader_stats("speed", 90, 260);
    text_loader_stats("shoot_speed", 90, 300);
    text_loader_stats("dammage", 90, 340);
    text_loader_stats("range", 90, 380);
    text_loader_stats("ball_speed", 90, 420);
    text_loader_stats("luck", 90, 460);
}

void load_hud(void)
{
    create_text("coins_text", "00", "font");
    create_text("bombs_text", "00", "font");
    create_text("keys_text", "00", "font");
    move_text("coins_text", 69, 112);
    move_text("bombs_text", 69, 112 + 32);
    move_text("keys_text", 69, 112 + 64);
    outline_text("coins_text", 6, sfBlack);
    outline_text("bombs_text", 6, sfBlack);
    outline_text("keys_text", 6, sfBlack);
    sfText_setScale(get_text("coins_text")->text, (sfVector2f) {0.8f, 1.1f});
    sfText_setScale(get_text("bombs_text")->text, (sfVector2f) {0.8f, 1.1f});
    sfText_setScale(get_text("keys_text")->text, (sfVector2f) {0.8f, 1.1f});
    load_hud_stats();
}
