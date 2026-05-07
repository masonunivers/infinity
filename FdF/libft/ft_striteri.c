/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:58:16 by jomason           #+#    #+#             */
/*   Updated: 2025/08/19 21:48:48 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void test_function(unsigned int index, char *c)
// {
// 	if(*c == ' ')
// 		return ;
// 	if (index % 2 == 0)
// 	{
// 		*c = *c - 32; // Convert even indexed characters to uppercase
// 	}
// 	else
// 	{
// 		*c = *c + 1; // Increment odd indexed characters
// 	}
// }
// // need more test_functions for other f functions.
// int main(void)
// {
// 	char str1[] = "hello world> a   ce b d* f";
// 	char str2[] = "aaaaabcTest123";
// 	char str3[] = "";
// 	char str4[] = "abcdefg";
// 	printf("Original str1: \"%s\"\n", str1);
// 	ft_striteri(str1, test_function);
// 	printf("Modified str1: \"%s\")\n\n", str1);
// 	printf("Original str2: \"%s\"\n", str2);
// 	ft_striteri(str2, test_function);
// 	printf("Modified str2: \"%s\")\n\n", str2);
// 	printf("Original str3: \"%s\" (Empty string)\n", str3);
// 	ft_striteri(str3, test_function);
// 	printf("Modified str3: \"%s\" (Should remain empty)\n\n", str3);
// 	printf("Testing with NULL string:\n");
// 	ft_striteri(NULL, test_function);
// 	printf("Function should not crash if handled correctly\n\n");
// 	printf("Testing with NULL function:\n");
// 	printf("Original str4: \"%s\"\n", str4);
// 	ft_striteri(str4, NULL);
// 	printf("Modified str4: \"%s\"\n", str4);
// }