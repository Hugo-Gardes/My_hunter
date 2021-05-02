/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-tom.bartuzel
** File description:
** init_handle.c
*/

#include "my_defender.h"

open_window_t init_window(open_window_t window_t)
{
    window_t.mode = (sfVideoMode){WIDTH, HEIGHT, 32};
    window_t.window = sfRenderWindow_create(window_t.mode, \
    "my_hunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window_t.window, 120);
    return (window_t);
}

scene_container init_scenes(scene_container scene)
{
    scene.which_window = 0;
    scene.window = init_window(scene.window);
    scene.music = sfMusic_createFromFile\
    ("res/duck-hunt-music-title-theme.ogg");
    scene.game.shot = sfMusic_createFromFile("res/feu.ogg");
    sfMusic_setVolume(scene.music, 5);
    sfMusic_setLoop(scene.music, sfTrue);
    sfMusic_play(scene.music);
    scene.start = init_menu_scene(scene.start);
    scene.game = init_game_scene(scene.game);
    scene.end = init_end_scene(scene.end);
    scene.high_sc = init_h_scene(scene.high_sc);
    init_duck(&scene);
    scene.scene_play = scene.start;
    return (scene);
}