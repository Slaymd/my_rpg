/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** cycle
*/

#include "rpg.h"

char *my_strcat_no_free(char *str1, char *str2)
{
	int len = my_strlen(str1) + my_strlen(str2) + 1;
	char *dest = malloc(sizeof(char) * len);
	int i = 0;
	int j = 0;

	if (!dest)
		return (NULL);
	while (str1[i] != '\0') {
		dest[i] = str1[i];
		i ++;
	}
	while (str2[j] != '\0') {
		dest[i] = str2[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	return (dest);
}

char *my_strcat_free(char *str1, char *str2)
{
	int len = my_strlen(str1) + my_strlen(str2) + 1;
	char *dest = malloc(sizeof(char) * len);
	int i = 0;
	int j = 0;

	if (!dest)
		return (NULL);
	while (str1[i] != '\0') {
		dest[i] = str1[i];
		i ++;
	}
	while (str2[j] != '\0') {
		dest[i] = str2[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
	free(str1);
	return (dest);
}

float clock_rotation(cycle_t *cycle)
{
	float rotation = 90;

	rotation += (float)cycle->h / 24.0 * 360.0;
	rotation += (float)cycle->m / 60.0 / 24 * 360.0;
	return (rotation);
}

void refresh_time(cycle_t *cycle)
{
	cycle->time = sfClock_getElapsedTime(cycle->clock);
	cycle->seconds = cycle->time.microseconds / 1000000.0;
	(cycle->seconds >= 0.00001) ? cycle->m ++ : 0;
	if (cycle->m >= 60) {
		cycle->m = 0;
		cycle->h++;
	} if (cycle->h >= 24) {
		cycle->h = 0;
	} if (cycle->seconds >= 0.00001) {
		run_cycle(cycle);
		sfSprite_setRotation(cycle->s_clock, clock_rotation(cycle));
		sfClock_restart(cycle->clock);
	}
}

void display_time(cycle_t *cycle, sfRenderWindow *window)
{
	char *str;
	char *tmp = "0";
	char *h;
	char *m = my_itoa(cycle->m);

	sfRenderWindow_drawSprite(window, cycle->s_clock, NULL);
	if (cycle->h < 10) {
		h = my_itoa(cycle->h);
		str = my_strcat_no_free(tmp, h);
		free(h);
	} else
		str = my_itoa(cycle->h);
	str = my_strcat_free(str, ":");
	if (cycle->m < 10)
		str = my_strcat_free(str, tmp);
	str = my_strcat_free(str, m);
	sfText_setString(cycle->text, str);
	sfRenderWindow_drawText(window, cycle->text, NULL);
	free(str);
	free(m);
}
