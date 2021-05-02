/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** init_end_scene.c
*/

#include "my_defender.h"

game_container init_end_button(game_container gc_start)
{
    gc_start.button = malloc(sizeof(button_t) * 4);
    gc_start.index = 0;
    gc_start.button = create_button(&gc_start, init_play_scene, \
    (to_init){"res/button/exit1.png", 10}, gc_start.vector[0]);
    gc_start.button = create_button(&gc_start, init_play_scene, \
    (to_init){"res/button/play1.png", 0}, gc_start.vector[1]);
    gc_start.button = create_button(&gc_start, init_play_scene, \
    (to_init){"res/button/hs.png", 1}, gc_start.vector[2]);
    return (gc_start);
}

void init_end_vector(game_container *game)
{
    game->vector = malloc(sizeof(vector_t) * 3);
    game->vector[0].pos = (sfVector2f){250, 400};
    game->vector[0].scale = (sfVector2f){0.21, 0.21};
    game->vector[0].size = (sfVector2f){100.0, 32.76};
    game->vector[1].pos = (sfVector2f){450, 400};
    game->vector[1].scale = (sfVector2f){0.21, 0.21};
    game->vector[1].size = (sfVector2f){100.0, 32.76};
    game->vector[2].pos = (sfVector2f){350, 500};
    game->vector[2].scale = (sfVector2f){0.21, 0.21};
    game->vector[2].size = (sfVector2f){100.0, 32.76};
}

game_container init_end_scene(game_container game)
{
    game.obj = malloc(sizeof(game_obj_t) * 2);
    game.text = malloc(sizeof(game_text_t) * 3);
    init_end_vector(&game);
    game.text->index = 0;
    game.obj->index = 0;
    game.text = create_text(game.text, (to_inittext){"res/f.ttf", \
    "You lose\nscore :", sfWhite, 60, (sfVector2f){WIDTH / 4, HEIGHT / 4}});
    game.text = create_text(game.text, (to_inittext){"res/f.ttf", "0", \
    sfWhite, 60, (sfVector2f){WIDTH / 4 + 74 * 3, HEIGHT / 4 + 78}});
    game.obj = create_object(game.obj, (init_create_obj){(sfVector2f){0, 0}, \
    (sfVector2f){800, 600}, (sfVector2f){1, 1}, "res/bg.jpg"});
    game = init_end_button(game);
    game = init_cursor_menu(game);
    return (game);
}