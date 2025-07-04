/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegachee <mdegachee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:05:09 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/04 11:05:15 by mdegachee         ###   ########.fr       */
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
    else if (game->map->map[y][x - 1] != 'r' && game->map->map[y - 1][x] == 'r' && game->map->map[y][x + 1] == 'r')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "stone ml"), NULL, tmp);
    else if ((game->map->map[y][x + 1] != 'r' && game->map->map[y - 1][x] == 'r') || (game->map->map[y][x + 1] != 'r' && game->map->map[y][x - 1] == '#'))
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
    tmp->x = (x - 1) * 16;
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

void    trap(t_game *game, int x, int y)
{
    SDL_Rect    *tmp;

    tmp = find_rect(game->rect, "block");
    tmp->x = (x - 1) * 16;
    tmp->y = (y - 1) * 16;
    if (game->map->map[y][x] == 's')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "spike"), NULL, tmp);
}

void    antonio_action(t_game *game, int x, int y)
{
    SDL_Rect    tmp;

    tmp.x = (x - 1) * 16 - 221;
    tmp.y = (y - 1) * 16 - 67;
    tmp.h = 67;
    tmp.w = 221;
    SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "antonio_text"), NULL, &tmp);
}

void    frog(t_game *game, int x, int y)
{
    SDL_Rect    *tmp;

    tmp = find_rect(game->rect, "antonio");
    tmp->x = (x - 1) * 16;
    tmp->y = (y - 1) * 16 - 16;
    if (game->map->map[y][x] == 'f')
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "frog"), NULL, tmp);
}

void    frog_action(t_game *game, int x, int y)
{
    SDL_Rect    tmp;
    int         i;

    tmp.x = (x - 1) * 16 - 221;
    tmp.y = (y - 1) * 16 - 67;
    tmp.h = 67;
    tmp.w = 221;
    i = rand() % 3;
    if (i == 0 && game->bot == 0)
    {
        game->bot = 1;
    }
    if (i == 1 && game->bot == 0)
    {
        game->bot = 2;
    }
    if (i == 2 && game->bot == 0)
    {
        game->bot = 3;
    }
    if (game->bot == 1)
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "bot1"), NULL, &tmp);
    if (game->bot == 2)
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "bot2"), NULL, &tmp);
    if (game->bot == 3)
        SDL_RenderCopy(game->window->renderer, find_texture(game->texture, "bot3"), NULL, &tmp);
}

void    create_ground(t_game *game)
{
    int x;
    int y;
    int count_x;
    int count_y;

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
                if (game->map->map[y][x] == 's')
                    trap(game, x, y);
                if (game->map->map[y][x] == 'a')
                     Antonio(game, x, y);
                if (game->map->map[y][x] == 'f')
                     frog(game, x, y);
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
            {
                Antonio(game, x, y);
            }
            if (game->map->map[y][x] == 'c')
                Rock(game, x, y);
            if (game->map->map[y][x] == 's')
                 trap(game, x, y);
            if (game->map->map[y][x] == 'f')
                frog(game, x, y);
            x++;
            count_x++;
        }
        count_y++;
        y++;
    }
    int status;

    status = 0;
    if (game->player->y - 2 < 0)
        y = 0;
    else
        y = game->player->y - 2;
    count_x = 0;
    count_y = 0;
    while (game->map->map[y] && count_y < 4)
    {
        if (game->player->x - 2 < 0)
            x = 0;
        else
            x = game->player->x - 2;
        count_x = 0;
        while(game->map->map[y][x] && count_x < 4)
        {
            if (game->map->map[y][x] == 'a')
            {
                antonio_action(game, x, y);
            }
            if (game->map->map[y][x] == 'f')
            {
                status = 1;
                frog_action(game, x, y);
            }
            x++;
            count_x++;
        }
        count_y++;
        y++;
    }
    if (status == 0)
        game->bot = 0;
}

void    map_new_pos_player(t_game *game)
{
    game->player->x = (game->player->x_win) / 16 + 1;
    game->player->y = (game->player->y_win) / 16 + 1;
    if ((game->map->map[game->player->y + 1][game->player->x] == '0' || game->map->map[game->player->y + 1][game->player->x] == 's') &&  game->pl_jump != 1)
    {
        game->player->y_win += 4;
    }
}

int verif_move(t_game *game, int pos, int status)
{
    char *str;
    int i;
    
    str = "0s";
    i = 0;
    while (str[i])
    {
        if (status == 0)
            if (str[i] == game->map->map[game->player->y][game->player->x  + pos])
                return (1);
        if (status == 1)
            if (str[i] == game->map->map[game->player->y][game->player->x  + pos])
                return (1);
        i++;
    }
    return (0);
}

void loop(t_game *game)
{
    uint32_t   start_time;
    uint32_t   lastTicks;
    uint32_t   frame_duration;

    get_player_pos(game);
    game->player->spawn_x = game->player->x;
    game->player->spawn_y = game->player->y;
    game->player->x_win = (game->player->x) * 16 - 16;
    game->player->y_win = (game->player->y) * 16 - 16;
    game->player->animation = 3;
    game->pl_jump = 0;
    game->pl_earth = 1;
    game->player->last_time = SDL_GetTicks();
    game->keystates = SDL_GetKeyboardState(NULL);
    game->bot = 0;
    while (game->status != STOP)
    {
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
        if (game->map->map[game->player->y][game->player->x] == 's')
        {
            game->player->y = game->player->spawn_y;
            game->player->x = game->player->spawn_x;
            game->player->x_win = (game->player->x) * 16 - 16;
            game->player->y_win = (game->player->y) * 16 - 16;
        }
        if (game->keystates[SDL_SCANCODE_A])
        {
            if (verif_move(game, -1, 0) == 1)
            {
                if (game->player->animation != 5)
                    game->player->animation = 1;
                game->player->x_win -= 4;
            }
        }
        else if (game->keystates[SDL_SCANCODE_D])
        {
            if (verif_move(game, 1, 1) == 1)
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
                game->player->y_win -= 6;
            game->pl_jump = 1;
            if (animation_loop_player_jump(game, 200, game->player->x_win - 16, game->player->y_win - 16) == 0)
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