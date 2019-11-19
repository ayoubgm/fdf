/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:02:00 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:51:51 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

static int			ft_countdigit(unsigned int nb)
{
	int		cdigit;

	if (nb == 0)
		return (1);
	cdigit = 0;
	while (nb > 0)
	{
		cdigit++;
		nb /= 10;
	}
	return (cdigit);
}

static char			*strforzero(char *str)
{
	str[0] = '0';
	return (str);
}

char				*ft_itoa(int n)
{
	int				nc;
	char			*str;
	unsigned int	unb;

	unb = n < 0 ? -n : n;
	nc = 0;
	if (n < 0)
		nc++;
	nc += ft_countdigit(unb);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (nc + 1))))
		return (NULL);
	ft_bzero(str, nc);
	if (n == 0)
		return (strforzero(str));
	while (unb > 0)
	{
		str[nc - 1] = unb % 10 + '0';
		unb /= 10;
		nc--;
	}
	if (nc == 1)
		str[0] = '-';
	return (str);
}
