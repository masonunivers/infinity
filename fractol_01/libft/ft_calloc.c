/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:47:49 by jomason           #+#    #+#             */
/*   Updated: 2025/07/30 12:58:20 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}

// int	main(void)
// {
// 	 //Allocate space for cool integers
// 	 int *arr1 = (int *)ft_calloc(5, sizeof(int));
// 	 if (arr1 == NULL) {
// 		 printf("ft_calloc failed for arr1\n");
// 		 return 1;
// 	 }
// 	 printf("Testing integers:\n");
// 	 for (size_t i = 0; i < 5; i++) {
// 		 printf("arr1[%zu] = %d\n", i, arr1[i]);
// 	 }
// 	 free(arr1);
// 	 printf("\n");

// 	 //Allocate space for special characters
// 	 char *str = (char *)ft_calloc(3, sizeof(char));
// 	 if (str == NULL) {
// 		 printf("ft_calloc failed for str\n");
// 		 return 1;
// 	 }
// 	 printf("Testing character:\n");
// 	 for (size_t i = 0; i < 10; i++) {
// 		 printf("str[%zu] = '%c' (ASCII: %d)\n", i, str[i], str[i]);
// 	 }
// 	 free(str);
// 	 printf("\n");

// 	 //Allocate zero bytes (should return a unique pointer or NULL)
// 	 void *zero_ptr = ft_calloc(0, 100);
// 	 printf("Testing ground zero bytes:\n");
// 	 printf("Pointer to zero bytes: %p\n", zero_ptr);
// 	 if (zero_ptr != NULL) {
// 		 free(zero_ptr);
// 	 }
// 	 printf("\n");

// 	 //Allocate with zero count douko
// 	 void *zero_count_ptr = ft_calloc(100, 0);
// 	 printf("Testing count zero:\n");
// 	 printf("Pointer with zero count: %p\n", zero_count_ptr);
// 	 if (zero_count_ptr != NULL) {
// 		 free(zero_count_ptr);
// 	 }
// 	 printf("\n");

// 	 return 0;
// }
