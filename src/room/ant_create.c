/*
** EPITECH PROJECT, 2017
** ant_create.c
** File description:
** Create an ant
*/

#include <stdlib.h>
#include "room.h"

ant_t *ant_create(int id)
{
	ant_t *ant = malloc(sizeof(ant_t));

	ant->id = id;
	ant->can_move = 1;
	return (ant);
}
