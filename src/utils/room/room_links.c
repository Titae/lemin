/*
** EPITECH PROJECT, 2017
** room_links
** File description:
** create room links
*/

#include <stdlib.h>
#include "room.h"
#include "list.h"

static void handle_dup_links(room_t *room1, room_t *room2, list_t *room_list)
{
	if (get_node_by_name(&(room1->links), room2->name) == NULL) {
		put_in_list(&(room1->links), room2);
		put_in_list(&(room2->links), room1);
	}
}

void create_link(char *name_room1, char *name_room2, list_t *room_list)
{
	list_t *list_room1 = get_node_by_name(&room_list, name_room1);
	list_t *list_room2 = get_node_by_name(&room_list, name_room2);
	room_t *room1;
	room_t *room2;

	if (list_room1 && list_room2) {
		room1 = list_room1->data;
		room2 = list_room2->data;
		if (room1 != room2) {
			handle_dup_links(room1, room2, room_list);
		}
	}
}
