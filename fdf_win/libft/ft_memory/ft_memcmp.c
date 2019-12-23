/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:38:04 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:51:37 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (n)
	{
		if (*ps1 == *ps2)
		{
			ps1++;
			ps2++;
		}
		else
			return ((unsigned char)*ps1 - (unsigned char)*ps2);
		n--;
	}
	return (0);
}
