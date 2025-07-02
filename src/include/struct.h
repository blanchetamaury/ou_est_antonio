/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:50:58 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/02 17:27:04 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

#include "include.h"


typedef enum __attribute__((__packed__)) e_statusgame
{
	MAIN_SCREEN,
    GAME,
    STOP,
	ERR
}	t_status_game;

typedef struct          s_texture
{
    SDL_Texture         *texture;
    struct s_texture    *next;
    char                *name;
}                       t_texture;

typedef struct          s_texture_anim
{
    t_texture         *texture;
    t_texture         *origine;
    int               nb_frame;
    float             time_len;
    float             last_time;
    char              *name;
}                       t_texture_anim;

typedef struct          s_rect
{
    SDL_Rect            rect;
    struct s_rect       *next;
    char                *name;    
}                       t_rect;

typedef struct          s_player
{
    t_texture_anim      *animation_player_left;
    t_texture_anim      *animation_player_right;
    int                 x;
    int                 y;   
}                       t_player;

typedef struct          s_win
{
    SDL_Renderer        *renderer;
    SDL_Window          *window;
}                       t_win;

typedef struct          s_map // pas fait
{
    char    map[1000][1000];
}                       t_map;

typedef struct          s_game
{
    t_win               *window;
    t_player            *player;
    t_map               *map;    
    t_rect              *rect;
    t_texture           *texture;
    t_status_game       status;
    float               dt;
}                       t_game;

#endif