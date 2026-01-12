/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:03:22 by jomason           #+#    #+#             */
/*   Updated: 2026/01/12 19:16:23 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	counter;
	int	error;

	counter = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			error = ft_putchar(str[i++]);
			if (error == -1)
				return (error);
			counter += error;
		}
	}
	return (counter);
}
