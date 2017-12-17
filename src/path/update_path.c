/*
** EPITECH PROJECT, 2017
** update_path.c
** File description:
** update the path
*/

#include <stdlib.h>
#include "my_printf.h"
#include "string.h"
#include "path.h"
#include "list.h"
#include "room.h"

static char *update_rooms(list_t *room)
{
	room_t *room_tmp = room->data;
	int nb = 0;
	char *res = NULL;
	char *tmp = NULL;

	if (room->next)
		my_sprintf(&tmp, "%s", update_rooms(room->next));
	else
		return (my_dup(""));
	if (room_tmp->nb_ant && room_tmp->ants[room_tmp->nb_ant - 1]->can_move)
		if (!((room_t *)room->next->data)->nb_ant ||
		    ((room_t *)room->next->data)->is_special == 2) {
			my_sprintf(&res, "%sP%d-%s ", tmp,
				   room_tmp->ants[room_tmp->nb_ant - 1]->id,
				   ((room_t *)room->next->data)->name);
			free(tmp);
			room_tmp->send_ant(room_tmp,
					   (room_t *)room->next->data);
			return (res);
		}
	return (tmp);
}

void update_path(path_t *this)
{
	list_t *l_room = this->rooms;
	char *to_print = NULL;
	int i = 0;

	if (l_room == NULL)
		return;
	to_print = update_rooms(l_room);
	my_printf(to_print);
	free(to_print);
}
