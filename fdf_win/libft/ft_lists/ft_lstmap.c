/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:05:55 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:44:44 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*curr;

	if (lst)
	{
		if (!(start = (*f)(lst)))
			return (NULL);
		curr = start;
		while (lst->next)
		{
			lst = lst->next;
			if (!(curr->next = (*f)(lst)))
			{
				free(start);
				return (NULL);
			}
			curr = curr->next;
		}
		return (start);
	}
	return (NULL);
}
