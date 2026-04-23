/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:44:21 by jomason           #+#    #+#             */
/*   Updated: 2025/08/03 19:28:25 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	m;

	if (!s)
		return (NULL);
	i = 0;
	m = 0;
	if (ft_strlen(s) > start)
	{
		while (s[start + m] != '\0' && m < len)
			m++;
	}
	str = (char *)malloc(sizeof(char) * m + 1);
	if (!str)
		return (NULL);
	while (m != 0 && i < m)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
