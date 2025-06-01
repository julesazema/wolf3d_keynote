/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** resource_loader
*/

#include "collectible.h"
#include "wolf.h"

static void load_entity_textures(void)
{
    load_resource("slime_texture", "assets/monsters/slime.png", TEXTURE);
    load_resource("blob_texture", "assets/monsters/blob.png", TEXTURE);
    load_resource("loki_texture", "assets/monsters/loki.png", TEXTURE);
    load_resource("fatty_texture", "assets/monsters/gros.png", TEXTURE);
    load_resource("fly_texture", "assets/monsters/fly.png", TEXTURE);
    load_resource("red_fly_texture", "assets/monsters/red_fly.png", TEXTURE);
    load_resource("king_fly_texture", "assets/monsters/king_fly.png", TEXTURE);
    load_resource("caca_texture", "assets/monsters/caca.png", TEXTURE);
    load_resource("fire_texture", "assets/fire_texture.png", TEXTURE);
    load_resource("bluefire_texture", "assets/bluefire_texture.png", TEXTURE);
    load_resource("rock_texture", "assets/rock.png", TEXTURE);
    load_resource("ladder_texture", "assets/ladder.png", TEXTURE);
}

static void load_game_textures(void)
{
    load_resource("floor_texture", "assets/floor.png", TEXTURE);
    load_resource("floor_texture_sacrifice", "assets/floor_sacrifice.png",
        TEXTURE);
    load_resource("wall_texture", "assets/wall.png", TEXTURE);
    load_resource("wall_texture_sacrifice", "assets/wall_sacrifice.png",
        TEXTURE);
    load_resource("door_texture", "assets/door.png", TEXTURE);
    load_resource("door_texture_item", "assets/door_golden.png", TEXTURE);
    load_resource("door_texture_shop", "assets/door_shop.png", TEXTURE);
    load_resource("door_texture_boss", "assets/door_boss.png", TEXTURE);
    load_resource("door_texture_sacrifice", "assets/door_sacrifice.png",
        TEXTURE);
}

static void load_textures(void)
{
    load_resource("tear_texture", "assets/tear.png", TEXTURE);
    load_resource("crosshair", "assets/crosshair.png", TEXTURE);
    load_resource("vignette", "assets/vignette.png", TEXTURE);
    load_resource("life_sheet", "assets/hearts.png", TEXTURE);
    load_resource("coin_hud", "assets/coin.png", TEXTURE);
    load_resource("bomb_hud", "assets/bomb.png", TEXTURE);
    load_resource("key_hud", "assets/key.png", TEXTURE);
    load_resource("pedestral", "assets/place_object.png", TEXTURE);
    load_resource("splatter_texture", "assets/splatter.png", TEXTURE);
    load_game_textures();
    load_collectibles_resources();
}

static void load_menu_resources(void)
{
    load_resource("test_1", "assets/backgrouds/isaac_menu_1.png", TEXTURE);
    load_resource("x_button", "assets/backgrouds/button_x.png", TEXTURE);
    load_resource("e_button", "assets/backgrouds/button_e.png", TEXTURE);
    load_resource("pointeur", "assets/backgrouds/pointeur.png", TEXTURE);
}

void load_resources(void)
{
    load_resource("menu_music", "assets/musics/menu.mp3", MUSIC);
    load_resource("basement_music", "assets/musics/basement.mp3", MUSIC);
    load_resource("mapmaker_music", "assets/musics/mapmaker.wav", MUSIC);
    load_resource("splatter01", "assets/sounds/splatter01.mp3", SOUND);
    load_resource("splatter02", "assets/sounds/splatter02.mp3", SOUND);
    load_resource("tear_fire0", "assets/sounds/tear_fire0.mp3", SOUND);
    load_resource("tear_impact0", "assets/sounds/tear_impact0.mp3", SOUND);
    load_resource("pennypickup", "assets/sounds/pennypickup.mp3", SOUND);
    load_resource("pillpickup", "assets/sounds/pillpickup.mp3", SOUND);
    load_resource("castleportcullis", "assets/sounds/castleportcullis.mp3",
        SOUND);
    load_resource("screenshot", "assets/sounds/screenshots.mp3", SOUND);
    load_resource("font", "assets/font/font.ttf", FONT);
    load_resource("subfont", "assets/font/onesize.ttf", FONT);
    load_textures();
    load_menu_resources();
    load_entity_textures();
}
