/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** pnj_event
*/

#include "rpg.h"

char *rpg_dialog(game_t *game, char *curr_dialog)
{
    int j = 0;
    int i = game->game_scenes[game->player.is_on_scene].pos_in_dial;

    j = my_strlen(game->game_scenes[game->player.is_on_scene].dialog);
    if (i - 2 == j && j != 0)
        return (curr_dialog);
    if (curr_dialog == NULL) {
        if (!(curr_dialog = malloc(sizeof(char) * (j + 1))))
            return (NULL);
    }
    curr_dialog[i] = game->game_scenes[game->player.is_on_scene].dialog[i];
    curr_dialog[i + 1] = '\0';
    ++game->game_scenes[game->player.is_on_scene].pos_in_dial;
    return (curr_dialog);
}

int set_pnj_dialog(game_t *game, char *text)
{
    sfText_setString(game->game_scenes[game->player.is_on_scene].texts.string,
        text);
    return (0);
}

char *clean_str(game_t *game, char *curr)
{
    curr[0] = '\0';
    sfText_setString(game->game_scenes[game->player.is_on_scene].texts.string,
        curr);
    free(curr);
    curr = NULL;
    return (curr);
}

int pnj_event(game_t *game)
{
    static double time;
    static char *curr_dialog = NULL;

    game->time = sfClock_getElapsedTime(game->clock);
    time = time + game->time.microseconds / 1000000.0;
    if (game->hit.pnj == 0) {
        time = 0;
        game->game_scenes[game->player.is_on_scene].pos_in_dial = 0;
        if (curr_dialog != NULL)
            curr_dialog = clean_str(game, curr_dialog);
    }
    if (time >= 0.1 && game->hit.pnj == 1) {
        curr_dialog = rpg_dialog(game, curr_dialog);
        if (curr_dialog == NULL)
            return (change_state_cause_of_error(game));
        set_pnj_dialog(game, curr_dialog);
        time -= 0.1;
    }
    return (0);
}