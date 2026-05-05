/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:49:39 by jomason           #+#    #+#             */
/*   Updated: 2025/08/19 11:29:23 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (dst);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dst);
}

// int	main(void)
// {
// 	char destiny[] = "";
// 	char secretsauce[] = "Beware of the";
// 	printf("%s ", ft_memcpy(destiny, secretsauce, 13));
// 	char dork[] = "Lord w Monster";
// 	char santa[] = "Cookie";
// 	printf("%s\n", ft_memcpy(dork, santa, 6));
// }
