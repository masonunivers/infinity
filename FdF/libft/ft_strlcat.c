/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:21:59 by jomason           #+#    #+#             */
/*   Updated: 2025/08/19 21:51:41 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	org_lsrc;
	size_t	org_ldst;

	org_lsrc = ft_strlen(src);
	org_ldst = ft_strlen(dst);
	if (org_ldst >= dstsize)
		org_ldst = dstsize;
	if (org_ldst == dstsize)
		return (dstsize + org_lsrc);
	if (org_lsrc < dstsize - org_ldst)
		ft_memcpy(dst + org_ldst, src, org_lsrc + 1);
	else
	{
		ft_memcpy(dst + org_ldst, src, dstsize - org_ldst - 1);
		dst[dstsize - 1] = '\0';
	}
	return (org_ldst + org_lsrc);
}

// int	main(void)
// {
// 	char dest[42] = "C'est un bon vie. ";
// 	const char *src = "Tres bien!";
// 	size_t dstsize = 29;
// 	printf("Original: %s\n", dest);
// 	size_t result = ft_strlcat(dest, src, dstsize);
// 	printf("Update %s\n -> The return value: %zu", dest, result);
// }