/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** textboxes disps
*/

#include "my_uilib.h"

void edit_textbox_design_by_state(textbox_t *textbox)
{
	sfColor fill = get_textbox_fill_color(textbox);

	switch (textbox->entry_state) {
	case SUCCESS:
		set_textbox_color(textbox, fill, (sfColor){46,204,113,255});
		break;
	case ERROR:
		set_textbox_color(textbox, fill, (sfColor){231,76,60,255});
		break;
	case NORMAL:
		set_textbox_color(textbox, fill, textbox->outl_color);
		break;
	}
}

void	disp_textbox(sfRenderWindow *wd, textbox_t *textbox)
{
	if (textbox == NULL)
		return;
	edit_textbox_design_by_state(textbox);
	if (textbox->state == 1)
		set_textbox_hover_design(textbox);
	else
		rem_textbox_hover_design(textbox);
	sfRenderWindow_drawRectangleShape(wd, textbox->rect, NULL);
	if (textbox->text != NULL)
		disp_text(wd, textbox->text);
}

void	disp_textboxes(sfRenderWindow *wd, textbox_t *textboxes, int nb)
{
	for (int i = 0; textboxes != NULL && i < nb; i++) {
		disp_textbox(wd, &textboxes[i]);
	}
}
