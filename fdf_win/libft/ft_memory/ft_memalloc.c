/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:37:04 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:51:33 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void		*ft_memalloc(size_t size)
{
	char	*ptr;

	if (size)
	{
		if ((ptr = (char *)malloc(size)) == NULL)
			return (NULL);
		ft_bzero(ptr, size);
		return ((void *)ptr);
	}
	return (NULL);
}
