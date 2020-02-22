/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:02:54 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:51:37 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*pd;
	char	*ps;

	pd = (char *)dst;
	ps = (char *)src;
	while (n--)
		*pd++ = *ps++;
	return (dst);
}
