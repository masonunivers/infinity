/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:55:24 by jomason           #+#    #+#             */
/*   Updated: 2025/08/17 23:13:59 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_extractword(const char *s, char c, size_t *i)
{
	char	*word_size;
	size_t	genesis;

	genesis = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	word_size = (char *)malloc(*i - genesis + 1);
	if (!word_size)
		return (NULL);
	ft_strlcpy(word_size, s + genesis, *i - genesis + 1);
	return (word_size);
}

static char	**ft_parsewords(char **array, const char *s, char c)
{
	size_t	i;
	size_t	words;
	char	*current_word;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		current_word = ft_extractword(s, c, &i);
		if (!current_word)
		{
			while (words > 0)
				free(array[--words]);
			free(array);
			return (NULL);
		}
		array[words] = current_word;
		words++;
	}
	array[words] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!arr)
		return (NULL);
	return (ft_parsewords(arr, s, c));
}

// // arr is the address of the newly allocated memory block:)
// int	main(void)
// {
// 	char	*str1;
// 	char	**split1;
// 	int		i;

// 	// spaces as delimiters
// 	str1 = "Vive ora ede et caca";
// 	split1 = ft_split(str1, ' ');
// 	if (!split1)
// 		return (1); // Handle allocation failure in main
// 	printf("String: \"%s\", Delimiter: ' '\n", str1);
// 	for (i = 0; split1[i]; i++)
// 	{
// 		printf("Word [%d]: \"%s\"\n", i, split1[i]);
// 		free(split1[i]); // Free allocated words
// 	}
// 	free(split1); // Free the array of words
// 	printf("\n");

// 	// string with leading and trailing spaces
// 	str1 = "   ora caca   ";
// 	split1 = ft_split(str1, ' ');
// 	if (!split1)
// 		return (1);
// 	printf("String: \"%s\", Delimiter: ' '\n", str1);
// 	for (i = 0; split1[i]; i++)
// 	{
// 		printf("Word [%d]: \"%s\"\n", i, split1[i]);
// 		free(split1[i]);
// 	}
// 	free(split1);
// 	printf("\n");

// 	// string with multiple delimiters
// 	str1 = "vive||ede|||caca";
// 	split1 = ft_split(str1, '|');
// 	if (!split1)
// 		return (1);
// 	printf("String: \"%s\", Delimiter: '|'\n", str1);
// 	for (i = 0; split1[i]; i++)
// 	{
// 		printf("Word [%d]: \"%s\"\n", i, split1[i]);
// 		free(split1[i]);
// 	}
// 	free(split1);
// 	printf("\n");

// 	// empty string
// 	str1 = "";
// 	split1 = ft_split(str1, ' ');
// 	if (!split1)
// 		return (1);
// 	printf("Empty string: \"%s\", Delimiter: ' '\n", str1);
// 	for (i = 0; split1[i]; i++)
// 	{
// 		printf("Word [%d]: \"%s\"\n", i, split1[i]);
// 		free(split1[i]);
// 	}
// 	free(split1);
// 	printf("\n");

// 	// string with no delimiters
// 	str1 = "viveoraedecaca";
// 	split1 = ft_split(str1, ' ');
// 	if (!split1)
// 		return (1);
// 	printf("String: \"%s\", Delimiter: ' '\n", str1);
// 	for (i = 0; split1[i]; i++)
// 	{
// 		printf("Word [%d]: \"%s\"\n", i, split1[i]);
// 		free(split1[i]);
// 	}
// 	free(split1);
// 	printf("\n");

// 	// string with only delimiters
// 	str1 = "      ";
// 	split1 = ft_split(str1, ' ');
// 	if (!split1)
// 		return (1);
// 	printf("String: \"%s\", Delimiter: ' '\n", str1);
// 	for (i = 0; split1[i]; i++)
// 	{
// 		printf("Word [%d]: \"%s\"\n", i, split1[i]);
// 		free(split1[i]);
// 	}
// 	free(split1);
// 	printf("\n");

// 	// complex string
// 	str1 = "  hello  world  42  ";
// 	split1 = ft_split(str1, ' ');
// 	if (!split1)
// 		return (1);
// 	printf("String: \"%s\", Delimiter: ' '\n", str1);
// 	for (i = 0; split1[i]; i++)
// 	{
// 		printf("Word [%d]: \"%s\"\n", i, split1[i]);
// 		free(split1[i]);
// 	}
// 	free(split1);
// 	printf("\n");
// 	return (0);
// }
