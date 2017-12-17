/*
** EPITECH PROJECT, 2017
** sort_path.c
** File description:
** Sort path by size
*/

#include <stdlib.h>
#include "list.h"
#include "path.h"

static void handle_rest(list_t *l_curr, list_t *l_tmp)
{
	path_t *path_tmp = NULL;

	while (l_tmp) {
		if (((path_t *)l_curr->data)->size > ((path_t *)l_tmp->data)->size) {
			path_tmp = l_curr->data;
			l_curr->data = l_tmp->data;
			l_tmp->data = path_tmp;
		}
		l_tmp = l_tmp->next;
	}
}

void sort_path(list_t **path)
{
	list_t *l_curr = *path;
	list_t *l_tmp = NULL;

	while (l_curr->next) {
		l_tmp = l_curr->next;
		handle_rest(l_curr, l_tmp);
		l_curr = l_curr->next;
	}

}
