/*
** EPITECH PROJECT, 2017
** core_lemin.c
** File description:
** core of the lemin programme
*/

#include <stdlib.h>
#include "my_printf.h"
#include "list.h"
#include "room.h"
#include "parser.h"
#include "path.h"

int core_lemin(list_t *rooms, list_t *paths)
{
	room_t *start = get_start_room(rooms);
	room_t *end = get_end_room(rooms);
	int nb_ant = start->nb_ant;
	list_t *tmp = NULL;

	if (!start || !end)
		return (1);
	while (start->nb_ant != 0 || end->nb_ant != nb_ant) {
		tmp = paths;
		while (tmp) {
			((path_t *)tmp->data)->update((path_t *)tmp->data);
			tmp = tmp->next;
		}
		my_printf("\n");
		tmp = rooms;
		while (tmp) {
			((room_t *)tmp->data)->update((room_t *)tmp->data);
			tmp = tmp->next;
		}
	}
	return (0);
}
