/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** structs for graphical
*/

#ifndef _MS_H_
	#define _MS_H_

	typedef struct stick_s {
		int lines;
		int len;
		int max;
		int turn;
		int in_l;
		int in_m;
		int ai_l;
		int ai_m;
		int *line;
	} stick_t;

	typedef struct match_s {
		float scale;
		int mode;
		sfSprite *smatch;
		sfTexture *tmatch;
		sfSprite *sred_match;
		int x;
		int y;
		sfSprite *sarrow;
		sfTexture *tarrow;
		sfClock *clock;
		sfTime time;
		float seconds;
	} match_t;

	stick_t *fill_stick(void);
	match_t *init_match(void);
	void ai_play(match_t *match, stick_t *stick);
	void match_ai(stick_t *stick, match_t *match);
	void play_match(rpg_t *rpg, match_t *match, stick_t *stick);
	void player_play(match_t *match, stick_t *stick);
	void match_input(match_t *match, stick_t *stick);
	void calcul_match(rpg_t *rpg, match_t *match, stick_t *stick);
	void draw_match(rpg_t *rpg, match_t *match, stick_t *stick,
	sfVector2f pos);
	void matchstick_gestion(rpg_t *rpg, match_t *match);
	void free_match(match_t *match, stick_t *stick);
	int my_end(stick_t *stick);

#endif
