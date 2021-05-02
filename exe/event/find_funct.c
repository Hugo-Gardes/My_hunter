/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-tom.bartuzel
** File description:
** menu_event.c
*/

#include "my_defender.h"

void gest_scene(scene_container *scene, int index)
{
    if (scene->which_window == 1) {
        scene->scene_play.mobs[index].\
        funct(scene, index);
    } else
        scene->scene_play.button[index].\
        funct(scene, scene->scene_play.button[index].id);
}

void verif_posb(sfVector2f pos_mouse, sfVector2f pos_button, \
scene_container *scene, int *index)
{
    if (pos_mouse.x >= pos_button.x && pos_mouse.x <= \
    pos_button.x + scene->scene_play.mobs[*index].size.x) {
        if (pos_mouse.y >= pos_button.y && pos_mouse.y <= \
        pos_button.y + scene->scene_play.mobs[*index].size.y) {
            gest_scene(scene, *index);
            *index = 9998;
        }
    }
}

void verif_pos(sfVector2f pos_mouse, sfVector2f pos_button, \
scene_container *scene, int *index)
{
    if (pos_mouse.x >= pos_button.x && pos_mouse.x <= \
    pos_button.x + scene->scene_play.button[*index].size.x) {
        if (pos_mouse.y >= pos_button.y && pos_mouse.y <= \
        pos_button.y + scene->scene_play.button[*index].size.y) {
            gest_scene(scene, *index);
            *index = 9998;
        }
    }
}

scene_container *init_scene(scene_container *scenes, sfVector2f pos_mouse)
{
    int valid = 0;
    int u = 0;

    for (;scenes->which_window == 1 && u != 9999 && \
    scenes->scene_play.mobs[u].sprite; u++) {
        verif_posb(pos_mouse, scenes->scene_play.mobs[u].pos, scenes, &u);
        if (u == 9998)
            valid = 1;
    }
    for (u = 0; u != 9999 && scenes->scene_play.button[u].sprite; u++) {
        verif_pos(pos_mouse, scenes->scene_play.button[u].pos, scenes, &u);
        if (u == 9998)
            valid = 1;
    }
    return (scenes);
}