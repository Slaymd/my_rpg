/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _PARTICLE_H_
	#define _PARTICLE_H_

	#define NB_FORM 2
	#define NB_EFFECT 2

	typedef struct particle_s particle_t;

	typedef enum form_type_s {
		SQUARE,
		CIRCLE
	} form_type_t;

	typedef enum effect_type_s {
		NONE,
		RADIAL
	} effect_type_t;

	typedef struct form_tab_s {
		form_type_t form;
		void (*func)(particle_t *particle, int refresh);
	} form_tab_t;

	typedef struct effect_tab_s {
		effect_type_t effect;
		void (*func)(particle_t *particle, sfVector2i pos, int refresh);
	} effect_tab_t;

	struct particle_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfUint8 *pixels;
		sfColor color;
		form_type_t form;
		effect_type_t effect;
		int x;
		int y;
	};

	//CREATE
	particle_t *create_particle(sfVector2i size, sfColor color, form_type_t
	form, effect_type_t effect);
	void destroy_particle(particle_t *particle);

	//DISPLAY
	void put_pixel(particle_t *particle, int x, int y, sfColor color);
	void display_particle(particle_t *particle, sfRenderWindow *window,
	sfVector2f pos, int refresh);

	//FORM
	void select_form(particle_t *particle, int refresh);
	void display_circle(particle_t *p, int refresh);
	void display_square(particle_t *p, int refresh);

	//EFFECT
	void select_effect(particle_t *particle, sfVector2i pos, int refresh);
	void no_effect(particle_t *particle, sfVector2i pos, int refresh);
	void radial_gradiant(particle_t *particle, sfVector2i pos, int refresh);
#endif
