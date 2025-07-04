/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:46:43 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/04 13:46:13 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

t_texture_anim   *animation_init(t_texture_anim *anim, t_texture *texture)
{
    anim->origine = texture;
    anim->texture = texture;
    anim->last_time = SDL_GetTicks();
    return (anim);
}

void    animation_loop_player(t_game *game, t_texture_anim *anim, int speed, int x, int y)
{
    uint32_t now = SDL_GetTicks();
    SDL_Rect    tmp;
    
    if (now - anim->last_time >= speed) // 150
    {
        anim->last_time = now;
        if (anim->texture) 
            anim->texture = anim->texture->next; 
    }
    if (anim->texture == NULL)
        anim->texture = anim->origine;
    tmp.h = 32;
    tmp.w = 32;
    tmp.x = x;
    tmp.y = y;
    SDL_RenderCopy(game->window->renderer, anim->texture->texture, NULL, &tmp);
}

int    animation_loop_player_jump(t_game *game, int speed, int x, int y)
{
    uint32_t now = SDL_GetTicks();
    SDL_Rect    tmp;
    
    if (now - game->player->last_time >= speed) // 150
    {
        game->player->last_time = now;
        return (0);
    }
    tmp.h = 32;
    tmp.w = 32;
    tmp.x = x;
    tmp.y = y;
    SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "jump"), NULL, &tmp);
    return(1);
}

void    animation_loop(t_game *game, t_texture_anim *anim, int speed)
{
    uint32_t now = SDL_GetTicks();
    if (now - anim->last_time >= speed) // 150
    {
        anim->last_time = now;
        if (anim->texture) 
            anim->texture = anim->texture->next;
    }
    if (anim->texture == NULL)
        anim->texture = anim->origine;
    SDL_RenderCopy(game->window->renderer, anim->texture->texture, NULL, find_rect(game->rect, "block"));
}