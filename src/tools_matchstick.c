/*
** EPITECH PROJECT, 2019
** tools_matchstick
** File description:
** tools
*/

#include "../include/my.h"
#include "../include/matchstick.h"

void print_game_board(game_t *game)
{
    for (int h = 0; h <= (game->line + 1); h++) {
        my_putstr(game->board[h]);
        write(1, "\n", 1);
    }
}

int check_victory_b(game_t *game, int stick)
{
    if (stick == 0 && game->option == 3) {
        if (game->secu_win == 0) {
            game->secu_win = 1;
            my_putstr("You lost, too bad...\n");
        }
        return (2);
    }
    if (stick == 0 && (game->option == 0)) {
        if (game->secu_win == 0) {
            game->secu_win = 1;
            my_putstr("I lost... snif... but I'll get you next time!!\n");
        }
        return (1);
    }
    return (0);
}

int check_victory(game_t *game)
{
    int stick = 0;

    for (int h = 0; h <= game->line; h++) {
        for (int i = 0; i < (game->line * 2 + 1); i++) {
            if (game->board[h][i] == '|')
                stick++;
        }
    }
    return (check_victory_b(game, stick));
}

void ia_algo(game_t *game)
{
    int stick = 0;

    for (int h = 0; h <= game->line; h++) {
        for (int i = 0; i < (game->line * 2 + 1); i++) {
            if (game->board[h][i] == '|')
                stick = h;
        }
    }
    game->ia_line = stick;
    game->ia_stick = 1;
}

void computer_play(game_t *game)
{
    int pos = 0;
    int save_nb = 0;

    ia_algo(game);
    save_nb = game->ia_stick;
    pos = (2 *(game->line - 1) + 3);
    while (game->ia_stick != 0) {
        while (game->board[game->ia_line][pos] != '|')
            pos--;
        game->board[game->ia_line][pos] = ' ';
        game->ia_stick--;
    }
    my_putstr("AI removed ");
    my_put_nbr(save_nb);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->ia_line);
    write(1, "\n", 1);
    print_game_board(game);
}
