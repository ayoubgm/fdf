/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 05:37:00 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/31 20:16:51 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void				iso(t_point *p, double h)
{
	int		previous_x;
	int		previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = (previous_x - previous_y) * cos(0.523599);
	p->y = (previous_x + previous_y) * sin(0.523599) - p->z * h;
}

void				change_altitude(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->p_iso[i][j].x = map->pts[i][j].x + 20;
			map->p_iso[i][j].y = map->pts[i][j].y - 500;
			map->p_iso[i][j].z = map->pts[i][j].z;
			iso(&map->p_iso[i][j], map->h);
		}
	}
}

void				calc_dist(t_map *map)
{
	int		dist_hei;
	int		dist_widt;

	dist_hei = 1;
	dist_widt = 1;
	map->dist = 1;
	while (map->width * dist_widt <= WIDTH_IMG / 2)
		dist_widt++;
	while (map->height * dist_hei <= HEIGTH_IMG / 2)
		dist_hei++;
	map->dist = dist_hei > dist_widt ? dist_widt : dist_hei;
}

void				change_zoom(t_map *map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (map->prelines[i][++j])
		{
			map->pts[i][j].x = j * map->dist + WIDTH_IMG / 2 -
												(map->width * map->dist) / 2;
			map->pts[i][j].y = i * map->dist + HEIGTH_IMG / 2 -
												(map->height * map->dist) / 2;
			map->pts[i][j].z = ft_atoi(map->prelines[i][j]) * map->dist;
			map->p_iso[i][j].x = map->pts[i][j].x + 20;
			map->p_iso[i][j].y = map->pts[i][j].y - 500;
			map->p_iso[i][j].z = map->pts[i][j].z;
			iso(&map->p_iso[i][j], map->h);
		}
	}
}
