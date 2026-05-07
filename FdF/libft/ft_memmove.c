/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:47:56 by jomason           #+#    #+#             */
/*   Updated: 2025/08/15 13:42:58 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
	{
		i = 0;
		while (len-- > 0)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	const unsigned char	*tmp_s;
// 	unsigned char		*tmp_d;
// 	size_t				i;

// 	tmp_s = (const unsigned char *)src;
// 	tmp_d = (unsigned char *)dst;
// 	i = 0;
// 	if (!src && !dst)
// 		return (NULL);
// 	if (tmp_d < tmp_s)
// 	{
// 		while (i < len)
// 		{
// 			tmp_d[i] = tmp_s[i];
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (len-- > 0)
// 			tmp_d[len] = tmp_s[len];
// 	}
// 	return (dst);
// }
// // int	main(void)
// // {
// // 	char d[] = "Floppy Avocado";
// // 	char s[] = "Tasty Angry";
// // 	size_t n = 11;
// // 	printf("%s\n", ft_memmove(d, s, n));
// // }