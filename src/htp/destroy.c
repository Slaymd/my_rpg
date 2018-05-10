/*
** EPITECH PROJECT, 2017
** raphou
** File description:
** free
*/

#include "rpg.h"

void free_htp(htp_t *htp)
{
	sfClock_destroy(htp->clock);
	free(htp);
}
