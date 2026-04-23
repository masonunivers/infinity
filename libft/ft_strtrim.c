/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 16:02:30 by jomason           #+#    #+#             */
/*   Updated: 2025/08/03 17:18:40 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src && n > i)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	head;
	size_t	back;

	if (!s1 || !set)
		return (NULL);
	head = 0;
	back = ft_strlen(s1);
	while (ft_strchr(set, s1[head]) && s1[head])
		head++;
	while (ft_strchr(set, s1[back -1]) && back > head)
		back--;
	trimmed = (char *)malloc(sizeof(char) * (back - head) + 1);
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, (char *)s1 + head, (back - head));
	trimmed[back - head] = '\0';
	return (trimmed);
}
