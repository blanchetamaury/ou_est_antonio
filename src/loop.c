/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:05:09 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/02 17:52:02 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

void loop(t_game *game)
{
    uint32_t   start_time;
    uint32_t   lastTicks;
    uint32_t   frame_duration;

    while (game->status != STOP)
    {
        start_time = SDL_GetTicks();
		uint32_t current = SDL_GetTicks();
        game->dt = (current - lastTicks) / 1000.0f;
        lastTicks = current;
        
        
        SDL_RenderClear(game->window->renderer);
        event_loop(game);
        SDL_SetRenderDrawColor(game->window->renderer, 85, 130, 219, 255);
        animation_loop_player(game, game->player->animation_player_left, 100, 200, 200);
        SDL_RenderPresent(game->window->renderer);
        
        
        frame_duration = SDL_GetTicks() - start_time;
		if (frame_duration < 1000 / 60)
			SDL_Delay((1000 / 60) - frame_duration);
    }
}