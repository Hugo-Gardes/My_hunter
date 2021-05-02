/*
** EPITECH PROJECT, 2020
** hunter
** File description:
** main.c
*/

#include "my_defender.h"

void my_hunter(void)
{
    scene_container scene = init_scenes(scene);

    sfRenderWindow_setMouseCursorVisible(scene.window.window, sfFalse);
    while (sfRenderWindow_isOpen(scene.window.window)) {
        event_handling(scene.window.window, &scene);
        if (scene.which_window == 1)
            lose_event(&scene);
        update_right_screen(&scene);
    }
    my_free(&scene);
}

int match__(char *str_to_comp, char *str)
{
    if (my_strlen(str_to_comp) != my_strlen(str))
        return (0);
    for (int i = 0; str[i]; i++)
        if (str[i] != str_to_comp[i])
            return (0);
    return (1);
}

void print_help(void)
{
    my_printf("Goal :\n");
    my_printf("\tThe goal of my_hunter is to shoot a maximum of duck.");
    my_printf("\n\tIf 3 ducks go out of the window you lose.\n");
    my_printf("\nHow to play:\n");
    my_printf("\tTo kill ducks you must click on them with mouse\n");
}

int main(int argc, char **argv)
{
    if (argc != 1) {
        if (match__(argv[1], "-h") || match__(argv[1], "--HELP")) {
            print_help();
        } else
            return (84);
    } else
        my_hunter();
    return (0);
}