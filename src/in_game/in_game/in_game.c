/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** in game
*/

#include "rpg.h"

void *init_in_game(game_t *game)
{
    if (init_in_game_scene(game))
        change_state_cause_of_error(game);
    if (init_hitbox(game))
        change_state_cause_of_error(game);
    if (create_utils_in_game(game))
        change_state_cause_of_error(game);
    return ((void *) 1);
}

int in_game(game_t *game)
{
    if (create_character(game))
        change_state_cause_of_error(game);
    sfClock_restart(game->clock);
    while (game->game_state[GAME] == 1) {
        sfRenderWindow_clear(WINDOW, sfBlack);
        events_in_game(game);
        draw_in_game(game);
        while(game->game_state[PAUSE_MENU] == 1)
            pause_menu(game);
        sfClock_restart(game->clock);
        sfRenderWindow_display(game->window->window);
    }
    //destroy_in_game(game);
    return (0);
}