/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** event_move
*/

#include "../../../../include/rpg.h"

void is_player_walking(game_t *game)
{
    static double time = 0;
    sfTime seconds = sfClock_getElapsedTime(game->clock);

    time = time + seconds.microseconds / 1000000.0;
    if (game->player.is_walking == 0)
        time = 0;
    else {
        while (time >= 0.3) {
            move_rect_player(game);
            time -= 0.3;
        }
    }
    return;
}