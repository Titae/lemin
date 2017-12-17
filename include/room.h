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
typedef struct ant ant_t;

struct ant
{
	int id;
	int can_move;
};

struct room
{
	char *name;
	int nb_ant;
	int is_special;
	int *pos;
	list_t *links;
	ant_t **ants;
	void (*populate)(room_t *this, int nb_ant);
	void (*send_ant)(room_t *this, room_t *room);
	void (*update)(room_t *this);
};

room_t *get_start_room(list_t *list);
room_t *get_end_room(list_t *list);
room_t *room_create(char *name, int is_special, int x, int y);
void create_link(char *name_room1, char *name_room2, list_t *room_list);
void populate_room(room_t *this, int nb_ant);
void send_ant(room_t *this, room_t *room);
void update_room(room_t *this);
ant_t *ant_create(int id);

#endif /* ROOM_H_ */
