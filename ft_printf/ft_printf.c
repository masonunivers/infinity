/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 20:04:33 by jomason           #+#    #+#             */
/*   Updated: 2026/01/30 13:38:10 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(char specifier, va_list *args)
{
	int	counter;

	if (specifier == 'c')
		counter = ft_putchar(va_arg(*args, int));
	else if (specifier == 's')
		counter = ft_putstr(va_arg(*args, char *));
	else if (specifier == 'd' || specifier == 'i')
		counter = ft_put_nbr((long)va_arg(*args, int), 10);
	else if (specifier == 'x')
		counter = ft_put_un((unsigned long)va_arg(*args, unsigned int), 16);
	else if (specifier == 'X')
		counter = ft_put_hex((unsigned long)va_arg(*args, unsigned int), 16);
	else if (specifier == 'u')
		counter = ft_put_un((unsigned long)va_arg(*args, unsigned int), 10);
	else if (specifier == '%')
		counter = ft_putchar('%');
	else if (specifier == 'p')
		counter = ft_putptr(va_arg(*args, void *));
	else
		return (-1);
	return (counter);
}

static int	handle_spec(const char *format, int *i, va_list *args)
{
	if (format[*i + 1] == '\0')
		return (-2);
	(*i)++;
	return (printf_format(format[*i], args));
}

static int	process_format(const char *format, va_list *args)
{
	int		i;
	int		counter;
	int		error;

	i = -1;
	counter = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			error = handle_spec(format, &i, args);
			if (error == -2 || error == -1)
				return (-1);
			counter += error;
			continue ;
		}
		error = write(1, &format[i], 1);
		if (error == -1)
			return (-1);
		counter += error;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = process_format(format, &args);
	va_end(args);
	return (res);
}

// #include <stdio.h>
// int main()
// {
// 	printf(" %p %p\n", NULL, (void *)0);
// 	ft_printf(" %p %p\n", NULL, (void *)0);
// 	ft_printf(" %p\n", 0);
// 	return (0);
// }