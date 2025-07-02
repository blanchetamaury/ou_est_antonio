/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:05:50 by mdegache          #+#    #+#             */
/*   Updated: 2025/07/02 17:50:59 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/include.h"

void    free_all(t_game *game)
{
    SDL_DestroyRenderer(game->window->renderer);
    SDL_DestroyWindow(game->window->window);
    IMG_Quit();
    SDL_Quit();
    ft_free_textures(game->texture);
    ft_free_rect(game->rect);
    free(game->player);
    free(game->window);
    free(game);
}

int init_win(t_win *win)
{
    win->window = SDL_CreateWindow("Où est Antonio ?", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN);
    win->renderer = SDL_CreateRenderer(win->window, -1, SDL_RENDERER_ACCELERATED);
    return (0);
}

void    get_map(t_map *map, char *map_name)
{
    int i;
    int j;
    int k;
    int fd;
    int bytes;
    char  buffer[1000];
    
    memset(buffer, 0, 1000);
    fd = open(map_name, O_RDONLY);
    bytes = read(fd, buffer, 1000); 
    i = 0;
    k = 0;
    while (buffer[k] && buffer[k] != '\0')
    {
        j = 0;
        while (buffer[k] && buffer[k] != '\n')
        {
            map->map[i][j] = buffer[k];
            k++;
            j++;
        }
        i++;
        k++;
    }
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
    game->player->animation_player_left->texture = malloc(sizeof(t_texture));
    game->player->animation_player_right->texture = malloc(sizeof(t_texture));
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    init_win(game->window);
    init_rect_wall(game);
    init_texture_wall_stone(game);
    init_texture_wall_grass(game);
    init_character_left(game);
    init_character_right(game);
    game->status = MAIN_SCREEN;
    get_map(game->map, map);
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
