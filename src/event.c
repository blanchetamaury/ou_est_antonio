/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:10:53 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/03 10:38:21 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/include.h"

void    event_loop(t_game *game)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
		{
            if (event.key.keysym.sym == SDLK_ESCAPE )
                game->status = STOP;
            if (event.key.keysym.sym == SDLK_a)
            {
                if (game->map->map[game->player->y][game->player->x - 1] == '0')
                {
                    game->player->animation = 1;
                    game->player->x_win -= 3;
                }
                
            }
            if (event.key.keysym.sym == SDLK_d)
            {
                if (game->map->map[game->player->y][game->player->x + 1] == '0')
                {
                    game->player->animation = 2;
                    game->player->x_win += 3;
                }
            }
		}
        if (event.type == SDL_KEYUP)
        {
            if (game->player->animation == 1)
                game->player->animation = 3;
            if (game->player->animation == 2)
                game->player->animation = 4;
            if (event.key.keysym.sym == SDLK_SPACE && game->player->animation != 5)
            {
               game->player->animation = 5;
            }
        }
    }
}