/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:03:05 by jomason           #+#    #+#             */
/*   Updated: 2026/01/12 23:14:50 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(long nbr, int base)
{
	int	counter;

	if (nbr < 0)
	{
		counter = ft_putchar('-');
		if (counter == -1)
			return (-1);
		return (counter + ft_put_un((unsigned long)(-(nbr + 1)) + 1, base));
	}
	return (ft_put_un((unsigned long)nbr, base));
}
