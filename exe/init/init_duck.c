/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** init_duck.c
*/

#include "my_defender.h"

bool check_pos_duck(int index, mobss mobs)
{
    for (int y = 0; y < index; y++)
        if (mobs[y].pos.y + 50 < mobs[index].pos.y + 50 && \
        mobs[y].pos.y - 50 > mobs[index].pos.y - 50)
            return (true);
    return (false);
}

void create_mobs(int in, stim don, mobss mobs)
{
    mobs[in].clock = sfClock_create();
    mobs[in].clockspr = sfClock_create();
    mobs[in].pos = don.pos;
    mobs[in].size = (sfVector2f){don.size.x * don.scale.x, \
    don.size.y * don.scale.y};
    mobs[in].scale = don.scale;
    mobs[in].rect = (sfIntRect){0, 0, mobs[in].size.x, mobs[in].size.y};
    mobs[in].second = 0.0;
    mobs[in].sprite = sfSprite_create();
    mobs[in].texture = sfTexture_createFromFile(don.sprite, NULL);
    mobs[in].funct = don.funct;
    sfSprite_setTexture(mobs[in].sprite, mobs[in].texture, sfTrue);
    sfSprite_setTextureRect(mobs[in].sprite, mobs[in].rect);
    sfSprite_setPosition(mobs[in].sprite, mobs[in].pos);
    mobs[in + 1].sprite = NULL;
}

void init_duck(scp sc)
{
    srand(time(NULL));
    int nbr_duck = rand() % 6 + 1;

    sc->game.speed = 0.07;
    sc->game.life = 3;
    sc->game.nbr_kill = 0;
    sc->game.mobs = malloc(sizeof(button_t) * (nbr_duck + 10));
    for (int y = 0; y < nbr_duck; y++) {
        do {
            sc->game.mobs[y].pos = (sfVector2f){rand()%100 - 110, rand()%300};
        } while (check_pos_duck(y, sc->game.mobs));
        create_mobs(y, (stim){"res/duck.png", sc->game.mobs[y].pos, \
        (sfVector2f){110, 110}, (sfVector2f){1, 1}, shot_duck}, sc->game.mobs);
    }
}