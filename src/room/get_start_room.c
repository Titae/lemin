/*
** EPITECH PROJECT, 2017
** get_start_room.c
** File description:
** get_start_room
*/

#include <stdlib.h>
#include "room.h"
#include "list.h"

room_t *get_start_room(list_t *list)
{
	list_t *tmp = list;
	room_t *room;

	while (tmp) {
		room = tmp->data;
		if (room->is_special == 1)
			return (room);
		tmp = tmp->next;
	}
	return (NULL);
}
