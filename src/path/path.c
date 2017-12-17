/*
** EPITECH PROJECT, 2017
** path.c
** File description:
** path.c
*/

#include <stdlib.h>
#include "list.h"
#include "room.h"
#include "path.h"

void get_all_path(list_t **path_list, list_t *list_room, room_t *room_actual)
{
	list_t *tmp = NULL;
	room_t *room_tmp = NULL;

	if (room_actual == NULL)
		return;
	if (room_actual->is_special == 2) {
		put_in_list(&list_room, room_actual);
		put_in_list(path_list, create_path(list_room));
	} else {
		if (get_node_by_name(&list_room, room_actual->name) != NULL)
			return;
		put_in_list(&list_room, room_actual);
		tmp = room_actual->links;
		while (tmp) {
			room_tmp = tmp->data;
			get_all_path(path_list, list_copy(list_room), room_tmp);
			tmp = tmp->next;
		}
	}
}
