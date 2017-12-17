/*
** EPITECH PROJECT, 2017
** create_path.c
** File description:
** Create a path
*/

#include <stdlib.h>
#include "path.h"
#include "list.h"
#include "room.h"

path_t *create_path(list_t *rooms)
{
	path_t *path = malloc(sizeof(path_t));

	if (path == NULL)
		return (NULL);
	path->rooms = rooms;
	path->size = list_size(rooms);
	path->update = &update_path;
	return (path);
}
