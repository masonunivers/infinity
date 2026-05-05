/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:15:25 by jomason           #+#    #+#             */
/*   Updated: 2025/07/20 20:01:31 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int omega)
{
	if ((omega >= 'a' && omega <= 'z') || (omega >= 'A' && omega <= 'Z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	int	alpha;

// 	alpha = '{';
// 	printf("%d", ft_isalpha(alpha));
// }
