/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-tom.bartuzel
** File description:
** init_vector.c
*/

#include "my_defender.h"

vector_t *init_vector_menu(vector_t *vector)
{
    vector = malloc(sizeof(vector_t) * 3);
    vector[0].pos = (sfVector2f){250, 300};
    vector[0].scale = (sfVector2f){0.21, 0.21};
    vector[0].size = (sfVector2f){100.0, 32.76};
    vector[1].pos = (sfVector2f){450, 300};
    vector[1].scale = (sfVector2f){0.21, 0.21};
    vector[1].size = (sfVector2f){100.0, 32.76};
    vector[2].pos = (sfVector2f){350, 400};
    vector[2].scale = (sfVector2f){0.21, 0.21};
    vector[2].size = (sfVector2f){100.0, 32.76};
    return (vector);
}
