/*
** EPITECH PROJECT, 2019
** game_move
** File description:
** read player move and print updated
*/

#include "../include/my.h"
#include "../include/matchstick.h"

int next_board_game_b(game_t *game)
{
    char *buffer = malloc(sizeof(char) * 8);
    size_t buffsize = 20;

    my_putstr("Matches: ");
    getline(&buffer, &buffsize, stdin);
    if (buffer[0] == 0)
        return (84);
    if (buffer[0] == '\n' || check_number(buffer) == 84) {
        game->option = 1;
        return (0);
    }
    game->new_stick = my_getnbr(buffer);
    if (updated_board_game(game->new_line, game->new_stick, game) == 0)
        game->option = 3;
    else
        game->option = 1;
    return (0);
}

int next_board_game(game_t *game)
{
    char *buffer = malloc(sizeof(char) * 8);
    size_t buffsize = 20;

    if (game->option == 1) {
        my_putstr("Line: ");
        getline(&buffer, &buffsize, stdin);
        if (buffer[0] == 0)
            return (84);
        if (buffer[0] == '\n' || check_number(buffer) == 84)
            return (0);
        game->new_line = my_getnbr(buffer);
        if (check_board(game->new_line , 1, game) == 0)
            game->option = 2;
    } else if (game->option == 2)
        return (next_board_game_b(game));
    return (0);
}

int read_player_move_and_print_updated_board_game(game_t *game)
{
    game->option = 0;
    game->secu_win = 0;
    print_game_board(game);
    while (1) {
        if (next_board_game(game) == 84)
            return (0);
            if (check_victory(game) == 1 || check_victory(game) == 2)
                break;
        if (game->option == 0) {
            my_putstr("\nYour turn:\n");
            game->option = 1;
        } else if (game->option == 3) {
            my_putstr("\nAI'S turn...\n");
            computer_play(game);
            game->option = 0;
        }
        if (check_victory(game) == 1 || check_victory(game) == 2)
            break;
    }
    return (check_victory(game));
}
