/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:50:57 by jomason           #+#    #+#             */
/*   Updated: 2025/08/03 17:29:08 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// int	main(void)
// {
// 	int	*num_ptr = malloc(sizeof(int));

// 	if (!num_ptr)
// 		return (1);
// 	*num_ptr = 14;
// 	t_list *node_int = ft_lstnew(num_ptr);
// 	printf("\nint is: %d", *(int *)(node_int->content));
// 	printf("@%p\n\n", (void *)node_int->next);
// 	free(num_ptr);
// 	free(node_int);

// 	char	*my_string = "Howdy, partner!";

// 	t_list	*node_str = ft_lstnew(my_string);
// 	if (node_str == NULL)
// 		return (1);
// 	printf("string is: %s", (char *)(node_str->content));
// 	printf("@%p\n\n", (void *)node_str->next);
// 	free(node_str);

// 	t_list *node_null_content = ft_lstnew(NULL);
// 	if (node_null_content == NULL)
// 		return (1);
// 	printf("NULL %p\n", node_null_content->content);
// 	printf("next@%p\n\n", (void *)node_null_content->next);
// 	free(node_null_content);
// }