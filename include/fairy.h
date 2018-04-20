/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _FAIRY_H_
	#define _FAIRY_H_

	#define SIZE_F_X 34
	#define SIZE_F_Y 49
	#define MOVE_F_X 50
	#define MOVE_F_Y 55
	#define EXPLO_X 192
	#define EXPLO_Y 195

	typedef struct fairy_s fairy_t;
	typedef struct shoot_s shoot_t;
	typedef struct list_shoot_s list_shoot_t;

	struct shoot_s {
		sfIntRect rect;
		pos_t pos;
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
		list_shoot_t *shoot;
		sfVertexArray *line;
		sfMusic *shhh;
	};

#endif
