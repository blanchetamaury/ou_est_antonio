/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:10:53 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/03 17:29:37 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/include.h"

void    event_loop(t_game *game)
{   
    SDL_Event event;

    //int bottom = (game->player->x_win + 32) / 16;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN)
		{
            if (event.key.keysym.sym == SDLK_ESCAPE)
                game->status = STOP;
        }
            /*if (event.key.keysym.sym == SDLK_a)
            {
                game->pl_jump = 0;
                if (game->map->map[game->player->y][game->player->x - 1] == '0' && game->map->map[game->player->y][bottom - 1] == '0')
                {
                    game->player->animation = 1;
                    game->player->x_win -= 4;
                }
                
            }
            if (event.key.keysym.sym == SDLK_d)
            {
                game->pl_jump = 0;
                if (game->map->map[game->player->y][game->player->x + 1] == '0' && game->map->map[game->player->y][bottom] == '0')
                {
                    game->player->animation = 2;
                    game->player->x_win += 4;
                }
            }
            if (event.key.keysym.sym == SDLK_SPACE && game->pl_earth == 1)
            {
                if (game->map->map[game->player->y - 1][game->player->x] == '0' && game->map->map[game->player->y - 2][game->player->x] == '0')
                {
                    game->player->animation = 5;
                    game->pl_earth = 0;
                }
            }
		}*/
        if (event.type == SDL_KEYUP)
        {
            if (game->player->animation == 1)
                game->player->animation = 3;
            if (game->player->animation == 2)
                game->player->animation = 4;
        }
    }
}