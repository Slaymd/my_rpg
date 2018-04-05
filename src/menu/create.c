/*
** EPITECH PROJECT, 2018
** rafou
** File description:
** menu
*/

#include "rpg.h"

scene_t *create_menu_bg(char *path)
{
	scene_t *scene = malloc(sizeof(scene_t));

	scene->texture = sfTexture_createFromFile(path, NULL);
	scene->sprite = sfSprite_create();
	sfSprite_setTexture(scene->sprite, scene->texture, sfTrue);
	return (scene);
}

button_t *create_menu_button(char *path, sfVector2f pos, sfVector2f size, button_action_t func)
{
	button_t *button = malloc(sizeof(button_t));

	button->rect = sfRectangleShape_create();
	button->texture = sfTexture_createFromFile(path, NULL);
	button->sprite = sfSprite_create();
	sfSprite_setTexture(button->sprite, button->texture, sfTrue);
	sfSprite_setPosition(button->sprite, pos);
	sfSprite_setTextureRect(button->sprite,
	(sfIntRect){0, 0, size.x, size.y});
	sfRectangleShape_setPosition(button->rect, pos);
	sfRectangleShape_setSize(button->rect, size);
	sfRectangleShape_setFillColor(button->rect, sfRed);
	button->callback = func;
	return (button);
}

text_t *create_menu_text(char *info, int size, sfVector2f pos, sfColor color)
{
	text_t *text = malloc(sizeof(text_t));
	char **str = str_to_array(info, ' ');

	text->text = sfText_create();
	text->font = sfFont_createFromFile(str[1]);
	sfText_setFont(text->text, text->font);
	sfText_setString(text->text, str[0]);
	sfText_setCharacterSize(text->text, size);
	sfText_setPosition(text->text, pos);
	sfText_setColor(text->text, color);
	free_str_array(str);
	return (text);
}

menu_t *create_menu(void)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (!menu)
		return (NULL);
	menu->state = 0;
	menu->scene = malloc(sizeof(scene_t *) * 2);
	if (!menu->scene)
		return (NULL);
	menu->scene[0] = create_start_scene();
	menu->scene[1] = NULL;
	return (menu);
}
