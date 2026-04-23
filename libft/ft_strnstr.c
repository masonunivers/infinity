/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:44:44 by jomason           #+#    #+#             */
/*   Updated: 2025/08/14 15:16:57 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len && needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char hey[] = "Find me if you can.";
// 	const char pee[] = "x";
// 	const char *eureka;
// 	size_t l = 19;

// 	eureka = ft_strnstr(hey, pee, l);
// 	if (eureka)
// 		printf("Found: %s\n", eureka);
// 	else
// 		printf("Sorry, no sry. Try again.\n");
// }
