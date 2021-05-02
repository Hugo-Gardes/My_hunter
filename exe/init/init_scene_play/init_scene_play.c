/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-tom.bartuzel
** File description:
** options.c
*/

#include "my_defender.h"
/*
0 menu
1 level
2 param
3 game
4 button */

void init_switch_hc(scp scenes)
{
    char *str = open_read("res/high_score.txt");
    scenes->scene_preced = scenes->scene_play;
    scenes->scene_play = scenes->high_sc;
    scenes->which_window = 4;
    scenes->which_window_preced = 0;
    sfText_setString(scenes->high_sc.text[1].text, str);
    free(str);
}

void switch_menu(scene_container *scenes, int wich_scenes)
{
    game_container save = scenes->scene_play;
    switch (wich_scenes) {
        case 0:
            scenes->scene_preced = scenes->scene_play;
            scenes->scene_play = scenes->game;
            scenes->which_window = 1;
            scenes->which_window_preced = 0;
            break;
        case 1:
            init_switch_hc(scenes);
            break;
        case 2:
            scenes->scene_play = scenes->scene_preced;
            scenes->scene_preced = save;
            scenes->which_window = scenes->which_window_preced;
            break;
    }
}

void switch_end(scene_container *scenes, int wich_scenes)
{
    switch (wich_scenes) {
        case 11:
            scenes->scene_preced = scenes->scene_play;
            scenes->scene_play = scenes->high_sc;
            scenes->which_window = 4;
            scenes->which_window_preced = 3;
            break;
    }
}

scene_container *init_play_scene(scene_container *scenes, int wich_scenes)
{
    if (wich_scenes == 10)
        sfRenderWindow_close(scenes->window.window);
    if (wich_scenes < 10)
        switch_menu(scenes, wich_scenes);
    return (scenes);
}