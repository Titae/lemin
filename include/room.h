/*
** EPITECH PROJECT, 2017
** room.h
** File description:
** rooms
*/

#ifndef ROOM_H_
#define ROOM_H_

typedef struct list list_t;
typedef struct room room_t;

struct room
{
	char *name;
	int nb_ant;
	int is_special;
	int *pos;
	int ant_can_move;
	list_t *links;
};

room_t *get_start_room(list_t *list);
room_t *room_create(char *name, int is_special, int x, int y);
void create_link(char *name_room1, char *name_room2, list_t *room_list);

#endif
