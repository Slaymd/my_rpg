/*
** EPITECH PROJECT, 2017
** character
** File description:
** conf
*/

#include "rpg.h"

char **str_to_tab(char *str, char c)
{
	int i = 1;
	int mal = 0;
	char **dest;

	for (int j = 0; str[j] != '\0'; j++)
		i = str[j] == c ? i + 1 : i;
	dest = malloc(sizeof(char *) * (i + 1));
	for (int j = 0, k = 0; j < i; j ++, k ++, mal = 0) {
		for (; str[k] != c && str[k] != '\0'; k ++, mal ++);
		dest[j] = malloc(sizeof(char) * (mal + 1));
	}
	for (int m = 0, k = 0, j = 0; k < i; k ++, j++, m = 0) {
		for (; str[j] != c && str[j] != '\0'; m++, j++)
			dest[k][m] = str[j];
		dest[k][m] = '\0';
	}
	dest[i] = NULL;
	return (dest);
}

char *my_read(char *path)
{
	char *map = malloc(sizeof(char));
	char *buffer = malloc(sizeof(char) * 4096);
	int fd = open(path, O_RDONLY);
	int rd;

	rd = read(fd, buffer, 4094);
	map[0] = '\0';
	while (rd > 0) {
		buffer[rd] = '\0';
		map = my_strcat(map, buffer);
		if (!map)
			exit(84);
		rd = read(fd, buffer, 4094);
	}
	close(fd);
	free(buffer);
	return (map);
}

char *statistik[] = {
	"attack",
	"defense",
	"hp",
	"mana",
	"hp_r",
	"mana_r",
	"hp_max",
	"mana_max",
	"xp",
	"level",
};

int *verif_conf(void)
{
	char *file = my_read("conf/character.txt");
	char **lines = str_to_tab(file, '\n');
	int *stats = malloc(sizeof(int) * 10);
	char **stat;

	if (!stats || tab_len(lines) != 11)
		return (NULL);
	for (int i = 0; i < 10; i++) {
		stat = str_to_tab(lines[i], ' ');
		if (tab_len(stat) != 3 || is_num(stat[2]) == 0 ||
		str_cmp(stat[1], "=") != 0 ||
		str_cmp(stat[0], statistik[i]) != 0)
			return (NULL);
		stats[i] = my_getnbr(stat[2]);
		free_tab(stat);
	}
	free(file);
	free_tab(lines);
	return (stats);
}

int config_character_stat(main_stat_t *stat)
{
	int *stats = verif_conf();

	if (!stats)
		return (84);
	stat->attack = stats[0];
	stat->defense = stats[1];
	stat->hp = stats[2];
	stat->mana = stats[3];
	stat->hp_r = stats[4];
	stat->mana_r = stats[5];
	stat->hp_max = stats[6];
	stat->mana_max = stats[7];
	stat->xp = stats[8];
	stat->level = stats[9];
	free(stats);
	return (0);
}
