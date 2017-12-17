/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** Init function of the lemin project
*/

#include <stdlib.h>
#include "my_printf.h"
#include "string.h"
#include "get_next_line.h"
#include "list.h"
#include "room.h"
#include "parser.h"
#include "path.h"

static char *check_in_list(list_t *link, room_t *room_from, char **rooms_name)
{
	char *res = my_dup("");
	room_t *room = NULL;

	while (link) {
		room = link->data;
		if (pos_str_in_array(rooms_name, room->name) == -1)
			my_sprintf(&res, "%s-%s\n", room_from->name,
				   room->name);
		link = link->next;
	}
	return (res);
}

static char *get_links(list_t *rooms)
{
	char *res = my_dup("");
	list_t *tmp = rooms;
	list_t *link = NULL;
	char *rooms_name[list_size(rooms)];
	int i = 0;

	for (int j = 0; j < list_size(rooms); j++)
		rooms_name[j] = NULL;
	while (tmp) {
		link = ((room_t *)tmp->data)->links;
		my_sprintf(&res, check_in_list(link, (room_t *)tmp->data,
					       rooms_name));
		rooms_name[i++] = ((room_t *)tmp->data)->name;
		tmp = tmp->next;
	}
	return (res);
}

static char *get_rooms(list_t *rooms)
{
	char *res = my_dup("");
	list_t *tmp = rooms;
	room_t *room = NULL;

	while (tmp) {
		room = tmp->data;
		if (room->is_special == 1)
			my_sprintf(&res, "##start\n");
		if (room->is_special == 2)
			my_sprintf(&res, "##end\n");
		my_sprintf(&res, "%s %d %d\n", room->name, room->pos[0],
			   room->pos[1]);
		tmp = tmp->next;
	}
	return (res);
}

static int print_init(list_t *rooms)
{
	char *res = my_dup("");
	list_t *tmp = rooms;
	room_t *room = NULL;
	room_t *start = get_start_room(rooms);

	if (start == NULL)
		return (1);
	my_sprintf(&res, "#number_of_ants\n%d\n",
		   start->nb_ant);
	my_sprintf(&res, "#rooms\n");
	my_sprintf(&res, get_rooms(rooms));
	my_sprintf(&res, "#tunnels\n");
	my_sprintf(&res, get_links(rooms));
	my_sprintf(&res, "#moves\n");
	my_printf(res);
	free(res);
	return (0);
}

int init_lemin(list_t **rooms, list_t **paths)
{
	char **config = get_file_in_line(0, '\n');

	*rooms = config_to_list(config);
	if (*rooms == NULL)
		return (1);
	if (print_init(*rooms))
		return (1);
	get_all_path(paths, NULL, get_start_room(*rooms));
	if (*paths == NULL)
		return (1);
	sort_path(paths);
	return (0);
}
