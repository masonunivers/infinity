/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:03:30 by jomason           #+#    #+#             */
/*   Updated: 2026/01/12 19:16:23 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int				error;
	unsigned long	addr;

	error = ft_putstr("0x");
	if (error == -1)
		return (error);
	addr = (unsigned long)ptr;
	error = ft_put_un(addr, 16);
	if (error == -1)
		return (error);
	return (error + 2);
}
