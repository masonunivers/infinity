/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:50:54 by jomason           #+#    #+#             */
/*   Updated: 2025/08/15 14:17:00 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int input)
{
	return (ft_isdigit(input) || ft_isalpha(input));
}

// int	main(void)
// {
// 	int	spit;

// 	spit = '#';
// 	printf("%d", ft_isalnum(spit));
// }
