/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:15:46 by jomason           #+#    #+#             */
/*   Updated: 2025/08/15 15:01:29 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int font)
{
	if (font >= 32 && font <= 126)
		return (font);
	return (0);
}

// int	main(void)
// {
// 	char	canon;

// 	canon = '~';
// 	printf("%d", ft_isprint(canon));
// }
