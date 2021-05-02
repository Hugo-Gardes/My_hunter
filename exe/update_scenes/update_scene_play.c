/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-tom.bartuzel
** File description:
** update_screen.c
*/

#include "my_defender.h"

void update_s_t_b_bis(scene_container scenes)
{
    if (scenes.which_window == 2 || scenes.which_window == 0 || \
    scenes.which_window == 4) {
        for (int u = 0; scenes.scene_play.text[u].text; u++) {
            sfRenderWindow_drawSprite(scenes.window.window, \
            scenes.scene_play.text[u].text, NULL);
        }
    }
    if (scenes.which_window == 1) {
        for (int u = 0; scenes.game.mobs[u].sprite; u++) {
            sfRenderWindow_drawSprite(scenes.window.window, \
            scenes.game.mobs[u].sprite, NULL);
        }
    }
}

void update_s_t_b(scene_container scenes)
{
    for (int u = 0; scenes.scene_play.obj[u].sprite; u++) {
        sfRenderWindow_drawSprite(scenes.window.window, \
        scenes.scene_play.obj[u].sprite, NULL);
    }
    for (int u = 0; scenes.scene_play.button[u].sprite; u++) {
        sfRenderWindow_drawSprite(scenes.window.window, \
        scenes.scene_play.button[u].sprite, NULL);
    }
    update_s_t_b_bis(scenes);
    for (int u = 0; scenes.scene_play.cursor[u].sprite; u++) {
            sfRenderWindow_drawSprite(scenes.window.window, \
            scenes.scene_play.cursor[u].sprite, NULL);
        }
}

void update_right_screen(scp scenes)
{
    sfRenderWindow_clear(scenes->window.window, sfBlack);
    update_s_t_b(*scenes);
    if (scenes->which_window == 1)
        depla_duck(scenes);
    sfRenderWindow_display(scenes->window.window);
}