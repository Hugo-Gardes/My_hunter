/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** init_high_score.c
*/

#include "my_defender.h"

char *open_read(char *path)
{
    int fd = open(path, O_RDONLY);
    char *str = malloc(sizeof(char) * 255);
    int size = 0;
    read(fd, str, 255);
    while (str[size] >= 48 && str[size] <= 57)
        size += 1;
    str[size] = 0;
    close(fd);
    return (str);
}

void set_high_score(char *path, char *score)
{
    int fd = open(path, O_WRONLY | O_TRUNC);
    write(fd, score, my_strlen(score));
}

void init_high_sc(char *path, char *score, int score_i)
{
    char *str = open_read(path);
    int last_high = my_getnbr(str);
    if (last_high < score_i)
        set_high_score(path, score);
    free(str);
}