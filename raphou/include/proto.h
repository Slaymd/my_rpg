/*
** EPITECH PROJECT, 2017
** match
** File description:
** proto
*/

#ifndef _PROTO_H_
	#define _PROTO_H_

	#include <SFML/Graphics.h>
	#include <SFML/Audio.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include "struct.h"

	#define SIZE_X 750
	#define SIZE_Y 750
	#define SIZE_IMG_X 1920
	#define SIZE_IMG_Y 1080

	void event_gestion(window_t *window);

	//CREATE
	character_t *init_character(void);
	void set_window(window_t *window);
	window_t *init_window(void);

	//DISPLAY
	void display_map(window_t *window);
	void display_character(window_t *window, character_t *character);

	//DESTROY
	void my_free(window_t *window, character_t *character);

	//MOVE
	void move_map(window_t *window);
	void move_character(character_t *character);
#endif
