/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-tom.bartuzel
** File description:
** creat_button.c
*/

#include "my_defender.h"

button_t *create_button(game_container *scene, \
int (*funct)(void), to_init arg, vector_t vector)
{
    scene->button[scene->index].pos = vector.pos;
    scene->button[scene->index].funct = funct;
    scene->button[scene->index].sprite = sfSprite_create();
    scene->button[scene->index].texture = \
    sfTexture_createFromFile(arg.path, NULL);
    scene->button[scene->index].size = vector.size;
    sfSprite_setTexture(scene->button[scene->index].sprite, \
    scene->button[scene->index].texture, sfTrue);
    sfSprite_setPosition(scene->button[scene->index].sprite, vector.pos);
    sfSprite_setScale(scene->button[scene->index].sprite, vector.scale);
    if (funct != 0) {
        scene->button[scene->index].id = arg.id;
    } else
        scene->button[scene->index].id = 0;
    scene->index++;
    scene->button[scene->index].sprite = NULL;
    return (scene->button);
}