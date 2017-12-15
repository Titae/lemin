/*
** EPITECH PROJECT, 2017
** room.h
** File description:
** rooms
*/

#ifndef ROOM_H_
#define ROOM_H_

typedef struct room room_t;

struct room
{
 	char *name;
	int nb_ant;
	int is_start;
	int *pos;
	list_t *links;
};

#endif
