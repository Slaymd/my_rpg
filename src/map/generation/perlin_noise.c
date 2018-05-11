/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** perlin noise
*/

#include "../../../include/rpg.h"

int perm[] = {208,34,231,213,32,248,233,56,161,78,24,140,71,48,140,254,245,255,247,247,40,
			185,248,251,245,28,124,204,204,76,36,1,107,28,234,163,202,224,245,128,167,204,
			9,92,217,54,239,174,173,102,193,189,190,121,100,108,167,44,43,77,180,204,8,81,
			70,223,11,38,24,254,210,210,177,32,81,195,243,125,8,169,112,32,97,53,195,13,
			203,9,47,104,125,117,114,124,165,203,181,235,193,206,70,180,174,0,167,181,41,
			164,30,116,127,198,245,146,87,224,149,206,57,4,192,210,65,210,129,240,178,105,
			228,108,245,148,140,40,35,195,38,58,65,207,215,253,65,85,208,76,62,3,237,55,89,
			232,50,217,64,244,157,199,121,252,90,17,212,203,149,152,140,187,234,177,73,174,
			193,100,192,143,97,53,145,135,19,103,13,90,135,151,199,91,239,247,33,39,145,
			101,120,99,3,186,86,99,41,237,203,111,79,220,135,158,42,30,154,120,67,87,167,
			135,176,183,191,253,115,184,21,233,58,129,233,142,39,128,211,118,137,139,255,
			114,20,218,113,154,27,127,246,250,1,8,198,250,209,92,222,173,21,88,102,219};

int noise(int seed, sfVector2i pos)
{
	int hashed = perm[((int)pos.y + seed) % 256];

	return (perm[(hashed + (int)pos.x) % 256]);
}

float lin_inter(sfVector2i pos, float s)
{
	return (pos.x + s * (pos.y-pos.x));
}

float smooth_inter(sfVector2i pos, float s)
{
	return (lin_inter(pos, s * s * (3-2*s)));
}

float noise_2d(map_t *map, pos_t pos)
{
	sfVector2i int_pos = {(int)pos.x, (int)pos.y};
	sfVector2f frac = {pos.x - int_pos.x, pos.y - int_pos.y};
	int s = noise(map->seed, int_pos);
	int t = noise(map->seed, (sfVector2i){int_pos.x+1, int_pos.y});
	int u = noise(map->seed, (sfVector2i){int_pos.x, int_pos.y+1});
	int v = noise(map->seed, (sfVector2i){int_pos.x+1, int_pos.y+1});
	float low = smooth_inter((sfVector2i){s, t}, frac.x);
	float high = smooth_inter((sfVector2i){u, v}, frac.x);

	return (smooth_inter((sfVector2i){low, high}, frac.y));
}

float get_perlin_value(map_t *map, pos_t pos, float freq, int depth)
{
	float xa = pos.x*freq;
	float ya = pos.y*freq;
	float amplitude = 2.0;
	float fin = 0;
	float division = 0.0;

	for(int i = 0; i < depth; i++) {
		division += 256 * amplitude;
		fin += noise_2d(map, (pos_t){xa, ya, 0}) * amplitude;
		amplitude /= 2;
		xa *= 2;
		ya *= 2;
	}
	return (fin/division);
}
