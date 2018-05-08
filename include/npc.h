/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _NPC_H_
	#define _NPC_H_

	typedef struct npc_s npc_t;
	typedef struct npc_info_s npc_info_t;
	typedef struct dial_s dial_t;

	struct dial_s {
		char *dial;
		int ask;
		char *f_ch;
		char *s_ch;
		char *t_ch;
	};

	struct npc_info_s {
		int type;
		char *name;
		int age;
		int used;
		sfVector2f pos;
	};

	struct npc_s {
		sfSprite *s_npc[2];
		sfRectangleShape *box;
		sfSprite *s_arrow;
		sfTexture *t_arrow;
		sfText *text;
		sfFont *font;
		int select;
		sfClock *clock;
		sfTime time;
		float seconds;
	};

	//CREATE
	npc_t *create_npc(void);

	//DISPLAY
	void manage_inter(rpg_t *rpg);

	//TYPES
	void npc_game(rpg_t *rpg, int next);

#endif
