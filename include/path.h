/*
** EPITECH PROJECT, 2017
** path.h
** File description:
** function used to path finding
*/

#ifndef PATH_H_
#define PATH_H_

typedef struct path path_t;
typedef struct list list_t;
typedef struct room room_t;

struct path {
	int size;
	list_t *rooms;
	void (*update)(path_t *this);
};

path_t *create_path(list_t *rooms);
void update_path(path_t *this);
void get_all_path(list_t **path_list, list_t *list_room, room_t *room_actual);
void sort_path(list_t **path);

#endif /* PATH_H_ */
