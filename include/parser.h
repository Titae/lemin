/*
** EPITECH PROJECT, 2017
** parser.h
** File description:
** function used to parse
*/

#ifndef PARSER_H_
#define PARSER_H_

typedef struct list list_t;

char **my_str_to_word_array(char *str);
list_t *config_to_list(char **file);
int pos_str_in_array(char **array, char *str);

#endif /* PARSER_H_ */
