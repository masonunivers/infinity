/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_un.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:03:13 by jomason           #+#    #+#             */
/*   Updated: 2026/01/12 19:16:23 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_un(unsigned long nbr, int base)
{
	int		counter;
	int		tmp;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (nbr < (unsigned long)base)
	{
		counter = ft_putchar(symbols[nbr]);
		if (counter == -1)
			return (-1);
		return (counter);
	}
	counter = ft_put_un(nbr / base, base);
	if (counter == -1)
		return (-1);
	tmp = ft_putchar(symbols[nbr % base]);
	if (tmp == -1)
		return (-1);
	return (counter + tmp);
}
