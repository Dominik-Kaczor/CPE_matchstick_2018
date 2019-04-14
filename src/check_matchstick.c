/*
** EPITECH PROJECT, 2019
** check_matchstick
** File description:
** all check
*/

#include "../include/my.h"
#include "../include/matchstick.h"

int check_error(int ac, char **av, game_t *game)
{
    if (ac != 3) {
        write(2, "invalide nomber of arguments\n", 29);
        return (1);
    }
    for (int h = 1; h < 3; h++ ) {
        for (int i = 0; av[h][i] != '\0'; i++) {
            if ((av[h][i] < '0' || av[h][i] > '9') && av[h][i] != '\0') {
                write (1, "invalide character\n", 19);
                return (1);
            }
        }
    }
    game->line = my_getnbr(av[1]);
    game->max_stick = my_getnbr(av[2]);
    if (game->line <= 1 || game->line >= 100 || game->max_stick <= 0) {
        write (1, "invalide nomber\n", 16);
        return (1);
    }
    return (0);
}

int check_board_b(int line , int nb_matches, game_t *game)
{
    int stick = 0;

    for (int h = 0; game->board[line][h] != '\0'; h++) {
        if (game->board[line][h] == '|')
            stick++;
    }
    if (nb_matches > stick) {
        my_putstr("Error: not enough matches on this line\n");
        return (1);
    }
    if (nb_matches <= 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (1);
    }
    return (0);
}

int check_board(int line , int nb_matches, game_t *game)
{
    if (game->line < line || line <= 0) {
        my_putstr("Error: this line is out of range\n");
        return (1);
    }
    if (game->max_stick < nb_matches ) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(game->max_stick);
        my_putstr(" matches per turn\n");
        return (1);
    }
    return (check_board_b(line , nb_matches, game));
}

int check_number(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n') {
        if (buffer[0] == '\n')
            return (0);
        if (buffer[i] < 48 || buffer[i] > 57) {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (84);
        }
        i++;
    }
    return (0);
}
