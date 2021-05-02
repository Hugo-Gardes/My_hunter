/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-tom.bartuzel
** File description:
** event_handling.c
*/

#include "../include/my_defender.h"

void quit_event(sfRenderWindow *window, sfEvent event)
{
    if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) || \
    event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
}

void which_event_mouse(sfRenderWindow *window, scene_container\
*scenes, sfEvent ev)
{
    sfVector2i vecti = {0, 0};
    sfVector2f vectf = {0, 0};

    if (sfMouse_isButtonPressed(sfMouseLeft) && ev.type == \
    sfEvtMouseButtonPressed) {
        vecti = sfMouse_getPositionRenderWindow(window);
        vectf = (sfVector2f){vecti.x, vecti.y};
        init_scene(scenes, vectf);
    }
    if (ev.type == sfEvtMouseMoved) {
        vecti = sfMouse_getPositionRenderWindow(window);
        vectf = (sfVector2f){vecti.x - (scenes->scene_play.cursor->size.x / 2)\
        , vecti.y - (scenes->scene_play.cursor->size.y / 2)};
        scenes->scene_play.cursor->pos = vectf;
        sfSprite_setPosition(scenes->scene_play.cursor->sprite, vectf);
    }
}

void lose_event(scp sc)
{
    char *s = to_str(20 * sc->game.nbr_kill);
    if (s[0] == NULL) {
        s[0] = '0';
        s[1] = 0;
    }
    if (sc->game.life <= 0) {
        init_high_sc("res/high_score.txt", s, 20 * sc->game.nbr_kill);
        sc->scene_play = sc->end;
        sc->which_window = 2;
        sfText_setString(sc->end.text[1].text, s);
        sc->game.life = 3;
        sc->game.nbr_kill = 0;
        for (int i = 0; sc->game.mobs[i].sprite; i++)
            sc->game.mobs[i].pos = (sfVector2f){rand()%100 - 110, rand()%300};
    }
}

void event_handling(sfRenderWindow *window, scene_container *scene)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyB)
            scene->game.life = 0;
        quit_event(window, event);
        which_event_mouse(window, scene, event);
    }
}