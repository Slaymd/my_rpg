/*
** EPITECH PROJECT, 2017
** matches
** File description:
** structs for graphical
*/

#ifndef _CHARACTER_H_
	#define _CHARACTER_H_

	#define SIZE_C_X 68
	#define SIZE_C_Y 72

	#define CHAR_DEFAULT_SKIN "assets/character/sacha-red.png"

	typedef struct character_s character_t;
	typedef struct main_stat_s main_stat_t;

	struct main_stat_s {
		float attack;
		float hp;
		float mana;
		float defense;
		float hp_r;
		float mana_r;
		float hp_max;
		float mana_max;
		float xp;
		int level;
		sfClock *clock;
		sfTime time;
		float seconds;
	};

	struct character_s {
		sfSprite *sprite;
		sfTexture *texture;
		sfIntRect rect;
		sfClock *clock;
		sfTime time;
		float seconds;
		int inter;
		int speed;
		sfVector2f pos_screen;
		pos_t pos;
		main_stat_t *stat;
		sfRectangleShape *hp_bar;
		sfRectangleShape *mana_bar;
	};

	//STAT
	void display_character_bar(rpg_t *, float, float max,
	sfRectangleShape *);
	int config_character_stat(main_stat_t *stat);
	void character_regen(character_t *);
	void character_stat(character_t *);
	char	*my_str_cat(char *str1, char *str2);
	int str_cmp(char const *s1, char const *s2);
	int tab_len(char **tab);
	void free_tab(char **tab);
	int is_num(char *str);

#endif
