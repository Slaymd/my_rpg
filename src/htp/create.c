/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** time
*/

#include "rpg.h"

sprite_tab_t htp_sprite(char *path, V2F pos, V2F origin, sfIntRect rect)
{
	sprite_tab_t new;

	new.sprite = sfSprite_create();
	new.texture = sfTexture_createFromFile(path, NULL);
	sfSprite_setTexture(new.sprite, new.texture, sfTrue);
	sfSprite_setPosition(new.sprite, pos);
	sfSprite_setScale(new.sprite, (V2F){ZOOM, ZOOM});
	sfSprite_setOrigin(new.sprite, origin);
	sfSprite_setTextureRect(new.sprite, rect);
	return (new);
}

void init_htp_sprites(htp_t *htp)
{
	htp->sprite[0] = htp_sprite("./img/sacha.png", (V2F){WIDTH / 2, HEIGHT
	/ 2}, (V2F){SIZE_C_X / 2, SIZE_C_Y}, (IR){0,0, SIZE_C_X, SIZE_C_Y});
	htp->sprite[1] = htp_sprite("./img/sacha.png", (V2F){WIDTH / 3, HEIGHT
	/ 3}, (V2F){SIZE_C_X / 2, SIZE_C_Y}, (IR){0,0, SIZE_C_X, SIZE_C_Y});
	htp->sprite[2] = htp_sprite("./img/sacha.png", (V2F){WIDTH / 4, HEIGHT
	/ 4}, (V2F){SIZE_C_X / 2, SIZE_C_Y}, (IR){0,0, SIZE_C_X, SIZE_C_Y});
	htp->sprite[3] = htp_sprite("./img/sacha.png", (V2F){WIDTH / 1.5, HEIGHT
	/ 1.5}, (V2F){SIZE_C_X / 2, SIZE_C_Y}, (IR){0,0, SIZE_C_X, SIZE_C_Y});
	htp->sprite[4] = htp_sprite("./img/sacha.png", (V2F){WIDTH / 3, HEIGHT
	/ 2}, (V2F){SIZE_C_X / 2, SIZE_C_Y}, (IR){0,0, SIZE_C_X, SIZE_C_Y});
}

htp_t *create_htp(void)
{
	htp_t *htp = malloc(sizeof(htp_t));

	htp->state = 0;
	init_htp_sprites(htp);
	htp->font = sfFont_createFromFile(FONT_UBUREG);
	htp->text = sfText_create();
	sfText_setFont(htp->text, htp->font);
	sfText_setColor(htp->text, sfBlack);
	sfText_setPosition(htp->text, (V2F){WIDTH / 2, HEIGHT / 8});
	sfText_setCharacterSize(htp->text, 30);
	htp->clock = sfClock_create();
	htp->time = sfClock_getElapsedTime(htp->clock);
	htp->seconds = 0;
	return (htp);
}
