/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:47:30 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/04 10:43:22 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H

# define INCLUDE_H

# include "../../SDL_LIB/include/SDL2/SDL.h"
# include "../../SDL_LIB/include/SDL2/SDL_image.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h> 
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "struct.h"
# include "../gnl/get_next_line.h"
# include <SDL_ttf.h>

////////////////////////////////////////////
///     list_texture_or_rect.c          ///
////////////////////////////////////////////

void	    ft_lstadd_back_rect(t_rect **lst, t_rect *new);
t_rect	    *ft_lstnew_rect(int x, int y , int h, int w, char *name);
void	    ft_lstadd_back_texture(t_texture **lst, t_texture *new);
t_texture	*ft_lstnew_texture(SDL_Texture *texture, char *name);
void        deleteNode(t_rect** lst, char *name);
SDL_Texture	*find_texture(t_texture *texture, char *name);
SDL_Rect	*find_rect(t_rect *rect, char *name);
void	    init_rect_wall(t_game *all);
void	    init_texture_wall_stone(t_game *all);
void	    init_texture_wall_grass(t_game *all);
void        init_character_left(t_game  *all);
void        init_character_right(t_game  *all);
void        init_character_no_move_right(t_game  *all);
void        init_character_no_move_left(t_game  *all);
void	    init_jump(t_game *all);
SDL_Texture	*LoadTexture(const char *file, SDL_Renderer *renderer);

////////////////////////////////////////////
///              animation               ///
////////////////////////////////////////////
void        animation_loop(t_game *game, t_texture_anim *anim, int speed);
t_texture_anim    *animation_init(t_texture_anim *anim, t_texture *texture);
void        animation_loop_player(t_game *game, t_texture_anim *anim, int speed, int x, int y);
int    animation_loop_player_jump(t_game *game, int speed, int x, int y);

////////////////////////////////////////////
///                 SRC                  ///
////////////////////////////////////////////
void    event_loop(t_game *game);
void    loop(t_game *game);

////////////////////////////////////////////
///                 FREE                 ///
////////////////////////////////////////////
void	ft_free_textures(t_texture *textures);
void	ft_free_rect(t_rect *rectangles);

////////////////////////////////////////////
///                 UTILS                ///
////////////////////////////////////////////
void	*ft_realloc(void *ptr, size_t size);
void	ft_free_h(char **array);
char	**ft_malloc_h(__uint32_t min_cap);
void	ft_stats(char **array, int *extern_size, int *extern_cap);
char	**ft_push(char **array, char *new);

#endif