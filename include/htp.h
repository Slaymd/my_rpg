/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _HTP_H_
	#define _HTP_H_

	typedef struct htp_s htp_t;
	typedef struct htp_tab_s htp_tab_t;
	typedef struct sprite_tab_s sprite_tab_t;

	struct htp_tab_s {
		// int character;
		// int fairy;
		// int ostich;
		// int ogre;
		// int wolf;
		// int npc;
		int disp[6];
		char *text;
		float time;
	};

	struct sprite_tab_s {
		sfSprite *sprite;
		sfTexture *texture;
	};

	struct htp_s {
		int state;
		sprite_tab_t sprite[6];
		sfFont *font;
		sfText *text;
		sfClock *clock;
		sfTime time;
		float seconds;
	};

	void manage_htp(rpg_t *rpg, htp_t *htp);

	//CREATE
	htp_t *create_htp(void);

	//DESTROY
	void free_htp(htp_t *htp);


#endif
