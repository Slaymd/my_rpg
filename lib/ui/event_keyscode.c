/*
** EPITECH PROJECT, 2018
** my_world_2017
** File description:
** keyboard handling
*/

#include "uilib.h"

char get_char_from_keycode(sfKeyCode key)
{
	long keys[] = {sfKeyA,'A',sfKeyB,'B',sfKeyC,'C',sfKeyD,'D',
		sfKeyE,'E',sfKeyF,'F',sfKeyG,'G',sfKeyH,'H',sfKeyI,'I',
		sfKeyJ,'J',sfKeyK,'K',sfKeyL,'L',sfKeyM,'M',sfKeyN,'N',
		sfKeyO,'O',sfKeyP,'P',sfKeyQ,'Q',sfKeyR,'R',sfKeyS,'S',
		sfKeyT,'T',sfKeyU,'U',sfKeyV,'V',sfKeyW,'W',sfKeyX,'X',
		sfKeyY,'Y',sfKeyZ,'Z',sfKeyNum1,'1',sfKeyNum2,'2',
		sfKeyNum3,'3',sfKeyNum4,'4',sfKeyNum5,'5',sfKeyNum6,'6',
		sfKeyNum7,'7',sfKeyNum8,'8',sfKeyNum9,'9',sfKeyNum0,'0',
		sfKeyBack,-2,-1,'\0'};

	for (int i = 0; keys[i] != -1; i += 2) {
		if (keys[i] == key)
			return (keys[i+1]);
	}
	return ('\0');
}
