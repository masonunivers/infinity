/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:41:34 by jomason           #+#    #+#             */
/*   Updated: 2025/08/03 20:24:48 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitcount(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	i;
	int		len;

	len = ft_digitcount(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = n;
	if (i < 0)
	{
		str[0] = '-';
		i *= -1;
	}
	str[len] = '\0';
	if (i == 0)
		str[0] = '0';
	while (i > 0)
	{
		str[--len] = (i % 10) + '0';
		i /= 10;
	}
	return (str);
}

// int	main(void) // not working...
// {
// 	int		no1 = 77;
// 	char	*str1 = ft_itoa(no1);
// 		if (str1)
// 	{
// 		printf("Input: %d, Output: %s\n", no1, str1);
// 		free(str1);
// 	}
// 	else
// 		printf("Malloc failed and so did you: %d\n", no1);

// 	int		no2 = -79;
// 	char	*str2 = ft_itoa(no2);
// 	if (str2)
// 	{
// 		printf("Input: %d, Output: %s\n", no2, str2);
// 		free(str2);
// 	}
// 	else
// 		printf("Failed again and so did you: %d\n", no2);

// 	int		no3 = 0;
// 	char	*str3 = ft_itoa(no3);
// 	if (str3)
// 	{
// 		printf("Input: %d, Output: %s\n", no3, str3);
// 		free(str3);
// 	}
// 	else
// 		printf("You never learn: %d\n", no3);

// 	int		no4 = 77777777;
// 	char	*str4 = ft_itoa(no1);
// 	if (str4)
// 	{
// 		printf("Input: %d, Output: %s\n", no4, str4);
// 		free(str4);
// 	}
// 	else
// 		printf("Idk what you want from me: %d\n", no4);
// }
// // what if there is space: _space_-994277? at str[0] would be space..