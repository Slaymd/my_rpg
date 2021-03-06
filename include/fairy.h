/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _FAIRY_H_
	#define _FAIRY_H_

	#define SIZE_F_X 72
	#define SIZE_F_Y 69
	#define MOVE_F_X 35
	#define MOVE_F_Y 40
	#define EXPLO_X 192
	#define EXPLO_Y 195
	#define ROCKET_X 32
	#define ROCKET_Y 32

	typedef struct fairy_s fairy_t;
	typedef struct shoot_s shoot_t;
	typedef struct list_shoot_s list_shoot_t;

	struct shoot_s {
		int state;
		sfIntRect rect;
		float angle;
		pos_t pos_r;
		pos_t pos_e;
		sfVector2f distance;
		shoot_t *next;
	};

	struct list_shoot_s {
		shoot_t *first;
	};

	struct fairy_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
		sfClock *clock;
		sfTime time;
		float seconds;
		sfVector2f pos;
		sfVector2f ec;
		sfVector2f ep;
		sfSprite *s_explo;
		sfTexture *t_explo;
		sfSprite *s_rocket;
		sfTexture *t_rocket;
		particle_t *particle;
		list_shoot_t *shoot;
		sfVertexArray *line;
		sfMusic *shhh;
	};

#endif
