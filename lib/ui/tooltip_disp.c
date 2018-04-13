/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** tooltip disp
*/

#include "my_uilib.h"

void tooltip_animation_tick(button_t *button)
{
	tooltip_t *tooltip = button->tooltip;
	sfColor color = sfRectangleShape_getFillColor(tooltip->rect);
	sfColor txtcolor = sfText_getColor(tooltip->text->text);

	if (tooltip->state == 1 && color.a < 180) {
		if (txtcolor.a < 255)
			txtcolor.a += 10;
		color.a += 10;
		sfText_setColor(tooltip->text->text, txtcolor);
		sfRectangleShape_setFillColor(tooltip->rect, color);
	} else if (tooltip->state == 2 && color.a > 0) {
		if (txtcolor.a > 75)
			txtcolor.a -= 10;
		color.a -= 10;
		sfText_setColor(tooltip->text->text, txtcolor);
		sfRectangleShape_setFillColor(tooltip->rect, color);
	} else if (tooltip->state == 2){
		tooltip->state = 0;
	}
}

void	disp_tooltip(sfRenderWindow *wd, button_t *button)
{
	tooltip_t *tooltip = button->tooltip;
	sfVector2f pos = get_button_position(button);
	sfVector2f size = get_button_size(button);
	int fontsize = sfText_getCharacterSize(tooltip->text->text);
	sfVector2f rectpos = {pos.x-4, pos.y+size.y+4};
	sfVector2f textpos = {rectpos.x+5, rectpos.y-fontsize*0.11};

	tooltip_animation_tick(button);
	if (tooltip == NULL || tooltip->state == 0)
		return;
	sfRectangleShape_setPosition(tooltip->rect, rectpos);
	sfRenderWindow_drawRectangleShape(wd, tooltip->rect, NULL);
	set_text_position(tooltip->text, textpos);
	disp_text(wd, tooltip->text);
}

void	disp_tooltips(sfRenderWindow *wd, button_t *buttons, int nb)
{
	button_t *button = NULL;
	for (int i = 0; buttons != NULL && i < nb; i++) {
		button = &buttons[i];
		if (button != NULL && button->tooltip != NULL)
			disp_tooltip(wd, button);
	}
}
