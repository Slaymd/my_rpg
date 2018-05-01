/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** texture manager
*/

#include "../../../include/rpg.h"

int	is_txt_var_table_match(float adjtxt[9], float txtvar[9])
{
	for (int i = 0; i < 9; i++) {
		if (txtvar[i] != -1.0 && adjtxt[i] != txtvar[i])
			return (0);
	}
	return (1);
}

int	get_texture_id(float adjtxt[9])
{
	int txtid = 1;

	txtid = get_texture_variation(adjtxt);
	return (txtid);
}
