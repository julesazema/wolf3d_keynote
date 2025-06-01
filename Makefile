##
## EPITECH PROJECT, 2025
## Wolf3D
## File description:
## Makefile
##

NAME = wolf3d

SOURCES = main.c \
		srcs/window/window_helper.c \
		srcs/window/window_manager.c \
		srcs/window/window_displayer.c \
		srcs/controller/controller_manager.c \
		srcs/controller/control_manager.c \
		srcs/controller/control_helper.c \
		srcs/screens/screen_manager.c \
		srcs/screens/menu_screen.c \
		srcs/screens/init_menu_screen.c \
		srcs/screens/stats_screen.c \
		srcs/screens/options_screen.c \
		srcs/screens/init_options_screen.c \
		srcs/screens/intro_screen.c \
		srcs/screens/mapmaker_screen.c \
		srcs/screens/controls_screen.c \
		srcs/screens/game_screen.c \
		srcs/screens/paused_screen.c \
		srcs/events/event_handler.c \
		srcs/menu/menu_helper.c \
		srcs/player/player_manager.c \
		srcs/player/player_controls.c \
		srcs/player/player_movement.c \
		srcs/player/player_velocity.c \
		srcs/player/player_shoot.c \
		srcs/player/player_damage.c \
		srcs/projectile/tear.c \
		srcs/projectile/projectile_drawer.c \
		srcs/projectile/projectile_movements.c \
		srcs/entity/entity_manager.c \
		srcs/entity/entity_helper.c \
		srcs/entity/entity_displayer.c \
		srcs/entity/entity_texturizer.c \
		srcs/entity/entity_death.c \
		srcs/entity/ia_slime.c \
		srcs/entity/ia_blob.c \
		srcs/entity/ia_loki.c \
		srcs/entity/ia_king_fly.c \
		srcs/entity/ia_fatty.c \
		srcs/entity/ia_fly.c \
		srcs/entity/ia_red_fly.c \
		srcs/entity/ia_caca.c \
		srcs/entity/ia_fire.c \
		srcs/entity/ia_bluefire.c \
		srcs/entity/ia_rock.c \
		srcs/entity/ia_bomb.c \
		srcs/entity/ia_ladder.c \
		srcs/particles/particle_manager.c \
		srcs/collectibles/collectibles_manager.c \
        srcs/collectibles/collectibles_helper.c \
        srcs/collectibles/collectibles_drawer.c \
        srcs/collectibles/heart_collectibles.c \
        srcs/collectibles/coin_collectibles.c \
        srcs/collectibles/bomb_pickups.c \
		srcs/items/items_manager.c \
		srcs/items/items_helper.c \
		srcs/items/items_drawer.c \
		srcs/items/heart_item.c \
		srcs/items/rosary_item.c \
		srcs/items/toothpicks_item.c \
		srcs/items/synthoil_item.c \
		srcs/items/cricket_head_item.c \
		srcs/items/dollar_item.c \
		srcs/items/boom_item.c \
		srcs/items/polyphemus_item.c \
		srcs/items/sad_onion_item.c \
		srcs/items/a_quarter_item.c \
		srcs/items/small_rock_item.c \
		srcs/items/odd_mushroom_item.c \
		srcs/items/cat_o_nine_tails_item.c \
		srcs/items/number_one_item.c \
		srcs/items/pyromania_item.c \
		srcs/stats/stats_manager.c \
        srcs/run/run_manager.c \
        srcs/run/run_displayer.c \
        srcs/run/run_helper.c \
        srcs/run/content_helper.c \
        srcs/run/floor_generator.c \
        srcs/run/room_generator.c \
        srcs/run/floor_helper.c \
        srcs/run/run_launcher.c \
        srcs/run/run_saver.c \
        srcs/run/run_loader.c \
        srcs/mapmaker/mapmaker_manager.c \
        srcs/raycaster/ray_caster.c \
        srcs/raycaster/ray_manager.c \
        srcs/raycaster/ray_displayer.c \
        srcs/raycaster/ray_helper.c \
        srcs/raycaster/points_projector.c \
        srcs/raycaster/bloom_shader.c \
        srcs/hud/hud_drawer.c \
        srcs/hud/hud_initializer.c \
        srcs/hud/player_stats.c \
        srcs/hud/inventory_drawer.c \
        srcs/actionbar/actionbar_manager.c \
        srcs/actionbar/actionbar_displayer.c \
		srcs/resources/resource_loader.c \
		srcs/resources/resource_manager.c \
		srcs/sprites/sprite_manager.c \
		srcs/sprites/sprite_helper.c \
		srcs/sprites/sprite_mover.c \
		srcs/sprites/sprite_scaler.c \
		srcs/spritesheet/spritesheet_manager.c \
		srcs/buttons/button_manager.c \
		srcs/buttons/button_utils.c \
		srcs/texts/text_manager.c \
		srcs/texts/text_utils.c \
		srcs/texts/text_helper.c \
		srcs/texts/text_displayer.c \
		srcs/texts/text_projector.c \
		srcs/clocks/clock_manager.c \
		srcs/clocks/clock_helper.c \
		srcs/utils/mouse_utils.c \
		srcs/utils/sound_utils.c \
		srcs/utils/music_utils.c \
		srcs/utils/list_utils.c \
		srcs/utils/file_utils.c \
		srcs/utils/environment_utils.c \
		srcs/utils/random_utils.c \
		srcs/utils/ft_split.c \
		srcs/utils/ft_putstr.c \
		srcs/utils/ft_lstadd_back.c \
		srcs/utils/ft_strdup.c \
        srcs/utils/ft_strcpy.c \
        srcs/utils/ft_strcmp.c \
        srcs/utils/ft_strjoin.c \
        srcs/utils/ft_strnstr.c \
        srcs/utils/ft_strlen.c \
		srcs/utils/ft_itoa.c \
		srcs/utils/ft_atoi.c \
		srcs/utils/ft_strcat.c \
		srcs/utils/bits_utils.c \
        srcs/option/set_option.c \
        srcs/option/option_manager.c \
        srcs/minimap/draw_minimap.c \
        srcs/minimap/minimap_manager.c \
        srcs/minimap/get_minimap_room.c \
        srcs/screenshot/screenshot.c

OBJECTS = $(SOURCES:.c=.o)

CSFML_FLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

all: $(NAME)

$(NAME): $(OBJECTS)
		cc -o $(NAME) $(OBJECTS) $(CSFML_FLAGS) -lm -I./includes

%.o: %.c
		cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o) -I./includes

clean:
		rm -rf $(OBJECTS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
