/*
** EPITECH PROJECT, 2025
** G-ING-210-TLS-2-1-wolf3d-jules.azema
** File description:
** option
*/

#ifndef OPTION_H
    #define OPTION_H

    #include <stdio.h>
    #include "wolf.h"

    #define NBR_CTRL 6

void set_controls(void);
void set_fullscreen(void);

typedef enum control_key_s {
    K_JUMP,
    K_MOVE_FORWARD,
    K_MOVE_BACKWARD,
    K_MOVE_LEFT,
    K_MOVE_RIGHT,
    K_PLACEBOMB,
    K_SHOOT,
    K_ENTER,
    K_DOWN,
    K_UP
} control_key_t;

typedef enum input_type_s {
    I_KEYBOARD,
    I_CONTROLLER
} input_type_t;

typedef struct option_part_s {
    int music;
    int sound;
    int fov;
    int fullscreen;
    sfRectangleShape *pipe;
    sfEvent event;
} option_part_t;

typedef struct control_s {
    control_key_t key;
    char *name;
    char *description;
    sfKeyCode code;
} control_t;

typedef struct key_value_s {
    sfKeyCode key;
    char *name;
} key_value_t;

static const key_value_t key_values[] = {
    {sfKeyA, "A"},
    {sfKeyB, "B"},
    {sfKeyC, "C"},
    {sfKeyD, "D"},
    {sfKeyE, "E"},
    {sfKeyF, "F"},
    {sfKeyG, "G"},
    {sfKeyH, "H"},
    {sfKeyI, "I"},
    {sfKeyJ, "J"},
    {sfKeyK, "K"},
    {sfKeyL, "L"},
    {sfKeyM, "M"},
    {sfKeyN, "N"},
    {sfKeyO, "O"},
    {sfKeyP, "P"},
    {sfKeyQ, "Q"},
    {sfKeyR, "R"},
    {sfKeyS, "S"},
    {sfKeyT, "T"},
    {sfKeyU, "U"},
    {sfKeyV, "V"},
    {sfKeyW, "W"},
    {sfKeyX, "X"},
    {sfKeyY, "Y"},
    {sfKeyZ, "Z"},
    {sfKeyNum0, "0"},
    {sfKeyNum1, "1"},
    {sfKeyNum2, "2"},
    {sfKeyNum3, "3"},
    {sfKeyNum4, "4"},
    {sfKeyNum5, "5"},
    {sfKeyNum6, "6"},
    {sfKeyNum7, "7"},
    {sfKeyNum8, "8"},
    {sfKeyNum9, "9"},
    {sfKeyEscape, "Escape"},
    {sfKeyLBracket, "["},
    {sfKeyRBracket, "]"},
    {sfKeySemicolon, ";"},
    {sfKeyComma, ","},
    {sfKeyPeriod, "."},
    {sfKeyQuote, "'"},
    {sfKeySlash, "/"},
    {sfKeyBackslash, "\\"},
    {sfKeyTilde, "~"},
    {sfKeyEqual, "="},
    {sfKeyHyphen, "-"},
    {sfKeySpace, "Space"},
    {sfKeyEnter, "Enter"},
    {sfKeyBackspace, "Backspace"},
    {sfKeyTab, "Tab"},
    {sfKeyLeft, "Left"},
    {sfKeyRight, "Right"},
    {sfKeyUp, "Up"},
    {sfKeyDown, "Down"},
    {sfMouseLeft, "Left click"},
    {sfKeyRight, "Right click"},
    {0, NULL},
};

int is_control_pressed(control_key_t key);
void init_controllers(void);
input_type_t get_input_type(void);
void set_input_type(input_type_t input_type);

void init_option(void);
option_part_t *get_option(void);
void unload_option(void);

char *get_name_control(sfKeyCode code);
control_t *get_code_control(control_key_t key);

control_t **get_control(void);
void init_control(void);
void unload_control(void);

void on_key_pressed_controlscreen(sfEvent event);

#endif //OPTION_H
