/*
** EPITECH PROJECT, 2017
** character
** File description:
** conf
*/

#include "rpg.h"

char	*my_str_cat(char *str1, char *str2)
{
	int len = my_strlen(str1) + my_strlen(str2) + 1;
	char *dest = malloc(sizeof(char) * len);
	int i = 0;
	int j = 0;

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

int str_cmp(char const *s1, char const *s2)
{
	int cnt = 0;

	while (s1[cnt] != '\0' && s2[cnt] != '\0' && s1[cnt] == s2[cnt])
		cnt ++;
	return (s1[cnt] - s2[cnt]);
}

int tab_len(char **tab)
{
	int i = 0;

	while (tab[i])
		i++;
	return (i);
}

void free_tab(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}

int is_num(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if ('0' > str[i] || str[i] > '9')
			return (0);
	return (1);
}
