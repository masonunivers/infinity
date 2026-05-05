/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:43:31 by jomason           #+#    #+#             */
/*   Updated: 2025/07/30 13:03:17 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1);
	cpy = (char *) malloc(sizeof(char) * (len +1));
	if (cpy == NULL)
		return (NULL);
	return (ft_strcpy(cpy, s1));
}

// int	main(void)
// {
// 	const char *org_str = "Hi there. I'm a duplicate.";
// 	char *dup_str = "";

// 	printf("BEFOREDupplo: '%s'\n", dup_str);
// 	dup_str = ft_strdup(org_str);
// 	printf("AfterDuplo: '%s'\n..believe me, it's duplicated.\n", dup_str);
// }