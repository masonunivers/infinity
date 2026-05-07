/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:07:59 by jomason           #+#    #+#             */
/*   Updated: 2025/07/14 14:40:35 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;
	size_t			i;

	str = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char data[] = {'a', 'b', 'c', 'x', 'y', 'z'};
// 	// char str[] = "Batman & Robin";

// 	const void *void_data = (const void *)data;
// 	// const void *void_str = (const void *)str;

// 	int	find_data = 'x';
// 	// char	find_str = "Robin";
// 	// int	str_conversion = ft_atoi(find_str);

// 	size_t	n1 = 4;
// 	// size_t	n2 = 14;

// 	printf("Memory address: %p\n", ft_memchr(void_data, find_data, n1));
// 	char *result = (char *)ft_memchr(void_data, find_data, n1);
// 	// char *result = (char *)ft_memchr(void_str, find_str, n2);
// 	if (result)
// 		printf("Successo!! Char found: '%c'\n", *result);
// 	else
// 		printf("WRAAGH, THAT'S AN ERROR! NOT FOUND!");
// 	// printf("%s\n", ft_memchr(str, find_str, n2));
// 	// HELP! I think I need atoi for the conversion
// }
