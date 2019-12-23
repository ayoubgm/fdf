/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:21:29 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/22 04:08:29 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        free_all(t_home *home)
{
    int i;

    i = 0;
    ft_strdel(home->map->lines);
    while (home->map->prelines[i])
    {
        ft_strdel(home->map->prelines[i]);
        i++;
    }
}

void        free_points(t_point **points)
{
    int i;

    i = -1;

    while (points[++i])
    {
        free(points[i]);
        points[i] = NULL;
    }
}