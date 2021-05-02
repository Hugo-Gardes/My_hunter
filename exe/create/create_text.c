/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** create_text.c
*/

#include "my_defender.h"

game_text_t *create_text(game_text_t *text, to_inittext ini)
{
    text[text->index].text = sfText_create();
    text[text->index].font = sfFont_createFromFile(ini.font);
    sfText_setFont(text[text->index].text, text[text->index].font);
    sfText_setString(text[text->index].text, ini.text);
    sfText_setColor(text[text->index].text, ini.color);
    sfText_setCharacterSize(text[text->index].text, ini.size);
    sfText_setPosition(text[text->index].text, ini.pos);
    text->index += 1;
    text[text->index].text = NULL;
    return (text);
}