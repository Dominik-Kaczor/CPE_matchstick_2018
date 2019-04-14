/*
** EPITECH PROJECT, 2019
** matchstick.h
** File description:
** struct
*/

#ifndef NAME_H_
#define NAME_H_

typedef struct game {
    char **board;
    int line;
    int max_stick;
    int option;
    int new_line;
    int new_stick;
    int secu_win;
    int ia_stick;
    int ia_line;
}game_t;

#endif /* NAME_H_ */

