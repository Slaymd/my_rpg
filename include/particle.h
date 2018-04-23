/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _PARTICLE_H_
	#define _PARTICLE_H_

	typedef struct particle_s particle_t;

	struct particle_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfUint8 *pixels;
		sfColor color;
		int x;
		int y;
	};
	particle_t *create_particle(int x, int y);
	void display_particle(particle_t *particle, sfRenderWindow *window,
	sfVector2f pos);
	void destroy_particle(particle_t *particle);
	void put_pixel(particle_t *particle, int x, int y, sfColor color);

	void radian_gradiant(particle_t *particle, sfVector2i pos);

#endif
