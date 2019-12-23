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

char	*ft_itoa(int nbr)
{
    int len;
    char *ptr;
    int value;
    
    len = 0;
    value = nbr;
    while (value)
    {
        value /= 10;
        len++;
    }
    value = nbr;
    if (nbr < 0)
    {
        len++;
        value *= -1;
    }
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