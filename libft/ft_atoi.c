/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:41:51 by jomason           #+#    #+#             */
/*   Updated: 2025/08/14 13:59:27 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * sign));
}

// int	main(int ac, char **av)
// {
// 	int	mine;
// 	int	theirs;

// 	if (ac == 2)
// 	{
// 		mine = ft_atoi(av[1]);
// 		theirs = atoi(av[1]);
// 		printf("mine: %d | theirs: %d\n", mine, theirs);
// 	}
// }
// // might get undefined behavior bc of missing overflow handling