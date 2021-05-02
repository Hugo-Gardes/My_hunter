/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** count string size
*/

#include <stdarg.h>

int my_strlen(char const *str)
{
    int t = 0;
    for (; str[t] != 0; t++);
    return (t);
}