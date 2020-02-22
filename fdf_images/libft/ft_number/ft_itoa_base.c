/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 05:13:49 by jaleman           #+#    #+#             */
/*   Updated: 2019/12/02 17:10:24 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_intlen(int nbr, int base)
{
	int		value;
	int		len;

	value = nbr;
	len = 0;
	while (value)
	{
		value /= base;
		len++;
	}
	value = nbr;
	if (nbr < 0)
		if (base == 10)
			len++;
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	int		len;
	int		nbr;
	char	*pointer;
	char	*base_string;

	base_string = "0123456789ABCDEF";
	if (value == 0)
		return ("0");
	len = ft_intlen(value, base);
	nbr = value;
	(nbr < 0) ? nbr *= -1 : nbr;
	if (!(pointer = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	pointer[len] = '\0';
	while (nbr)
	{
		pointer[--len] = base_string[nbr % base];
		nbr /= base;
	}
	if (value < 0 && base == 10)
		pointer[0] = '-';
	return (pointer);
}
