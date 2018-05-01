/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** texture variation table
*/

#include "../../../include/rpg.h"

int	get_sand_variation(float adjtxt[9])
{
	float txtvars[][9] = {S_N1NE1E1, S_E1SE1S1, S_W1SW1S1, S_N1NW1W1, S_SE1,
		S_S1, S_SW1, S_W1, S_NW1, S_N1, S_NE1, S_E1, DSTP};
	int txts[] = {TILE_SAND_N1NE1E1_ID, TILE_SAND_E1SE1S1_ID,
		TILE_SAND_W1SW1S1_ID, TILE_SAND_N1NW1W1_ID, TILE_SAND_SE1_ID,
		TILE_SAND_S1_ID, TILE_SAND_SW1_ID, TILE_SAND_W1_ID,
		TILE_SAND_NW1_ID, TILE_SAND_N1_ID, TILE_SAND_NE1_ID,
		TILE_SAND_E1_ID};

	for (int i = 0; txtvars[i][0] != -2.0; i++) {
		if (is_txt_var_table_match(adjtxt, txtvars[i]))
			return (txts[i]);
	}
	return (adjtxt[4]);
}

int	get_grass_variation3(float adjtxt[9])
{
	float txtvars[][9] = {G_N4NE4E4, G_E4SE4S4, G_W4SW4S4, G_N4NW4W4, G_SE4,
		G_S4, G_SW4, G_W4, G_NW4, G_N4, G_NE4, G_E4, DSTP};
	int txts[] = {TILE_GRASS_N4NE4E4_ID, TILE_GRASS_E4SE4S4_ID,
		TILE_GRASS_W4SW4S4_ID, TILE_GRASS_N4NW4W4_ID, TILE_GRASS_SE4_ID,
		TILE_GRASS_S4_ID, TILE_GRASS_SW4_ID, TILE_GRASS_W4_ID,
		TILE_GRASS_NW4_ID, TILE_GRASS_N4_ID, TILE_GRASS_NE4_ID,
		TILE_GRASS_E4_ID};

	for (int i = 0; txtvars[i][0] != -2.0; i++) {
		if (is_txt_var_table_match(adjtxt, txtvars[i]))
			return (txts[i]);
	}
	return (adjtxt[4]);
}

int	get_grass_variation2(float adjtxt[9])
{
	float txtvars[][9] = {G_N2NE2E2, G_E2SE2S2, G_W2SW2S2, G_N2NW2W2, G_SE2,
		G_S2, G_SW2, G_W2, G_NW2, G_N2, G_NE2, G_E2, DSTP};
	int txts[] = {TILE_GRASS_N2NE2E2_ID, TILE_GRASS_E2SE2S2_ID,
		TILE_GRASS_W2SW2S2_ID, TILE_GRASS_N2NW2W2_ID, TILE_GRASS_SE2_ID,
		TILE_GRASS_S2_ID, TILE_GRASS_SW2_ID, TILE_GRASS_W2_ID,
		TILE_GRASS_NW2_ID, TILE_GRASS_N2_ID, TILE_GRASS_NE2_ID,
		TILE_GRASS_E2_ID};

	for (int i = 0; txtvars[i][0] != -2.0; i++) {
		if (is_txt_var_table_match(adjtxt, txtvars[i]))
			return (txts[i]);
	}
	return (get_grass_variation3(adjtxt));
}

int	get_grass_variation(float adjtxt[9])
{
	float txtvars[][9] = {G_N1NE1E1, G_E1SE1S1, G_W1SW1S1, G_N1NW1W1, G_SE1,
		G_S1, G_SW1, G_W1, G_NW1, G_N1, G_NE1, G_E1, DSTP};
	int txts[] = {TILE_GRASS_N1NE1E1_ID, TILE_GRASS_E1SE1S1_ID,
		TILE_GRASS_W1SW1S1_ID, TILE_GRASS_N1NW1W1_ID, TILE_GRASS_SE1_ID,
		TILE_GRASS_S1_ID, TILE_GRASS_SW1_ID, TILE_GRASS_W1_ID,
		TILE_GRASS_NW1_ID, TILE_GRASS_N1_ID, TILE_GRASS_NE1_ID,
		TILE_GRASS_E1_ID};

	for (int i = 0; txtvars[i][0] != -2.0; i++) {
		if (is_txt_var_table_match(adjtxt, txtvars[i]))
			return (txts[i]);
	}
	return (get_grass_variation2(adjtxt));
}

int	get_texture_variation(float adjtxt[9])
{
	int main_id = (int)adjtxt[4];
	int (*pf[])(float[9]) = {&get_grass_variation, &get_sand_variation,
		NULL};
	int pf_txtids[] = {TILE_GRASS_ID, TILE_SAND_ID, -1};

	for (int i = 0; pf_txtids[i] != -1; i++) {
		if (pf_txtids[i] == main_id)
			return (pf[i](adjtxt));
	}
	return (main_id);
}
