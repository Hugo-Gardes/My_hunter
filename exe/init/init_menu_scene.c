/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-tom.bartuzel
** File description:
** open_window.c
*/

#include "my_defender.h"

/*
    sprite[0] == background
*/

game_container init_menu_obj(game_container start)
{
    start.obj = malloc(sizeof(game_obj_t) * 3);
    start.obj->index = 0;
    start.obj = create_object(start.obj, \
    (init_create_obj){(sfVector2f){0, 0}, \
    (sfVector2f){800, 600}, (sfVector2f){1, 1}, "res/bg.jpg"});
    return (start);
}

game_container init_menu_button(game_container gc_start)
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

game_container init_text_menu(game_container st)
{
    st.text = malloc(sizeof(game_obj_t) * 2);
    st.text->index = 0;
    st.text = create_text(st.text, (to_inittext){"res/f.ttf", \
    "My_Hunter", sfRed, 60, (sfVector2f){WIDTH / 4 + 45, HEIGHT / 4}});
    return (st);
}

game_container init_cursor_menu(game_container st)
{
    st.cursor = malloc(sizeof(game_obj_t) * 2);
    st.cursor->index = 0;
    st.cursor = create_object(st.cursor, \
    (init_create_obj){(sfVector2f){0, 0}, \
    (sfVector2f){100, 100}, (sfVector2f){0.03, 0.03}, "res/mcurs.png"});
    return (st);
}

game_container init_menu_scene(game_container gc_start)
{
    gc_start.index = 0;
    gc_start.life = 200;
    gc_start.vector = init_vector_menu(gc_start.vector);
    gc_start = init_menu_obj(gc_start);
    gc_start = init_menu_button(gc_start);
    gc_start = init_text_menu(gc_start);
    gc_start = init_cursor_menu(gc_start);
    return (gc_start);
}