/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:01:39 by jomason           #+#    #+#             */
/*   Updated: 2025/08/19 21:53:32 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

// char	*ft_strrchr(const char *s, int c)
// {
// 	char	*last_c;
// 	char	uc;
// 	size_t	i;
// 	last_c = NULL;
// 	uc = (char)c;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == uc)
// 			last_c = (char *)&s[i];
// 		i++;
// 	}
// 	if (uc == '\0')
// 		return ((char *)&s[i]);
// 	return (last_c);
// }
// // int	main(void)
// // {
// // 	char str[] = "ALWAYS be grateful to!Your Momma!";
// // 	int c = '!';
// // 	printf("Pointer points @ %s\n", ft_strrchr(str, c));
// // }
