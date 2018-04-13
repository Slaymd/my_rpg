/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** my_uilib
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../list/list.h"

#define DEFAULT_FONT "assets/fonts/UbuntuMono-R.ttf"

typedef enum
{
	FLAT=0,
	IMAGE=1,
}button_type_e;

typedef enum
{
	ALL=0,
	ONLY_LET=1,
	ONLY_NUM=2,
}textbox_entry_type_e;

typedef enum
{
	NORMAL=0,
	SUCCESS=1,
	ERROR=2,
}textbox_entry_state_e;

typedef struct text_s {
	int		fontsize;
	sfFont	*font;
	sfText	*text;
}text_t;

typedef struct button_state_s {
	int id;
	sfColor	fill_color;
	sfColor	outline_color;
	char		*text;
	char		*sprite_path;
	void (*action)(void*);
	void *params;
}bt_state_t;

typedef struct tooltip_s {
	text_t			*text;
	sfRectangleShape	*rect;
	int				state;
}tooltip_t;

typedef struct button_s {
	button_type_e type;
	sfRectangleShape *rect;
	text_t *text;
	sfSprite *sprite;
	tooltip_t *tooltip;
	int state;
	int nb_states;
	struct button_state_s *states;
	void (*action)(void*);
	void *params;
}button_t;

typedef struct textbox_s {
	sfRectangleShape 		*rect;
	struct text_s			*text;
	sfColor				outl_color;
	int 					state;
	textbox_entry_type_e	type;
	textbox_entry_state_e	entry_state;
}textbox_t;

typedef struct scene_s {
	list_t *buttons;
	list_t *textboxes;
	list_t *labels;
}scene_t;

//Tooltips create
tooltip_t	*create_tooltip(char *str, int size);

//Tooltips disp
void	disp_tooltips(sfRenderWindow *wd, list_t *buttons);

//Button create
button_t	*create_void_button();
button_t	*create_flat_button(sfIntRect pos, sfColor fill,
	sfColor outl, char *str);
//Button disp
void	disp_button(sfRenderWindow *wd, button_t *button);
void	disp_buttons(sfRenderWindow *wd, list_t *buttons);

//Button position/size tools
void set_button_size(button_t *button, sfVector2f size);
void set_button_position(button_t *button, sfVector2f pos);
sfVector2f get_button_position(button_t *button);
sfVector2f get_button_size(button_t *button);

//Buttons events
int	click_on_buttons(sfEvent event, list_t *buttons);
int	hover_on_buttons(sfEvent event, list_t *buttons);
//get fill/outline color
sfColor get_button_fill_color(button_t *button);
sfColor get_button_outline_color(button_t *button);
//set button color
void	set_button_color(button_t *button, sfColor fill, sfColor);
//set outline thickness:
void	set_button_outline_thickness(button_t *button, int);
//states
bt_state_t *init_bt_states(button_t *but, int nbstates);
int	set_button_state(button_t *button, int state);
void	switch_button_state(void *ptr);
//Check pos:
int	check_pos_in_button(button_t *button, sfVector2f pos);
//set/rem hover design
int	set_button_hover_design(button_t *button);
int	rem_button_hover_design(button_t *button);
//free button: free all instance of button_t
void	free_button(button_t *button);
//Create
text_t	*create_text(sfVector2f pos, char *, int, sfColor);
//Customization
void	set_text_string(text_t *text, char *str);
char	*get_text_string(text_t *text);
void	set_text_font(text_t *text, char *fontpath);
void	set_text_size(text_t *text, int size);
void set_text_position(text_t *text, sfVector2f pos);
//Disp
void	disp_text(sfRenderWindow *wd, text_t *text);
void	disp_texts(sfRenderWindow *wd, list_t *texts);
//Destroy
void free_text(text_t *text);
//Create
textbox_t	*create_textbox(sfIntRect rect, sfColor fill, sfColor);
//position/size tools
void set_textbox_size(textbox_t *textbox, sfVector2f size);
void set_textbox_position(textbox_t *textbox, sfVector2f pos);
sfVector2f get_textbox_position(textbox_t *textbox);
sfVector2f get_textbox_size(textbox_t *textbox);
//textbox colortools
void	set_textbox_color(textbox_t *textbox, sfColor fill, sfColor);
void	set_textbox_outline_thickness(textbox_t *textbox, int);
sfColor get_textbox_fill_color(textbox_t *textbox);
sfColor get_textbox_outline_color(textbox_t *textbox);
//effets
int	set_textbox_hover_design(textbox_t *textbox);
int	rem_textbox_hover_design(textbox_t *textbox);
//Events
int	check_pos_in_textbox(textbox_t *textbox, sfVector2f pos);
int	click_on_textboxes(sfEvent event, list_t *textboxes);
int	add_char_in_textboxes(list_t *textboxes, char c);
//Destroy
void	free_textbox(textbox_t *textbox);
//Disps
void	disp_textbox(sfRenderWindow *wd, textbox_t *textbox);
void	disp_textboxes(sfRenderWindow *wd, list_t *textboxes);

//****[EVENTS]****
//Keycode to char
char get_char_from_keycode(sfKeyCode key);

//****[SCENES]****
//Create
scene_t *create_scene(void);
//Events
int	scene_events_handler(sfRenderWindow *wd, sfEvent, scene_t *);
//Destroy
void	free_scene(scene_t *scene);
//Disp
int	disp_scene(sfRenderWindow *wd, scene_t *scene);
