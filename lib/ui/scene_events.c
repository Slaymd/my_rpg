/*
** EPITECH PROJECT, 2018
** UILib
** File description:
** scene events
*/

#include "my_uilib.h"

int	scene_mouse_evts_hdl(sfRenderWindow *wd, sfEvent e, scene_t *scn)
{
	switch (e.type) {
	case sfEvtMouseButtonPressed:
		click_on_buttons(e,scn->buttons,scn->nb_buttons);
		click_on_textboxes(e,scn->textboxes,scn->nb_textboxes);
		break;
	case sfEvtMouseMoved:
		hover_on_buttons(e,scn->buttons,scn->nb_buttons);
		break;
	default:
		break;
	}
	return (0);
}

int	scene_events_handler(sfRenderWindow *wd, sfEvent e, scene_t *scn)
{
	char keyc = '\0';

	scene_mouse_evts_hdl(wd, e, scn);
	switch (e.type) {
	case sfEvtClosed:
		sfRenderWindow_close(wd);
		break;
	case sfEvtKeyPressed:
		keyc = get_char_from_keycode(e.key.code);
		add_char_in_textboxes(scn->textboxes,scn->nb_textboxes,keyc);
		break;
	default:
		break;
	}
	return (0);
}
