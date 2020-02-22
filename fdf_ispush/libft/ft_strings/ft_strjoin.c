/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:20:20 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:47:51 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	int		size_c;
	char	*strc;

	if (s1 && s2)
	{
		size_s1 = ft_strlen(s1);
		size_s2 = ft_strlen(s2);
		size_c = size_s1 + size_s2;
		strc = (char *)ft_memalloc(sizeof(char) * (size_c + 1));
		if (strc == NULL)
			return (NULL);
		ft_strcat(strc, s1);
		ft_strcat(strc, s2);
		return (strc);
	}
	return (NULL);
}
