/*
** EPITECH PROJECT, 2017
** send_ant.c
** File description:
** Function that send an ant to another
*/

#include <stdlib.h>
#include "room.h"

void send_ant(room_t *this, room_t *room)
{
	this->nb_ant--;
	this->ants[this->nb_ant]->can_move = 0;
	room->ants[room->nb_ant] = this->ants[this->nb_ant];
	this->ants[this->nb_ant] = NULL;
	room->nb_ant++;
}
