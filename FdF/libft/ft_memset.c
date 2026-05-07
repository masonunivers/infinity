/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:40:14 by jomason           #+#    #+#             */
/*   Updated: 2025/07/10 16:58:47 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *) b;
	while (len > 0)
	{
		*(tmp_ptr++) = (unsigned char) c;
		len--;
	}
	return (b);
}

// int	main(void)
// {
// 	char str[50] = "no...pressure";
// 	printf("\nBefore memset: %s\n", str);
// 	ft_memset(str + 7, '$', 3*sizeof(char));
// 	printf("\nAfter memset: %s\n\n", str);
// }
