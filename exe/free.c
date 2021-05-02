/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** free.c
*/

#include "my_defender.h"

void free_button(scp sc)
{
    for (int x = 0; sc->start.button[x].sprite != NULL; x++)
        sfSprite_destroy(sc->start.button[x].sprite);
    for (int x = 0; sc->end.button[x].sprite != NULL; x++)
        sfSprite_destroy(sc->end.button[x].sprite);
    for (int x = 0; sc->game.button[x].sprite != NULL; x++)
        sfSprite_destroy(sc->game.button[x].sprite);
    free(sc->start.button);
    free(sc->game.button);
    free(sc->end.button);
}

void free_object(scp sc)
{
    for (int x = 0; sc->start.obj[x].sprite; x++)
        sfSprite_destroy(sc->start.obj[x].sprite);
    for (int x = 0; sc->end.obj[x].sprite; x++)
        sfSprite_destroy(sc->end.obj[x].sprite);
    for (int x = 0; sc->game.obj[x].sprite; x++)
        sfSprite_destroy(sc->game.obj[x].sprite);
    sfMusic_destroy(sc->music);
    sfMusic_destroy(sc->game.shot);
    free(sc->start.obj);
    free(sc->game.obj);
    free(sc->end.obj);
}

void free_vector(scp sc)
{
    if (sc->end.vector)
        free(sc->end.vector);
    if (sc->game.vector)
        free(sc->game.vector);
    if (sc->start.vector)
        free(sc->start.vector);
}

void my_free(scp sc)
{
    free_button(sc);
    free_object(sc);
    free_vector(sc);
    sfRenderWindow_close(sc->window.window);
}