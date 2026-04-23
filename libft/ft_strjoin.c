/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:51:38 by jomason           #+#    #+#             */
/*   Updated: 2025/08/19 21:51:25 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*united;
	size_t	m;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	m = (ft_strlen(s1) + ft_strlen(s2));
	united = (char *)malloc(sizeof(char) * m + 1);
	if (!united)
		return (NULL);
	while (s1[i])
	{
		united[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		united[i] = s2[j];
		i++;
		j++;
	}
	united[i] = '\0';
	return (united);
}

// int main(void)
// {
// 	char *str1;
// 	char *str2;
// 	char *result;
// 	// Test case 1: Basic concatenation
// 	str1 = "Hello, ";
// 	str2 = "world!";
// 	result = ft_strjoin(str1, str2);
// 	if (!result)
// 	{
// 		fprintf(stderr, "Memory allocation failed\n");
// 		return (1);
// 	}
// 	printf("Test 1: s1=\"%s\", s2=\"%s\", result=\"%s\"\n", str1, str2, result);
// 	free(result);
// 	result = NULL;
// }
