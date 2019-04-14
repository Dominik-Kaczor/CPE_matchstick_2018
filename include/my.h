/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef PROT_F_
#define PROT_F_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "matchstick.h"

int my_putstr(char const *str);
int my_getnbr(char const *str);
void print_game_board(game_t *game);
int check_error(int ac, char **av, game_t *game);
int check_board(int line , int nb_matches, game_t *game);
int my_put_nbr(int nb);
int updated_board_game(int line , int nb_matches, game_t *game);
int check_victory(game_t *game);
void computer_play(game_t *game);
int read_player_move_and_print_updated_board_game(game_t *game);
int next_board_game(game_t *game);
int next_board_game_b(game_t *game);
int check_number(char *buffer);

#endif /* PROT_F_ */
