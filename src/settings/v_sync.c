/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** vsync
*/

#include "rpg.h"

void set_v_sync(rpg_t *rpg)
{
	static int enable = 0;

	sfRenderWindow_setVerticalSyncEnabled(rpg->wd, enable);
	enable++;
	if (enable == 2)
		enable = 0;
}
