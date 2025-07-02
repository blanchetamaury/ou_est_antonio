/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:10:53 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/02 17:52:02 by amblanch         ###   ########.fr       */
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
		}
    }
}