/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** perlin noise
*/

#include "../../../include/my.h"
#include "../../../include/map.h"

int permutation[] = {208,34,231,213,32,248,233,56,161,78,24,140,71,48,140,254,245,255,247,247,40,
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
	int hashed = permutation[((int)pos.y + seed) % 256];

	return (permutation[(hashed + (int)pos.x) % 256]);
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
	float amp = 1.0;
	float fin = 0;
	float divi = 0.0;

	for(int i = 0; i < depth; i++) {
		divi += 256 * amp;
		fin += noise_2d(map, (pos_t){xa, ya, 0}) * amp;
		amp /= 2;
		xa *= 2;
		ya *= 2;
	}

	return (fin/divi);
}

/*int main(int argc, char *argv[])
{
	for(int y = -10; y < 10; y++) {
		for(int x = -7; x < 10; x++)
			printf("%.2f ", get_perlin_value((pos_t){x, y, 0}, 0.1, 4));
		printf("\n");
	}

	return (0);
}*/

float Get2DPerlinNoiseValue(float x, float y, float res)
{
    float tempX,tempY;
    int x0,y0,ii,jj,gi0,gi1,gi2,gi3;
    float unit = 1.0f/sqrt(2);
    float tmp,s,t,u,v,Cx,Cy,Li1,Li2;
    float gradient2[][2] = {{unit,unit},{-unit,unit},{unit,-unit},{-unit,-unit},{1,0},{-1,0},{0,1},{0,-1}};

    unsigned int perm[] =
       {151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,
        142,8,99,37,240,21,10,23,190,6,148,247,120,234,75,0,26,197,62,94,252,219,
        203,117,35,11,32,57,177,33,88,237,149,56,87,174,20,125,136,171,168,68,175,
        74,165,71,134,139,48,27,166,77,146,158,231,83,111,229,122,60,211,133,230,220,
        105,92,41,55,46,245,40,244,102,143,54,65,25,63,161,1,216,80,73,209,76,132,
        187,208,89,18,169,200,196,135,130,116,188,159,86,164,100,109,198,173,186,3,
        64,52,217,226,250,124,123,5,202,38,147,118,126,255,82,85,212,207,206,59,227,
        47,16,58,17,182,189,28,42,223,183,170,213,119,248,152,2,44,154,163,70,221,
        153,101,155,167,43,172,9,129,22,39,253,19,98,108,110,79,113,224,232,178,185,
        112,104,218,246,97,228,251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,
        235,249,14,239,107,49,192,214,31,181,199,106,157,184,84,204,176,115,121,50,45,
        127,4,150,254,138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,
        156,180};

    //Adapter pour la résolution
    x /= res;
    y /= res;

    //On récupère les positions de la grille associée à (x,y)
    x0 = (int)(x);
    y0 = (int)(y);

    //Masquage
    ii = x0 & 255;
    jj = y0 & 255;

    //Pour récupérer les vecteurs
    gi0 = perm[ii + perm[jj]] % 8;
    gi1 = perm[ii + 1 + perm[jj]] % 8;
    gi2 = perm[ii + perm[jj + 1]] % 8;
    gi3 = perm[ii + 1 + perm[jj + 1]] % 8;

    //on récupère les vecteurs et on pondère
    tempX = x-x0;
    tempY = y-y0;
    s = gradient2[gi0][0]*tempX + gradient2[gi0][1]*tempY;

    tempX = x-(x0+1);
    tempY = y-y0;
    t = gradient2[gi1][0]*tempX + gradient2[gi1][1]*tempY;

    tempX = x-x0;
    tempY = y-(y0+1);
    u = gradient2[gi2][0]*tempX + gradient2[gi2][1]*tempY;

    tempX = x-(x0+1);
    tempY = y-(y0+1);
    v = gradient2[gi3][0]*tempX + gradient2[gi3][1]*tempY;


    //Lissage
    tmp = x-x0;
    Cx = 3 * tmp * tmp - 2 * tmp * tmp * tmp;

    Li1 = s + Cx*(t-s);
    Li2 = u + Cx*(v-u);

    tmp = y - y0;
    Cy = 3 * tmp * tmp - 2 * tmp * tmp * tmp;

    return Li1 + Cy*(Li2-Li1);
}
