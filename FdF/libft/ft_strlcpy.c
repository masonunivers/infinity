/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:56:29 by jomason           #+#    #+#             */
/*   Updated: 2025/08/19 11:33:38 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (src_length + 1 < dstsize)
		ft_memcpy(dst, src, src_length + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_length);
}

// int	main(void)
// {
// 	char	des[300] = "This is Sparta!";
// 	char	src[42] = "These hamburgers are grotesque!";
// 	size_t	dstsize = sizeof(des);
// 	printf("Source: %s\n", des);
// 	size_t result = ft_strlcpy(des, src, dstsize);
// 	printf("Destination post-ft_strlcpy: %s\n", src);
// 	printf("The source string of a liar is: %zu\n", result);
// }