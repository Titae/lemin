/*
** EPITECH PROJECT, 2017
** update_room.c
** File description:
** Update a room
*/

#include <stdlib.h>
#include "room.h"

void update_room(room_t *this)
{
	for (int i = 0; i < this->nb_ant; i++)
		this->ants[i]->can_move = 1;
}
