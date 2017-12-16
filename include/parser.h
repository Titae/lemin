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
char **command_parser(char *command);
char **env_var_to_word_array(char *env_var, char separator);
list_t *config_to_list(char **file);

#endif /* PARSER_H_ */
