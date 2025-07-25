/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_texture_or_rect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:24:48 by amblanch          #+#    #+#             */
/*   Updated: 2025/07/02 17:52:02 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	ft_lstadd_back_rect(t_rect **lst, t_rect *new)
{
	t_rect	*i;

	i = *lst;
	if (lst == NULL)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		while (i->next != 0)
			i = i->next;
		i->next = new;
	}
}

t_rect	*ft_lstnew_rect(int x, int y , int h, int w, char *name)
{
	t_rect	*list;
	SDL_Rect rect = {x, y, h, w};

	list = malloc(sizeof(t_rect) * 1);
	if (list == 0)
		return (0);
	list->next = NULL;
	list->rect = rect;
	list->name = name;
	return (list);
}

void	ft_lstadd_back_texture(t_texture **lst, t_texture *new)
{
	t_texture	*i;

	i = *lst;
	if (lst == NULL)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		while (i->next != 0)
			i = i->next;
		i->next = new;
	}
}

t_texture	*ft_lstnew_texture(SDL_Texture *texture, char *name)
{
	t_texture	*list;

	list = malloc(sizeof(t_texture) * 1);
	if (list == 0)
		return (0);
	list->next = NULL;
	list->texture = texture;
	list->name = name;
	return (list);
}

void deleteNode(t_rect** lst, char *name)
{
	t_rect	*tmp;
	t_rect *prev = NULL;
	if (lst == NULL || *lst == NULL)
		return;
	tmp = *lst;
	while (lst)
	{
		if (strncmp(tmp->name, name, strlen(name)) == 0)
		{
			if (prev == NULL)
				*lst = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

SDL_Texture	*LoadTexture(const char *file, SDL_Renderer *renderer)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = IMG_Load(file);
	if (!surface)
	{
		SDL_Log("Erreur, chargement de l'image : %s", IMG_GetError());
		return (NULL);
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture)
	{
		SDL_Log("Erreur, création de la texture : %s", SDL_GetError());
		return (NULL);
	}
	return (texture);
}

