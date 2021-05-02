/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** duck_handling.c
*/

#include "my_defender.h"

sfVector2f new_pos(sfVector2f pos, scp sc)
{
    if (pos.x >= WIDTH) {
        pos.x = -110;
        pos.y = rand() % 300;
        sc->game.life -= 1;
    }
    else
        pos.x += 2;
    return (pos);
}

void init_rect(sfIntRect *rect, scp sc)
{
    if (rect->left + 110 >= 310) {
        rect->left = 0;
    } else
        rect->left += 110;
}

void shot_duck(scp sc, int i)
{
    sc->game.nbr_kill += 1;
    sc->game.mobs[i].pos.x = -110;
    sc->game.mobs[i].pos.y = rand() % 500;
    sc->game.mobs[i].rect.left = 0;
    if (sc->game.speed > 0)
        sc->game.speed -= 0.02;
}

void set_sprite_duck(scp scene, int i)
{
    if (getsec(scene->game.mobs[i].clockspr) >= 0.07) {
        init_rect(&scene->game.mobs[i].rect, scene);
        sfSprite_setTextureRect(scene->game.mobs[i].sprite, \
        scene->game.mobs[i].rect);
        sfClock_restart(scene->game.mobs[i].clockspr);
    }
}

void depla_duck(scp scene)
{
    for (int i = 0; scene->game.mobs[i].sprite; i++) {
        if (getsec(scene->game.mobs[i].clock) >= scene->game.speed) {
            scene->game.mobs[i].pos = new_pos(scene->game.mobs[i].pos, scene);
            sfSprite_setPosition(scene->game.mobs[i].sprite, \
            scene->game.mobs[i].pos);
            set_sprite_duck(scene, i);
            sfClock_restart(scene->game.mobs[i].clock);
        }
    }
}