/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** create_object.c
*/

#include "my_defender.h"

game_obj_t *create_object(game_obj_t *obj, init_create_obj init)
{
    obj[obj->index].pos = init.pos;
    obj[obj->index].size = (sfVector2f){init.size.x * init.scale.x, \
    init.size.y * init.scale.y};
    obj[obj->index].sprite = sfSprite_create();
    obj[obj->index].texture = sfTexture_createFromFile(init.pictures, NULL);
    sfSprite_setTexture(obj[obj->index].sprite, \
    obj[obj->index].texture, sfTrue);
    sfSprite_setScale(obj[obj->index].sprite, init.scale);
    obj->index += 1;
    obj[obj->index].sprite = NULL;
    return (obj);
}