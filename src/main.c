/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main of the lemin project
*/

#include <stdlib.h>
#include "list.h"
#include "lemin.h"
#include "my_printf.h"

int main(void)
{
	list_t *rooms = NULL;
	list_t *paths = NULL;

	if (init_lemin(&rooms, &paths)) {
		my_dprintf(2, "error in the init\n");
		return (84);
	}
	if (core_lemin(rooms, paths)) {
		my_dprintf(2, "error in the core\n");
		return (84);
	}
	return (0);
}
