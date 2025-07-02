/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:05:09 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/02 20:51:48 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

void     get_player_pos(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (game->map->map[y])
    {
        x = 0;
        while(game->map->map[y][x])
        {
            if (game->map->map[y][x] == 'p')
            {
                game->player->x = x;
                game->player->y = y;
                return ;
            }
            x++;
        }
        y++;
    }
}

void    create_ground(t_game *game)
{
    int x;
    int y;
    SDL_Rect    *tmp;

    x = 0;
    y = 0;
    while (game->map->map[y])
    {
        x = 0;
        while(game->map->map[y][x])
        {
            if (game->map->map[y][x] == '1')
            {
                tmp = find_rect(game->rect, "block");
                tmp->x = (x - 1) * 16;
                tmp->y = (y - 1) * 16;
                SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth mm"), NULL, tmp);
            }
            x++;
        }
        y++;
    }
}

void loop(t_game *game)
{
    uint32_t   start_time;
    uint32_t   lastTicks;
    uint32_t   frame_duration;

    get_player_pos(game);
    while (game->status != STOP)
    {
        start_time = SDL_GetTicks();
		uint32_t current = SDL_GetTicks();
        game->dt = (current - lastTicks) / 1000.0f;
        lastTicks = current;
        
        
        SDL_RenderClear(game->window->renderer);
        event_loop(game);
        SDL_SetRenderDrawColor(game->window->renderer, 85, 130, 219, 255);
        create_ground(game);
        animation_loop_player(game, game->player->animation_player_left, 100, (game->player->x - 1) * 16, (game->player->y - 1) * 16 - 16);
        SDL_RenderPresent(game->window->renderer);
        
        
        frame_duration = SDL_GetTicks() - start_time;
		if (frame_duration < 1000 / 60)
			SDL_Delay((1000 / 60) - frame_duration);
    }
}