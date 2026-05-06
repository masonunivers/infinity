/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:06:25 by jomason           #+#    #+#             */
/*   Updated: 2025/08/19 22:06:26 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;
	size_t			len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}

// int main(void)
// {
// 	const char *original_string = "hello, world!";
// 	char *new_string;
// 	char buffer[20];
// 	char *found;
// 	new_string = ft_strmapi(original_string, NULL);
// 	if (new_string != NULL)
// 	{
// 		printf("Original string: %s\n", original_string);
// 		printf("Modified string (add 1): %s\n", new_string);
// 		free(new_string);
// 	}
// 	else
// 		printf("ft_strmapi failed (NULL func)\n");
// 	// Test ft_memcpy
// 	ft_memcpy(buffer, "Original String", 16);
// 	printf("Before ft_memcpy: %s\n", buffer);
// 	ft_memcpy(buffer + 7, "Modified", 8);
// 	printf("After ft_memcpy: %s\n", buffer);
// 	// Test ft_strchr
// 	found = ft_strchr(original_string, 'w');
// 	if (found != NULL)
// 		printf("ft_strchr: Found 'w' at pos: %ld\n", found - original_string);
// 	else
// 		printf("ft_strchr: 'w' not found\n");
// 	found = ft_strchr(original_string, 'z');
// 	if (found != NULL)
// 		printf("ft_strchr: Found 'z' at pos: %ld\n", found - original_string);
// 	else
// 		printf("ft_strchr: 'z' not found\n");
// 	return (0);
// }