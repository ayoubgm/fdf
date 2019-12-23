/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:06:02 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:46:41 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un = -1 * n;
	}
	else
		un = n;
	if (un >= 10)
		ft_putnbr_fd(un / 10, fd);
	ft_putchar_fd(un % 10 + '0', fd);
}
