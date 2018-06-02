/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** pos generator
*/

#include "../../../include/rpg.h"

pos_t generate_hardpos_near(pos_t pos, int minradius)
{
	int maxtries = 4;
	int tries = 0;
	pos_t hardpos = pos;

	while ((hardpos.x >= pos.x - minradius && hardpos.x <= pos.x +
	minradius) || (hardpos.y >= pos.y - minradius && hardpos.y <=
	pos.y + minradius)) {
		hardpos.x = rand_time(pos.x-(minradius+1), pos.x+(minradius+1));
		hardpos.y = rand_time(pos.y - (minradius + 1), pos.y +
		(minradius + 1));
		tries++;
		if (tries >= maxtries) {
			maxtries *= 2;
			tries = 0;
			minradius += 1;
		}
		if (maxtries >= 32)
			break;
	}
	return (hardpos);
}

pos_t generate_pos_near(map_t *map, pos_t pos, int minradius)
{
	pos_t newpos = generate_hardpos_near(pos, minradius);

	for (int i = 0; i < 100 && !can_move_here(map, newpos); i++) {
		newpos = generate_hardpos_near(pos, minradius);
		minradius += 1;
	}
	return (newpos);
}
