/*
** EPITECH PROJECT, 2017
** btree_create_node.c
** File description:
** btree create node
*/

#include <stdlib.h>
#include "btree.h"
#include "string.h"
#include "room.h"
#include "list.h"

room_t *room_create(char *name, int is_special, int x, int y)
{
	room_t *node;

	node = malloc(sizeof(room_t));
	node->nb_ant = 0;
	node->name = name;
	node->is_special = is_special;
	node->pos = malloc(sizeof(int) * 3);
	node->pos[0] = x;
	node->pos[1] = y;
	node->links = NULL;
	if (is_special == 0)
		node->ants = malloc(sizeof(ant_t *));
	node->populate = &populate_room;
	node->send_ant = &send_ant;
	node->update = &update_room;
	return (node);
}
