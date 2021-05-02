/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** cassecouille.h
*/

#ifndef CASSECOUILLE_H
#define CASSECOUILLE_H

#include "my_defender.h"

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
    int id;
    int (*funct)(struct scene_container *scene_container, int id);
} button_t;

#endif