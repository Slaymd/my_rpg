/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** display
*/

#include "rpg.h"

void display_fairy_line(fairy_t *fairy, rpg_t *rpg)
{
	float x = (float)sfMouse_getPositionRenderWindow(rpg->wd).x;
	float y = (float)sfMouse_getPositionRenderWindow(rpg->wd).y;
	sfVertex fairy_pos = {.position = fairy->pos, .color = sfRed};
	sfVertex mouse_pos = {.position = (V2F){x, y}, .color = sfRed};

	sfVertexArray_clear(fairy->line);
	sfVertexArray_append(fairy->line, fairy_pos);
	sfVertexArray_append(fairy->line, mouse_pos);
	sfVertexArray_setPrimitiveType(fairy->line, sfLinesStrip);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_normal);
	sfRenderWindow_drawVertexArray(rpg->wd, fairy->line, NULL);
	sfRenderWindow_setView(rpg->wd, rpg->view->v_screen);
}

void display_fairy(rpg_t *rpg, sfEvent event)
{
	rpg->fairy->time = sfClock_getElapsedTime(rpg->fairy->clock);
	rpg->fairy->seconds = rpg->fairy->time.microseconds / 1000000.0;
	move_fairy(rpg->fairy, rpg, event);
	fairy_fight(rpg->fairy, rpg);
	display_fairy_line(rpg->fairy, rpg);
	display_particle(rpg->fairy->particle, rpg->wd, rpg->fairy->pos,
	rpg->fairy->seconds >= 0.05 ? 1 : 0);
	display_minimap(rpg->fairy->sprite, rpg);
	if (rpg->fairy->seconds >= 0.05)
		sfClock_restart(rpg->fairy->clock);
}
