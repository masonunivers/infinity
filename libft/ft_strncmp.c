/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:27:58 by jomason           #+#    #+#             */
/*   Updated: 2025/08/03 19:43:42 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (unsigned char)s2[i] == (unsigned char)s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	const char	*s1;
// 	const char	*s2;
// 	size_t		n;

// 	n = 34;
// 	s1 = "supercalifragilisticexpialidocious";
// 	s2 = "supercalifragilisticexpialidocious*";
// 	printf("%d\n", ft_strncmp(s1, s2, n));
// }
