/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:52:34 by jomason           #+#    #+#             */
/*   Updated: 2026/05/05 11:18:41 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	validate_characters(char *str, int *digit_count)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	*digit_count = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (dot_count > 0)
				return (0);
			dot_count++;
		}
		else if (ft_isdigit(str[i]))
			(*digit_count)++;
		else
			return (0);
		i++;
	}
	return (1);
}

static int	skip_sign(char *str)
{
	if (str[0] == '-' || str[0] == '+')
		return (1);
	return (0);
}

int	check_valid_double(char *str)
{
	int	digit_count;

	if (!str || !*str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	str += skip_sign(str);
	if (!validate_characters(str, &digit_count))
		return (0);
	return (digit_count > 0);
}
