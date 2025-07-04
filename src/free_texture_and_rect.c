/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture_and_rect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:42:02 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/04 13:46:13 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "include/include.h"

void	ft_free_textures(t_texture *textures)
{
	t_texture	*i;
	t_texture	*next;

	if (!textures)
		return ;
	i = textures;
	if (i == 0)
		textures = NULL;
	else
	{
		while (i)
		{
			next = i->next;
				SDL_DestroyTexture(i->texture);
			free(i);
			i = next;
		}
		textures = NULL;
	}
}

void	ft_free_rect(t_rect *rectangles)
{
	t_rect	*i;
	t_rect	*next;

	if (!rectangles)
		return ;
	i = rectangles;
	if (i == 0)
		rectangles = NULL;
	else
	{
		while (i)
		{
			next = i->next;
			free(i);
			i = next;
		}
		rectangles = NULL;
	}
}
