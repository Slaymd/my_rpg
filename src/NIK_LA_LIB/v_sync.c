/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** vsync
*/

#include "rpg.h"

void set_v_sync(rpg_t *rpg)
{
	static int enable = 1;

	sfRenderWindow_setVerticalSyncEnabled(rpg->wd, enable);
	if (enable == 0)
		enable = 1;
	else
		enable = 0;
}
