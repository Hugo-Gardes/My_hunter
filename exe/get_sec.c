/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** get_sec.c
*/

#include "my_defender.h"

float getsec(sfClock *clock)
{
    float seconds;
    sfTime time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    return (seconds);
}