/*
** EPITECH PROJECT, 2026
** Bidoune
** File description:
** Star
*/

#include <unistd.h>

static void cotes(unsigned int size)
{
    int c;

    c = 0;
    while (c < size * 2 + 1) {
        write(1, "*", 1);
        c++;
    }
    if (size == 1)
        write(1, " ", 1);
    c = 0;
    while (c < 2 * size - 3 && size != 1) {
        write(1, " ", 1);
        c++;
    }
    c = 0;
    while (c < size * 2 + 1) {
        write(1, "*", 1);
        c++;
    }
}

static void boucle(int i, unsigned int size)
{
    int q;

    q = 1;
    while (q <= i * 2 - 1) {
        write(1, " ", 1);
        q++;
    }
    if (i != 0)
        write(1, "*", 1);
}

void star_upper(unsigned int size)
{
    int i;
    int j;
    int x;

    x = 3 * size - 1;
    for (i = 0; i < size; i++) {
        for (j = 0; j < x - i; j++)
            write(1, " ", 1);
        if (size == 1)
            write(1, " ", 1);
        write(1, "*", 1);
        boucle(i, size);
        write(1, "\n", 1);
    }
}

void middle_star(unsigned int size)
{
    int i;
    int j;

    write(1, "\n", 1);
    for (i = 0; i < 2 * size - 1; i++) {
        j = i < size ? i : 2 * size - 2 - i;
        while (j >= 0) {
            write(1, " ", 1);
            j--;
        }
        write(1, "*", 1);
        j = 6 * size - 5 - 2 * (i < size ? i : 2 * size - 2 - i);
        j += 2 * (size == 1);
        while (j > 0) {
            write(1, " ", 1);
            j--;
        }
        write(1, "*", 1);
        write(1, "\n", 1);
    }
}

void star_lower(unsigned int size)
{
    int i;
    int j;
    int x;

    x = 3 * size - 1;
    write(1, "\n", 1);
    for (i = size - 1; i >= 0; i--) {
        for (j = 0; j < x - i; j++)
            write(1, " ", 1);
        if (size == 1)
            write(1, " ", 1);
        write(1, "*", 1);
        boucle(i, size);
        write(1, "\n", 1);
    }
}

void star(unsigned int size)
{
    if (size == 0)
        return;
    star_upper(size);
    cotes(size);
    middle_star(size);
    cotes(size);
    star_lower(size);
}