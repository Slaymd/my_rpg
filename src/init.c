/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** init
*/

#include "../include/rpg.h"

void set_character(character_t *character)
{
	sfSprite_setTexture(character->sprite, character->texture, sfTrue);
	sfSprite_setPosition(character->sprite, character->pos_screen);
	sfSprite_setTextureRect(character->sprite, character->rect);
}

character_t *init_character(void)
{
	character_t *character = malloc(sizeof(character_t));
	int x = WIDTH / 2 - SIZE_C_X / 2;
	int y = HEIGHT / 2 - SIZE_C_Y / 2;

	if (!character)
		return (NULL);
	character->texture = sfTexture_createFromFile("./img/sacha.png", NULL);
	character->sprite = sfSprite_create();
	character->clock = sfClock_create();
	character->time = sfClock_getElapsedTime(character->clock);
	character->seconds = 0;
	character->rect = (sfIntRect){0,0, SIZE_C_X, SIZE_C_Y};
	character->speed = 4;
	character->pos_screen = (sfVector2f){x, y};
	character->pos = (pos_t){16000, 16000, 0};
	set_character(character);
	return (character);
}

fairy_t *init_fairy(void)
{
	fairy_t *fairy = malloc(sizeof(fairy_t));
	int x = WIDTH / 2 + 20;
	int y = HEIGHT / 2 + 20;

	fairy->texture = sfTexture_createFromFile("./img/fairy.png", NULL);
	fairy->sprite = sfSprite_create();
	fairy->clock = sfClock_create();
	fairy->time = sfClock_getElapsedTime(fairy->clock);
	fairy->seconds = 0;
	fairy->pos = (sfVector2f){x, y};
	fairy->pos = (sfVector2f){0, 0};
	fairy->rect = (sfIntRect){0,0, SIZE_F_X, SIZE_F_Y};
	sfSprite_setTexture(fairy->sprite, fairy->texture, sfTrue);
	sfSprite_setPosition(fairy->sprite, fairy->pos);
	sfSprite_setTextureRect(fairy->sprite, fairy->rect);
	sfSprite_setOrigin(fairy->sprite, (V2F){SIZE_F_X / 2, SIZE_F_Y / 2});
	return (fairy);
}

void set_window(window_t *window)
{
	window->window = sfRenderWindow_create(window->mode,"RPG",\
	sfClose | sfResize, NULL);
	sfView_setSize(window->v_screen,
	(sfVector2f){WIDTH * 0.6, HEIGHT * 0.6});
	sfView_setSize(window->v_map, (sfVector2f){WIDTH, HEIGHT});
	sfView_setViewport(window->v_map, (sfFloatRect){0.7, 0.05, 0.25, 0.25});
	sfRenderWindow_setFramerateLimit(window->window, 60);
	sfSprite_setTexture(window->sprite, window->texture, sfTrue);
	sfSprite_setPosition(window->sprite, (sfVector2f){0, 0});
	sfSprite_setTextureRect(window->sprite, window->rect);
}

window_t *init_window(void)
{
	window_t *window = malloc(sizeof(window_t));

	if (!window)
		return (NULL);
	window->mode = (sfVideoMode){WIDTH, HEIGHT, 32};
	window->texture = sfTexture_createFromFile("./img/bg.jpg", NULL);
	window->v_screen = sfView_createFromRect((sfFloatRect)
	{0, 0, WIDTH, HEIGHT});
	window->v_map = sfView_createFromRect((sfFloatRect)
	{0, 0, WIDTH, HEIGHT});
	window->sprite = sfSprite_create();
	window->rect = (sfIntRect){0, 0, WIDTH, HEIGHT};
	window->clock = sfClock_create();
	window->time = sfClock_getElapsedTime(window->clock);
	window->seconds = 0;
	set_window(window);
	return (window);
}

rpg_t *init_rpg(void)
{
	rpg_t *rpg = (rpg_t*)malloc(sizeof(rpg_t));

	if (!rpg)
		return (NULL);
	rpg->state = 0;
	rpg->wd = create_window();
	rpg->character = init_character();
	rpg->fairy = init_fairy();
	rpg->map = init_map(NULL, SEED);
	rpg->scene = init_mainmenu(rpg);
	rpg->v_screen = sfView_createFromRect((sfFloatRect)
	{0, 0, WIDTH, HEIGHT});
	rpg->v_map = sfView_createFromRect((sfFloatRect)
	{0, 0, WIDTH, HEIGHT});
	sfView_setSize(rpg->v_screen, (sfVector2f){WIDTH * 0.8, HEIGHT * 0.8});
	sfView_setSize(rpg->v_map, (sfVector2f){WIDTH, HEIGHT});
	sfView_setViewport(rpg->v_map, (sfFloatRect){0.7, 0.05, 0.25, 0.25});
	return (rpg);
}

void free_rpg(rpg_t *rpg)
{

}
