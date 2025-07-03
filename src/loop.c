/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:05:09 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/03 23:11:13 by amblanch         ###   ########.fr       */
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
    if (game->map->map[y][x - 1] != 'r' && game->map->map[y - 1][x] != 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone tl"), NULL, tmp);
    else if (game->map->map[y][x + 1] != 'r' && game->map->map[y - 1][x] != 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone tr"), NULL, tmp);
    else if (game->map->map[y - 1][x] != 'r' || game->map->map[y - 1][x] != 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone tm"), NULL, tmp);
    else if (game->map->map[y][x - 1] != 'r' && game->map->map[y + 1][x] != 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone bl"), NULL, tmp);
    else if (game->map->map[y][x + 1] != 'r' && game->map->map[y + 1][x] != 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone br"), NULL, tmp);
    else if (game->map->map[y + 1][x] != 'r' && game->map->map[y][x + 1] == 'r' && game->map->map[y][x - 1] == 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone bm"), NULL, tmp);
    else if (game->map->map[y][x - 1] != 'r' && game->map->map[y - 1][x] == 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone ml"), NULL, tmp);
    else if (game->map->map[y][x + 1] != 'r' && game->map->map[y - 1][x] == 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone mr"), NULL, tmp);
    else
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone mm"), NULL, tmp);
}

void    good_earth(t_game *game, int x, int y)
{
    SDL_Rect    *tmp;
    
    tmp = find_rect(game->rect, "block");
    tmp->x = (x - 1) * 16;
    tmp->y = (y - 1) * 16;
    if (game->map->map[y][x - 1] != '1' && game->map->map[y - 1][x] != '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth tl"), NULL, tmp);
    else if (game->map->map[y][x + 1] != '1' && game->map->map[y - 1][x] != '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth tr"), NULL, tmp);
    else if (game->map->map[y - 1][x] != '1' || game->map->map[y - 1][x] != '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth tm"), NULL, tmp);
    else if (game->map->map[y][x - 1] != '1' && game->map->map[y + 1][x] != '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth bl"), NULL, tmp);
    else if (game->map->map[y][x + 1] != '1' && game->map->map[y + 1][x] != '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth br"), NULL, tmp);
    else if (game->map->map[y + 1][x] != '1' && game->map->map[y][x + 1] == '1' && game->map->map[y][x - 1] == '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth bm"), NULL, tmp);
    else if (game->map->map[y][x - 1] != '1' && game->map->map[y - 1][x] == '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth ml"), NULL, tmp);
    else if (game->map->map[y][x + 1] != '1' && game->map->map[y - 1][x] == '1')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth mr"), NULL, tmp);
    else
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "earth mm"), NULL, tmp);
}

void    Antonio(t_game *game, int x, int y)
{
    SDL_Rect    *tmp;
    
    tmp = find_rect(game->rect, "antonio");
    tmp->x = (x - 1) * 16 - 16;
    tmp->y = (y - 1) * 16 - 16;
    if (game->map->map[y][x] == 'a')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "antonio"), NULL, tmp);
}
void    Rock(t_game *game, int x, int y)
{
    SDL_Rect    *tmp;
    
    tmp = find_rect(game->rect, "rock alone");
    tmp->x = (x - 1) * 16;
    tmp->y = (y - 1) * 16;
    if (game->map->map[y][x] == 'c')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "rock alone"), NULL, tmp);
}

void    create_ground(t_game *game)
{
    int x;
    int y;
    int count_x;
    int count_y;

    /*x = 0;
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
    }*/
    x = 0;
    y = 0;
    while (game->map->map[y])
    {
        x = 0;
        while(game->map->map[y][x])
        {
            if (x * 16 > 600 && x * 16 < 1331 && y * 16 > 300 && y * 16 < 790)
            {
                if (game->map->map[y][x] == '1')
                    good_earth(game, x, y);
                if (game->map->map[y][x] == 'r')
                    good_stone(game, x, y);
                if (game->map->map[y][x] == 'c')
                    Rock(game, x, y);
                
            }
            x++;
        }
        y++;
    }
    
    if (game->player->y - 10 < 0)
        y = 0;
    else
        y = game->player->y - 10;
    count_x = 0;
    count_y = 0;
    while (game->map->map[y] && count_y < 20)
    {
        if (game->player->x - 10 < 0)
            x = 0;
        else
            x = game->player->x - 10;
        count_x = 0;
        while(game->map->map[y][x] && count_x < 20)
        {
            if (game->map->map[y][x] == '1')
                good_earth(game, x, y);
            if (game->map->map[y][x] == 'r')
                good_stone(game, x, y);
            if (game->map->map[y][x] == 'a')
                Antonio(game, x, y);
            if (game->map->map[y][x] == 'c')
                Rock(game, x, y);
            x++;
            count_x++;
        }
        count_y++;
        y++;
    }
}

void    map_new_pos_player(t_game *game)
{
    game->player->x = (game->player->x_win) / 16 + 1;
    game->player->y = (game->player->y_win) / 16 + 1;
    if (game->map->map[game->player->y + 1][game->player->x] == '0' &&  game->pl_jump != 1)
    {
        game->player->y_win += 4;
    }
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
    game->pl_jump = 0;
    game->pl_earth = 1;
    game->player->last_time = SDL_GetTicks();
    game->keystates = SDL_GetKeyboardState(NULL);
    while (game->status != STOP)
    {
        int bottom = (game->player->x_win + 32) / 16;
        map_new_pos_player(game);
        start_time = SDL_GetTicks();
		uint32_t current = SDL_GetTicks();
        game->dt = (current - lastTicks) / 1000.0f;
        lastTicks = current;
        
        if (game->map->map[game->player->y + 1][game->player->x] != '0')
            game->pl_earth = 1;
        else
            game->pl_earth = 0;
        SDL_RenderClear(game->window->renderer);
        event_loop(game);
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "bg"), NULL, find_rect(game->rect, "bg"));
         SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "home"), NULL, find_rect(game->rect, "home"));
        create_ground(game);
        if (game->keystates[SDL_SCANCODE_A]) // player left
        {
            //game->pl_jump = 0;
            if (game->map->map[game->player->y][game->player->x - 1] == '0' && game->map->map[game->player->y][bottom - 1] == '0')
            {
                if (game->player->animation != 5)
                    game->player->animation = 1;
                game->player->x_win -= 4;
            }
        }
        else if (game->keystates[SDL_SCANCODE_D]) // player right
        {
            //game->pl_jump = 0;
            if (game->map->map[game->player->y][game->player->x + 1] == '0' && game->map->map[game->player->y][bottom] == '0')
            {
                if (game->player->animation != 5)
                    game->player->animation = 2;
                game->player->x_win += 4;
            }
        }
        if (game->player->animation == 1)
            animation_loop_player(game, game->player->animation_player_left, 100, game->player->x_win -16, game->player->y_win - 16);
        if (game->player->animation == 2)
            animation_loop_player(game, game->player->animation_player_right, 100, game->player->x_win - 16, game->player->y_win - 16);
        if (game->player->animation == 3)
            animation_loop_player(game, game->player->animation_player_no_move_left, 80, game->player->x_win - 16, game->player->y_win - 16);
        if (game->player->animation == 4)
            animation_loop_player(game, game->player->animation_player_no_move_right, 80, game->player->x_win - 16, game->player->y_win - 16);
        if (game->keystates[SDL_SCANCODE_SPACE] && game->pl_earth == 1)
        {
            if (game->map->map[game->player->y - 1][game->player->x] == '0' && game->map->map[game->player->y - 2][game->player->x] == '0')
            {
                game->player->animation = 5;
                game->pl_earth = 0;
            }
        }
        if (game->player->animation == 5)
        {
            if (game->map->map[game->player->y - 1][game->player->x] == '0')
                game->player->y_win -= 4;
            game->pl_jump = 1;
            if (animation_loop_player_jump(game, 300, game->player->x_win - 16, game->player->y_win - 16) == 0)
            {
                game->pl_jump = 0;
                game->player->animation = 3;
            }
        }
        SDL_RenderPresent(game->window->renderer);
        
        
        frame_duration = SDL_GetTicks() - start_time;
		if (frame_duration < 1000 / 60)
			SDL_Delay((1000 / 60) - frame_duration);
    }
}