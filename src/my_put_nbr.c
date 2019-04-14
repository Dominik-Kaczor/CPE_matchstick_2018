/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** display nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    else if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    if ((nb / 10) != 0) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
        return (1);
    }
    my_putchar(nb % 10 + '0');
    return (1);
}
