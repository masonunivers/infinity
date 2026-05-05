/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:27:36 by jomason           #+#    #+#             */
/*   Updated: 2025/07/10 15:45:29 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int d)
{
	if (d >= '0' && d <= '9')
		return (d);
	return (0);
}

// int	main(void)
// {
// 	int	damsel;

// 	damsel = '+';
// 	printf("%d", ft_isdigit(damsel));
// }
