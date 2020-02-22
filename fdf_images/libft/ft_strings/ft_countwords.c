/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:31:52 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/23 16:36:58 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int			ft_countwords(const char *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s++ != c)
		{
			while (*s && *s != c)
				s++;
			count++;
		}
	}
	return (count);
}
