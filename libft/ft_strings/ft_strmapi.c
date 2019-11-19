/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:03:29 by gayoub            #+#    #+#             */
/*   Updated: 2019/10/31 15:48:03 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ps;

	if (s && f)
	{
		i = 0;
		ps = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (ps == NULL)
			return (NULL);
		while (s[i])
		{
			ps[i] = f(i, s[i]);
			i++;
		}
		ps[i] = '\0';
		return (ps);
	}
	return (NULL);
}
