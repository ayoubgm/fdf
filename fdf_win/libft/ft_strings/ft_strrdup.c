/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 04:41:42 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:48:32 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char		*ft_strrdup(char *head, char *tail)
{
	size_t	size;
	char	*res;

	size = 0;
	if (head && tail)
	{
		while (head + size < tail)
			size++;
		if (!(res = (char *)ft_memalloc(sizeof(char) * size + 1)))
			return (NULL);
		ft_bzero(res, size + 1);
		while (size-- > 0)
			res[size] = head[size];
		return (res);
	}
	return (NULL);
}
