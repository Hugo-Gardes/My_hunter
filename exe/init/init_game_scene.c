/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-tom.bartuzel
** File description:
** init_game_window.c
*/

#include "my_defender.h"

/*
    sprite[0] == background
*/

game_container init_cursor_game(game_container st)
{
    st.cursor = malloc(sizeof(game_obj_t) * 2);
    st.cursor->index = 0;
    st.cursor = create_object(st.cursor, \
    (init_create_obj){(sfVector2f){0, 0}, \
    (sfVector2f){100, 100}, (sfVector2f){0.30, 0.30}, "res/cursor.png"});
    return (st);
}

game_container init_game_scene(game_container game)
{
    game.index = 0;
    game.vector = malloc(sizeof(vector_t));
    game.obj = malloc(sizeof(game_obj_t) * 2);
    game.button = malloc(sizeof(button_t));
    game.life = 3;
    game.obj->index = 0;
    game.obj = create_object(game.obj, (init_create_obj){(sfVector2f){0, 0}, \
    (sfVector2f){800, 600}, (sfVector2f){1, 1}, "res/bg2.jpg"});
    game = init_cursor_game(game);
    game.button->sprite = NULL;
    return (game);
}