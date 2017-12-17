/*
** EPITECH PROJECT, 2017
** config_to_list
** File description:
** config_to_list
*/

#include <stdlib.h>
#include "string.h"
#include "list.h"
#include "room.h"
#include "my_printf.h"
#include "parser.h"

static int get_number_args(char **word_array)
{
	int i = 0;

	while (word_array && word_array[i])
		i++;
	return (i);
}

static void handle_create_link(char *str, list_t **list)
{
	char *name1 = my_dup("");
	char *name2 = my_dup("");
	int i = 0;

	while (str && str[i] != '\0' && str[i] != '-') {
		my_sprintf(&name1, "%c", str[i++]);
	}
	if (str[i] == '-')
		i++;
	while (str && str[i] != '\0')
		my_sprintf(&name2, "%c", str[i++]);
	create_link(name1, name2, *list);
}

static void handle_create_room(char **w_a, int is_special, list_t **list, int nb_ant)
{
	int nb = get_number_args(w_a);
	room_t *room;

	if (nb >= 3) {
		room = room_create(w_a[0], is_special,my_atoi(w_a[1]), my_atoi(w_a[2]));
		if (is_special == 1)
			room->populate(room, nb_ant);
		else if (is_special == 2)
			room->ants = malloc(sizeof(ant_t *) * (nb_ant + 1));
		put_in_list(list, room);
	}
}

static int parser(char *line, int is_special, list_t **list, int is_first)
{
	char **w_a = my_str_to_word_array(line);
	int num = get_number_args(w_a);
	static int num_ant;

	if (w_a == NULL || w_a[0] == NULL)
		return (0);
	if (len(w_a[0]) > 2 && w_a[0][0] == '#' && w_a[0][1] == '#') {
		if (compare(w_a[0], "##start") == 0 || compare(w_a[0], "##end") == 0)
			return ((compare(w_a[0], "##start") == 0) ? 1 : 2);
		return (0);
	}
	if (is_first && num == 1) {
		num_ant = my_atoi(w_a[0]);
		return (0);
	}
	if (num == 1)
		handle_create_link(w_a[0], list);
	else
		handle_create_room(w_a, is_special, list, num_ant);
	return (0);
}

list_t *config_to_list(char **file)
{
	int is_special = 0;
	int i = 0;
	int is_first = 1;
	list_t *list = NULL;

	while (file && file[i] != NULL)
	{
		if (len(file[i]) >= 2 && file[i][0] == '#' && file[i][1] != '#') {
			i++;
		} else {
			is_special = parser(file[i++], is_special, &list, is_first);
			is_first = 0;
		}
	}
	return (list);
}
