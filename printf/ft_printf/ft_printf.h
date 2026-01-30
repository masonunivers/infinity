/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:04:22 by jomason           #+#    #+#             */
/*   Updated: 2026/01/30 13:02:24 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_put_hex(unsigned long nbr, int base);
int	ft_put_nbr(long nbr, int base);
int	ft_put_un(unsigned long nbr, int base);
int	ft_putchar(int argument);
int	ft_putptr(void *ptr);
int	ft_putstr(char *str);

#endif