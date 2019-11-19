/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:10:45 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:46:48 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void		ft_putnstr(char const *str, size_t n)
{
	size_t	i;

	i = -1;
	if (str)
	{
		while (str[++i] && i < n)
			ft_putchar(str[i]);
	}
}
