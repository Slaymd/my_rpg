/*
** EPITECH PROJECT, 2017
** graphique
** File description:
** struct for the game
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Vector2.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct carac_s {
	sfSprite *sperso;
	sfTexture *tperso;
	sfVector2f posperso;
	sfIntRect rectperso;
}carac_t;

#endif
