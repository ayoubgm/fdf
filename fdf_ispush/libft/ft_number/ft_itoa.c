/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:02:00 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/02 17:09:44 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int			ft_intlen(int nbr)
{
	int		len;
	int		value;

	len = 0;
	value = nbr;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	value = nbr;
	if (value < 0)
		len++;
	return (len);
}

char				*ft_itoa(int nbr)
{
	int		len;
	char	*ptr;
	int		value;

	len = ft_intlen(nbr);
	value = nbr;
	(nbr < 0) ? nbr *= -1 : nbr;
	if (!(ptr = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	ptr[len] = '\0';
	while (value)
	{
		ptr[--len] = (value % 10) + '0';
		value /= 10;
	}
	if (nbr < 0)
		ptr[0] = '-';
	return (ptr);
}
