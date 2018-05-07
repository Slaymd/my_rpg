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

	struct npc_info_s {
		int type;
		char *name;
		int age;
		int used;
		sfVector2f pos;
	};

	struct npc_s {
		sfSprite *sprite[2];
		sfRectangleShape *box;
		sfText *text;
		sfFont *font;
		sfClock *clock;
		sfTime time;
		float seconds;
	};

	//CREATE
	npc_t *create_npc(void);

	//DISPLAY
	void manage_inter(rpg_t *rpg);

	//TYPES
	void npc_game(rpg_t *rpg);

#endif
