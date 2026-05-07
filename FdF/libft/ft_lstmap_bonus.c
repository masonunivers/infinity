/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomason <jomason@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 19:02:39 by jomason           #+#    #+#             */
/*   Updated: 2025/08/18 13:04:47 by jomason          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *), void(*del)(void *))
{
	t_list	*new;
	t_list	*current;
	void	*new_content;

	current = NULL;
	if (!lst)
		return (NULL);
	else
	{
		while (lst)
		{
			new_content = f(lst->content);
			new = ft_lstnew(new_content);
			if (new == NULL)
			{
				del(new_content);
				ft_lstclear(&current, (*del));
				return (NULL);
			}
			ft_lstadd_back(&current, new);
			lst = lst->next;
		}
	}
	return (current);
}
