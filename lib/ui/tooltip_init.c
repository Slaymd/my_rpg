/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** tooltips init
*/

#include "uilib.h"
int	my_strlen(char *);

tooltip_t	*create_tooltip(char *str, int size)
{
	tooltip_t	*tooltip = (tooltip_t*)malloc(sizeof(tooltip_t));
	sfColor white = {255, 255, 255, 75};

	if (tooltip == NULL)
		return (NULL);
	tooltip->text = create_text((sfVector2f){0, 0}, str, size, white);
	tooltip->state = 0;
	tooltip->rect = sfRectangleShape_create();
	if (tooltip->rect == NULL) {
		free(tooltip);
		return (NULL);
	}
	sfRectangleShape_setSize(tooltip->rect, (sfVector2f){
		size*(my_strlen(str)+1)/2, size+size*0.11*2});
	sfRectangleShape_setFillColor(tooltip->rect, sfTransparent);
	return (tooltip);
}
