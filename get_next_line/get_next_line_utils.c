/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:55:16 by jomason           #+#    #+#             */
/*   Updated: 2026/01/14 13:46:08 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static size_t	ft_copy_at(char *dst, const char *src, size_t at)
{
	size_t	k;

	k = 0;
	while (src[k])
	{
		dst[at + k] = src[k];
		k++;
	}
	return (k);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t		i;
	size_t		j;
	char		*joined;
	const char	*s2p;

	if (!s2)
		s2p = "";
	else
		s2p = s2;
	if (!s1)
		return (ft_strdup(s2p));
	joined = malloc(ft_strlen(s1) + ft_strlen(s2p) + 1);
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	i += ft_copy_at(joined, s1, 0);
	j += ft_copy_at(joined, s2p, i);
	joined[i + j] = '\0';
	return (joined);
}
