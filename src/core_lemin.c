/*
** EPITECH PROJECT, 2017
** core_lemin.c
** File description:
** core of the lemin programme
*/

#include <stdlib.h>
#include "my_printf.h"
#include "list.h"
#include "room.h"
#include "get_next_line.h"
#include "parser.h"
#include "path.h"

int main(int argc, char **argv)
{
	list_t *room_list = NULL;
	list_t *tmp;
	list_t *tmp2;
	list_t *path = NULL;
	char **file = get_file_in_line(0, '\n');
	room_t *room;

	
	room_list = config_to_list(file);
	get_all_path(&path, NULL, get_start_room(room_list));
	tmp = path;
	while (tmp) {
		tmp2 = tmp->data;
		//my_printf("Room : %s speciality : %d nb ants : %d\n", room->name, room->is_special, room->nb_ant);
		//tmp2 = room->links;
		while (tmp2) {
			room = tmp2->data;
			my_printf("room : %s\n", room->name);
			tmp2 = tmp2->next;
		}
		my_printf("-----------------------------\n");
		tmp = tmp->next;
	}
	return (0);
}
