/*
** EPITECH PROJECT, 2025
** my_world
** File description:
** text_manager
*/

#include <stdlib.h>
#include "list.h"
#include "wolf.h"

static list_t **local_get_texts(void)
{
    static list_t *texts = NULL;

    return (&texts);
}

void create_text(char *name, char *text, char *font_name)
{
    text_t *result;
    resource_t *font;

    if (get_text(name) != NULL)
        return;
    font = get_resource(font_name);
    if (!font || font->type != FONT)
        return;
    result = malloc(sizeof(text_t));
    if (!result)
        return;
    ft_strcpy(result->name, name);
    result->text = sfText_create();
    sfText_setString(result->text, text);
    sfText_setFont(result->text, font->data);
    result->hidden = 0;
    *local_get_texts() = ft_createnode(result, *local_get_texts());
}

text_t *get_text(char *name)
{
    list_t *texts;
    text_t *current;

    texts = *local_get_texts();
    while (texts) {
        current = texts->data;
        if (ft_strcmp(current->name, name) == 0)
            return (current);
        texts = texts->next;
    }
    return (NULL);
}

void draw_texts(void)
{
    list_t *texts;
    text_t *current;

    texts = *local_get_texts();
    while (texts) {
        current = texts->data;
        if (!current->hidden)
            sfRenderWindow_drawText(get_window(), current->text, NULL);
        texts = texts->next;
    }
}

void unload_texts(void)
{
    list_t *current;
    list_t *next;

    current = *local_get_texts();
    while (current) {
        next = current->next;
        sfText_destroy(((text_t *) current->data)->text);
        free(current->data);
        free(current);
        current = next;
    }
    *local_get_texts() = NULL;
}
