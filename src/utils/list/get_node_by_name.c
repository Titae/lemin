/*
** EPITECH PROJECT, 2017
** get_node_by_name
** File description:
** get the node by the name of the env var
*/

#include <stdlib.h>
#include "list.h"
#include "room.h"
#include "string.h"

list_t *get_node_by_name(list_t **begin, char *name)
{
        list_t *ptrPre = *begin;
        list_t *tmp = ptrPre;
	room_t *room;

	while (tmp != NULL) {
		room = tmp->data;
		if (compare(room->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
        return (NULL);
}
