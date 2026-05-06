/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:52:37 by jomason           #+#    #+#             */
/*   Updated: 2026/04/24 11:19:39 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_fraction_part(char *str, int *i, double *result)
{
	double	fraction;

	*result = 0.0;
	fraction = 0.1;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i])
		{
			if (!ft_isdigit(str[*i]))
				return (0);
			*result += (str[(*i)++] - '0') * fraction;
			fraction *= 0.1;
		}
	}
	return (1);
}

static int	parse_interger_part(char *str, int *i, double *result)
{
	*result = 0.0;
	while (str[*i] && str[*i] != '.')
	{
		if (!ft_isdigit(str[*i]))
			return (0);
		*result = *result * 10.0 + (str[(*i)++] - '0');
	}
	return (1);
}

double	atod(char *str)
{
	double	int_part;
	double	frac_part;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (!str)
		return (0.0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!parse_interger_part(str, &i, &int_part))
		return (0.0);
	if (!parse_fraction_part(str, &i, &frac_part))
		return (0.0);
	return ((int_part + frac_part) * sign);
}
