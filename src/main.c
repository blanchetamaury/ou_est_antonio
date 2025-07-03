/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:05:50 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/03 09:38:27 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

void    free_all(t_game *game)
{
    ft_free_textures(game->texture);
    SDL_DestroyRenderer(game->window->renderer);
    SDL_DestroyWindow(game->window->window);
    IMG_Quit();
    SDL_Quit();
    ft_free_rect(game->rect);
    ft_free_h(game->map->map);
    free(game->player->animation_player_no_move_right->texture);
    free(game->player->animation_player_no_move_left->texture);
    free(game->player->animation_player_left->texture);
    free(game->player->animation_player_right->texture);
    free(game->player->animation_player_no_move_left);
    free(game->player->animation_player_no_move_right);
    free(game->player->animation_player_left);
    free(game->player->animation_player_right);
    free(game->player);
    free(game->window);
    free(game->map);
    free(game);
}

int init_win(t_win *win)
{
    win->window = SDL_CreateWindow("Où est Antonio ?", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 368, 112, SDL_WINDOW_SHOWN);
    win->renderer = SDL_CreateRenderer(win->window, -1, SDL_RENDERER_ACCELERATED);
    return (0);
}

void    get_map(t_map *map, char *map_name)
{
    int     fd;
    char    *tmp;
    
    fd = open(map_name, O_RDONLY);
    map->map = ft_malloc_h(2);
    tmp = get_next_line(fd);
    while (tmp != NULL)
    {
        map->map = ft_push(map->map, ft_strtrim(tmp, "\n"));
        free(tmp);
        tmp = get_next_line(fd);
    }
    free(tmp);
    map->map = ft_push(map->map, NULL);
    close (fd);
}

int init_structs(t_game *game, char *map)
{
    game = malloc(sizeof(t_game));
    game->window = malloc(sizeof(t_win));
    game->player = malloc(sizeof(t_player));
    game->rect = malloc(sizeof(t_rect));
    game->texture = malloc(sizeof(t_texture));
    game->map = malloc(sizeof(t_map));
    game->player->animation_player_left = malloc(sizeof(t_texture_anim));
    game->player->animation_player_right = malloc(sizeof(t_texture_anim));
    game->player->animation_player_no_move_right = malloc(sizeof(t_texture_anim));
    game->player->animation_player_no_move_left = malloc(sizeof(t_texture_anim));
    game->player->animation_player_left->texture = malloc(sizeof(t_texture));
    game->player->animation_player_right->texture = malloc(sizeof(t_texture));
    game->player->animation_player_no_move_right->texture = malloc(sizeof(t_texture));
    game->player->animation_player_no_move_left->texture = malloc(sizeof(t_texture));
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    init_win(game->window);
    game->rect = NULL;
    game->texture = NULL;
    init_rect_wall(game);
    init_texture_wall_stone(game);
    init_texture_wall_grass(game);
    init_character_left(game);
    init_character_right(game);
    init_character_no_move_right(game);
    init_character_no_move_left(game);
    game->status = MAIN_SCREEN;
    get_map(game->map, map);
        int i = 0;
    while (game->map->map[i])
    {
        printf("%s\n", game->map->map[i]);
        i++;
    }
    loop(game);
    free_all(game);
    return (0);
}

int main(void)
{
    t_game  *game;

    game = NULL;
    if (init_structs(game, "map_de_con.txt"))
        return (1);
}
