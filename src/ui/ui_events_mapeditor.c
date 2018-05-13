/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map editor events
*/

#include "../../include/rpg.h"

void click_save_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	textbox_t *seedtb = (textbox_t*)list_get_fromtag(rpg->scene->textboxes,
		"seed");
	char *seed = get_text_string(seedtb->text);

	if (my_strlen(seed) == 0)
		seedtb->entry_state = ERROR;
	else {
		free_scene(rpg->scene);
		rpg->scene = NULL;
		rpg->state = 3;
		free_map(rpg->map);
		rpg->map = init_map(NULL, my_getnbr(seed));
		rpg->map = generate_map(my_getnbr(seed));
	}
}

void regen_map_from_ui(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	textbox_t *seedtb = (textbox_t*)list_get_fromtag(rpg->scene->textboxes,
		"seed");
	int seed = 0;

	if (my_strlen(get_text_string(seedtb->text)) == 0)
		return;
	seed = my_getnbr(get_text_string(seedtb->text));
	if (seed == rpg->map->seed)
		return;
	free_map(rpg->map);
	rpg->map = init_map(NULL, seed);
	rpg->map = generate_map(seed);
}

void swap_state_maptravelling(rpg_t *rpg)
{
	if (rpg->state == 2 && rpg->map->center.x <= DEFAULT_POS_X)
		rpg->state = 1;
	else if (rpg->state == 1 && rpg->map->center.x >=
		DEFAULT_POS_X+TILES_PER_CHUNKS)
		rpg->state = 2;
}

void click_vsync_button(void *data)
{
	rpg_t *rpg = (rpg_t*)data;
	button_t *vsync = (button_t*)list_get_fromtag(rpg->scene->buttons,\
	"vsync");

	if (vsync->state == 0)
		return;
	set_v_sync(rpg);
}
