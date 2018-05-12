/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _NPC_H_
	#define _NPC_H_

	typedef struct npc_s npc_t;
	typedef struct dial_s dial_t;

	struct dial_s {
		char *dial;
		int ask;
		char *f_ch;
		char *s_ch;
		char *t_ch;
	};

	struct npc_s {
		sfSprite *s_npc[2];
		sfRectangleShape *box;
		ms_t *ms;
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
	void display_question(rpg_t *rpg, sfText *text, dial_t dial, int nbr);
	void display_arrow(rpg_t *rpg, int choices, dial_t dial);

	//DETECT
	int detect_villager(entity_t *ent, map_t *map);

	//TYPES
	void npc_game(rpg_t *rpg, int next, int *choice);
	void npc_math(rpg_t *rpg, int next, int *choice);

	//DISPLAY
	void display_arrow(rpg_t *rpg, int choices, dial_t dial);
	void display_question(rpg_t *rpg, sfText *text, dial_t dial, int nbr);

	//DESTROY
	void free_npc(npc_t *npc);

#endif
