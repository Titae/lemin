/*
** EPITECH PROJECT, 2017
** populate_room.c
** File description:
** function that populate the start room
*/

#include <stdlib.h>
#include "room.h"

void populate_room(room_t *this, int nb_ant)
{
	this->nb_ant = nb_ant;
	if (nb_ant == 0)
		return;
	this->ants = malloc(sizeof(ant_t *) * (nb_ant + 1));
	for (int i = 0; i < nb_ant; i++)
		this->ants[nb_ant - 1 - i] = ant_create(i + 1);
}
