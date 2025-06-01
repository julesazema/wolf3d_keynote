/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** entity_texturizer
*/

#include "entity.h"

static const entity_model_t entity_models[] = {
    {E_EMBRYO, 12, "slime_texture", 4, 7, 24, &ia_slime},
    {E_BLOB, 12, "blob_texture", 4, 3, 12, &ia_blob},
    {E_LOKI, 350, "loki_texture", 6, 6, 18, &ia_loki},
    {E_FATTY, 20, "fatty_texture", 8, 4, 12, &ia_fatty},
    {E_FLY, 3, "fly_texture", 2, 1, 2, &ia_fly},
    {E_CACA, 6, "caca_texture", 3, 2, 4, &ia_caca},
    {E_FIRE, 3, "fire_texture", 5, 2, 6, &ia_fire},
    {E_BLUEFIRE, 1, "bluefire_texture", 5, 2, 6, &ia_bluefire},
    {E_ROCK, 1, "rock_texture", 1, 1, 1, &ia_rock},
    {E_RED_FLY, 6, "red_fly_texture", 2, 1, 2, &ia_red_fly},
    {E_BOMB, 5, "bomb_hud", 1, 1, 1, &ia_bomb},
    {E_LADDER, 1, "ladder_texture", 1, 1, 1, &ia_ladder},
    {E_KING_FLY, 150, "king_fly_texture", 2, 2, 2, &ia_king_fly},
    {0, 0, 0, 0, 0, 0, 0}
};

const entity_model_t *get_entity_model(entity_type_t entity_type)
{
    int i;

    i = 0;
    while (entity_models[i].life) {
        if (entity_models[i].type == entity_type)
            return (&entity_models[i]);
        i++;
    }
    return (NULL);
}

spritesheet_t model_to_spritesheet(const entity_model_t *model)
{
    return (create_spritesheet(model->resource_name,
                model->nb_cols,
                model->nb_rows,
                model->nb_steps));
}
