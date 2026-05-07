/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:23:15 by jomason           #+#    #+#             */
/*   Updated: 2026/05/07 20:36:50 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ac != 2)
		return (ft_putstr_fd("Usage ./fdf <location and name>\n", 2), 1);
	if (!init_fdf(&data, av[1]))
		return (ft_putstr_fd("Initialization failed\n", 2), 1);
	mlx_key_hook(data.mlx, on_key_press, &data);
	mlx_close_hook(data.mlx, on_close, &data);
	mlx_loop(data.mlx);
	cleanup_fdf(&data);
	return (0);
}
