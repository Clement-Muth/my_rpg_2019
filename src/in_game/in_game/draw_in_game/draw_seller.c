/*
** EPITECH PROJECT, 2020
** rpg Project
** File description:
** draw file
*/

#include "../../../../include/rpg.h"

void draw_seller(game_t *game)
{
    drawSprite(WINDOW,
            game->game_scenes[SELLER_MAP].ui_scene[MAP].sprite, NULL);
    drawSprite(WINDOW,
            game->game_scenes[SELLER_MAP].pnj[PNJ_S].sprite, NULL);
    drawSprite(WINDOW, game->player.character.sprite, NULL);
    return;
}