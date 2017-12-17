/*
** EPITECH PROJECT, 2017
** get_end_room.c
** File description:
** get the end room
*/

#include <stdlib.h>
#include "room.h"
#include "list.h"

room_t *get_end_room(list_t *list)
{
	list_t *tmp = list;
	room_t *room;

	while (tmp) {
		room = tmp->data;
		if (room->is_special == 2)
			return (room);
		tmp = tmp->next;
	}
	return (NULL);
}
