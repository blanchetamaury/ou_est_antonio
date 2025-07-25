/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:05:53 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/25 11:40:15 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero_gnl(void *s, size_t n)
{
	ft_memset_gnl(s, 0, n);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (size_t) - 1 / size)
		return (NULL);
	str = malloc(size * nmemb);
	if (str == NULL)
		return (NULL);
	ft_bzero_gnl(str, nmemb * size);
	return (str);
}

int	ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (-1);
	while (s[i] != '\0' && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return (i + 1);
	return (-1);
}

char	*ft_strjoin_gnl(char *str, char *src, int len)
{
	int		i;
	int		j;
	char	*new;

	if (!str)
		return (str = ft_calloc_gnl(1, sizeof(char)));
	if (!src)
		return (str);
	new = ft_calloc_gnl((ft_strlen_gnl(str) + len + 1), sizeof(char));
	if (new == 0)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (src[j] && j < len)
	{
		new[i + j] = src[j];
		j++;
	}
	free(str);
	return (new);
}

size_t	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
		i++;
	return (i);
}
