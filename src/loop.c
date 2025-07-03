/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:05:09 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/03 10:36:54 by amblanch         ###   ########.fr       */
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
                game->map->map[y][x] = '0';
                return ;
            }
            x++;
        }
        y++;
    }
}

void    good_stone(t_game *game, int x, int y)
{
    SDL_Rect    *tmp;

    tmp = find_rect(game->rect, "block");
    tmp->x = (x - 1) * 16;
    tmp->y = (y - 1) * 16;
    if (game->map->map[y][x - 1] == '0' && (game->map->map[y - 1][x] == '0' || game->map->map[y - 1][x] == 'p'))
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone tl"), NULL, tmp);
    else if (game->map->map[y][x + 1] == '0' && (game->map->map[y - 1][x] == '0' || game->map->map[y - 1][x] == 'p'))
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone tr"), NULL, tmp);
    else if (game->map->map[y - 1][x] == '0' || game->map->map[y - 1][x] == 'p')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone tm"), NULL, tmp);
    else if (game->map->map[y][x - 1] == '0' && game->map->map[y - 1][x] == 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone ml"), NULL, tmp);
    else if (game->map->map[y][x + 1] == '0' && game->map->map[y - 1][x] == 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone mr"), NULL, tmp);
    else if (game->map->map[y][x - 1] == '0' && game->map->map[y + 1][x] == '#')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone bl"), NULL, tmp);
    else if (game->map->map[y][x + 1] == '0' && game->map->map[y + 1][x] == '#')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone br"), NULL, tmp);
    else
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone mm"), NULL, tmp);
}

void    good_earth(t_game *game, int x, int y)
{
    SDL_Rect    *tmp;
    
    tmp = find_rect(game->rect, "block");
    tmp->x = (x - 1) * 16;
    tmp->y = (y - 1) * 16;
    if (game->map->map[y][x - 1] == '0' && (game->map->map[y - 1][x] == '0' || game->map->map[y - 1][x] == 'p'))
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth tl"), NULL, tmp);
    else if (game->map->map[y][x + 1] == '0' && (game->map->map[y - 1][x] == '0' || game->map->map[y - 1][x] == 'p'))
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth tr"), NULL, tmp);
    else if (game->map->map[y - 1][x] == '0' || game->map->map[y - 1][x] == 'p')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth tm"), NULL, tmp);
    else if (game->map->map[y][x - 1] == '0' && game->map->map[y - 1][x] == '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth ml"), NULL, tmp);
    else if (game->map->map[y][x + 1] == '0' && game->map->map[y - 1][x] == '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth mr"), NULL, tmp);
    else if (game->map->map[y][x - 1] == '0' && game->map->map[y + 1][x] == '#')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth bl"), NULL, tmp);
    else if (game->map->map[y][x + 1] == '0' && game->map->map[y + 1][x] == '#')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth br"), NULL, tmp);
    else
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth mm"), NULL, tmp);
}

void    create_ground(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (game->map->map[y])
    {
        x = 0;
        while(game->map->map[y][x])
        {
            if (game->map->map[y][x] == '1')
                good_earth(game, x, y);
            if (game->map->map[y][x] == 'r')
                good_stone(game, x, y);
            x++;
        }
        y++;
    }
}

void    map_new_pos_player(t_game *game)
{
    game->player->x = (game->player->x_win) / 16;
    game->player->y = (game->player->y_win) / 16;
    //printf("x = %d | y = %d | x_win = %d | y_win = %d\n", game->player->x, game->player->y, game->player->x_win, game->player->y_win);
    if (game->map->map[game->player->y + 1][game->player->x] == '0' && game->player->animation != 5/*&& (game->player->x_win - game->player->x * 16) >= 16*/)
        game->player->y_win += 2;
}

void loop(t_game *game)
{
    uint32_t   start_time;
    uint32_t   lastTicks;
    uint32_t   frame_duration;

    get_player_pos(game);
    game->player->x_win = (game->player->x) * 16 - 16;
    game->player->y_win = (game->player->y) * 16 - 16;
    game->player->animation = 3;
    while (game->status != STOP)
    {
        map_new_pos_player(game);
        start_time = SDL_GetTicks();
		uint32_t current = SDL_GetTicks();
        game->dt = (current - lastTicks) / 1000.0f;
        lastTicks = current;
        
        
        SDL_RenderClear(game->window->renderer);
        event_loop(game);
        SDL_SetRenderDrawColor(game->window->renderer, 85, 130, 219, 255);
        create_ground(game);
        if (game->player->animation == 1)
            animation_loop_player(game, game->player->animation_player_left, 100, game->player->x_win - 16, game->player->y_win - 32);
        if (game->player->animation == 2)
            animation_loop_player(game, game->player->animation_player_right, 100, game->player->x_win - 16, game->player->y_win - 32);
        if (game->player->animation == 3)
            animation_loop_player(game, game->player->animation_player_no_move_left, 80, game->player->x_win - 16, game->player->y_win - 32);
        if (game->player->animation == 4)
            animation_loop_player(game, game->player->animation_player_no_move_right, 80, game->player->x_win - 16, game->player->y_win - 32);
        if (game->player->animation == 5)
        {
            game->player->y_win -= 5;
            if (animation_loop_player_jump(game, game->player->animation_player_left, 100, game->player->x_win - 16, game->player->y_win - 32) == 0)
                game->player->animation = 1;
        }
        SDL_RenderPresent(game->window->renderer);
        
        
        frame_duration = SDL_GetTicks() - start_time;
		if (frame_duration < 1000 / 60)
			SDL_Delay((1000 / 60) - frame_duration);
    }
}