/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** actionbar
*/

#ifndef ACTIONBAR_H
    # define ACTIONBAR_H

typedef struct actionbar_s {
    char content[128];
    char subtitle[128];
    double max_time;
    double displayed_time;
    int launched;
} actionbar_t;

actionbar_t *get_top_action(void);
void display_actionbars(void);
void remove_actionbar(actionbar_t *actionbar);

void display_action(char *content, double time_display);
void display_title(char *title, char *subtitle, double time_display);

#endif
