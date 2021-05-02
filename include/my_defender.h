/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** my_defender.h
*/

#include <SFML/Audio/Export.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/System/Time.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <stdio.h>

#ifndef MY_DEFENDER
#define MY_DEFENDER

#include "button.h"

#define WIDTH 800
#define HEIGHT 600

#define w "layers/path.jpg"

typedef struct {
    char *font;
    char *text;
    sfColor color;
    unsigned int size;
    sfVector2f pos;
} to_inittext;

typedef struct game_text_s
{
    sfText *text;
    sfFont *font;
    int index;
} game_text_t;

typedef struct vector_s
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
} vector_t;

typedef struct open_window_s
{
    sfRenderWindow *window;
    sfVideoMode mode;
} open_window_t;

typedef struct game_obj_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
    int index;
} game_obj_t;

typedef struct {
    sfClock *clock;
    sfClock *clockspr;
    float second;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
    sfIntRect rect;
    void (*funct)(struct scene_container *sc, int i);
} mob, *mobss;

typedef struct {
    game_obj_t *obj;
    button_t *button;
    vector_t *vector;
    game_text_t *text;
    game_obj_t *cursor;
    sfMusic *shot;
    mob *mobs;
    int index;
    float speed;
    int nbr_kill;
    int life;
} game_container;

typedef struct {
    char *sprite;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
    void (*funct)(struct scene_container *sc, int i);
} stim;

typedef struct {
    char *path;
    int id;
} to_init;

typedef struct {
    sfMusic *music;
    game_container start;
    game_container end;
    game_container game;
    game_container scene_play;
    game_container scene_preced;
    game_container high_sc;
    int which_window;
    int which_window_preced;
    open_window_t window;
} scene_container, *scp;

typedef struct {
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
    char *pictures;
} init_create_obj;

button_t *create_button(game_container *scene, \
int (*funct)(void), to_init arg, vector_t vector);
game_obj_t *create_object(game_obj_t *obj, init_create_obj init);

game_container init_game_scene(game_container game);
scene_container *init_play_scene(scene_container *scenes, int wich_scenes);
vector_t *init_vector_menu(vector_t *vector);
game_container init_menu_scene(game_container gc_start);
scene_container init_scenes(scene_container scene);
game_container init_end_scene(game_container game);
void init_duck(scp sc);
game_text_t *create_text(game_text_t *text, to_inittext ini);
game_container init_h_scene(game_container game);

void event_handling(sfRenderWindow *window, scene_container *scene);
scene_container *init_scene(scene_container *scenes, sfVector2f pos_mouse);
void update_right_screen(scp scenes);
void depla_duck(scp scene);
void shot_duck(scp sc, int i);
void lose_event(scp sc);

void my_free(scp sc);

char *to_str(int nb);

float getsec(sfClock *clock);

void init_high_sc(char *path, char *score, int score_i);
char *open_read(char *path);

int my_strlen(char const *str);
int my_getnbr (char const *str);

game_container init_cursor_menu(game_container st);

int my_printf(char *str, ...);

#endif
