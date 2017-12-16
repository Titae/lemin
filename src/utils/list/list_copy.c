/*
** EPITECH PROJECT, 2017
** list_copy.c
** File description:
** return the copy of a list
*/

#include <stdlib.h>
#include "list.h"

list_t *list_copy(list_t *list)
{
	list_t *new_list = NULL;
	list_t *tmp = list;
	
	if (list == NULL)
		return (NULL);
	new_list = malloc(sizeof(*element));
	new_list->data = list->data;
	new_list->next = list_copy(list->next);
	return (new_list);
}
