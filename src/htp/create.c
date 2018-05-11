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
	htp->sprite[1] = htp_sprite("./img/fairy.png", (V2F){WIDTH / 2.1, HEIGHT
	/ 2}, (V2F){SIZE_F_X / 2, SIZE_F_Y / 2}, (IR){0,0, SIZE_F_X, SIZE_F_Y});
	htp->sprite[2] = htp_sprite(TXTRE_OSTRICH, (V2F){WIDTH / 4, HEIGHT
	/ 4}, (V2F){108 / 2, 120 / 2}, (IR){0, 150, 108, 120});
	htp->sprite[3] = htp_sprite(TXTRE_STONE_OGRE, (V2F){WIDTH / 1.5, HEIGHT
	/ 1.5}, (V2F){140 / 2, 155 / 2}, (IR){0, 150, 140, 155});
	htp->sprite[4] = htp_sprite(TXTRE_LYCANTHROPE, (V2F){WIDTH / 3, HEIGHT
	/ 1.5}, (V2F){180 / 2, 175 / 2}, (IR){0, 220, 180, 175});
	htp->sprite[5] = htp_sprite(TXTRE_VILLAGER, (V2F){WIDTH / 4.5, HEIGHT
	/ 1.5}, (V2F){70 / 2, 100 / 2}, (IR){0, 0, 70, 100});
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
