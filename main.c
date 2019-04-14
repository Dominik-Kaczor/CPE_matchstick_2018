/*
** EPITECH PROJECT, 2019
** main
** File description:
** matchstick
*/

#include "include/my.h"
#include "include/matchstick.h"

int updated_board_game(int line , int nb_matches, game_t *game)
{
    int pos = (2 *(game->line - 1) + 3);
    int save_nb = nb_matches;

    if (check_board(line , nb_matches, game) == 1)
        return (84);
    while (nb_matches != 0) {
        while (game->board[line][pos] != '|')
            pos--;
        game->board[line][pos] = ' ';
        nb_matches--;
    }
    my_putstr("Player removed ");
    my_put_nbr(save_nb);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    write(1, "\n", 1);
    print_game_board(game);
    return (0);
}

void init_game_board(game_t *game)
{
    int k = 0;

    game->board = malloc(sizeof(char *) * (game->line + 2));
    for (int h = 0; h < (game->line + 2); h++)
        game->board[h] = malloc(sizeof(char) * (2 *(game->line - 1) + 4));
    for (int h = 0; h < (2 *(game->line - 1) + 3); h++)
        game->board[0][h] = '*';
    for (int h = 1; h <= game->line; h++) {
        for (int i = 0; i < (game->line * 2 + 1); i++) {
            if (i == 0 || i == (game->line * 2))
                game->board[h][i] = '*';
            else if (i >= game->line - k && i <= game->line + k)
                game->board[h][i] = '|';
            else
                game->board[h][i] = ' ';
        }
        k++;
    }
    for (int h = 0; h < (2 *(game->line - 1) + 3); h++)
        game->board[game->line + 1][h] = '*';
}

int main(int ac, char **av)
{
    game_t game;

    if (check_error(ac, av, &game) == 1)
        return (84);
    init_game_board(&game);
    return (read_player_move_and_print_updated_board_game(&game));
}
