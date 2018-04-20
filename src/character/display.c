/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** move
*/

#include "rpg.h"

void display_character_hp(rpg_t *rpg, character_t *character)
{
	float hp = 50 * (character->hp / 100.0);

	sfRectangleShape_setSize(character->hp_bar, (V2F){hp, 5});
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
	sfRenderWindow_drawRectangleShape(rpg->wd, character->hp_bar, NULL);
}

void display_character(rpg_t *rpg, character_t *character)
{
	character->time = sfClock_getElapsedTime(character->clock);
	character->seconds = character->time.microseconds / 1000000.0;
	move_character(character, rpg);
	if (character->hp > 0)
		display_character_hp(rpg, character);
	else
		sfRenderWindow_close(rpg->wd);
	display_minimap(character->sprite, rpg);
}
