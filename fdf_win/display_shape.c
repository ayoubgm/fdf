/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:44:14 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/24 00:00:22 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		slope_less_1(t_home *home, t_bresn bresen, t_point p0, t_point p1)
{
	while (p0.y != p1.y)
	{
		mlx_pixel_put(home->mlx_ptr, home->win_ptr, p0.x + home->map->mvx, p0.y + home->map->mvy, home->color);
		p0.y += bresen.stpy;
		bresen.am += bresen.dx;
		if(bresen.am >= bresen.dy)
		{
			p0.x += bresen.stpx;
			bresen.am -= bresen.dy;
		}
	}
}

static void		slope_greater_1(t_home *home, t_bresn bresen, t_point p0, t_point p1)
{
	while (p0.x != p1.x)
	{
		mlx_pixel_put(home->mlx_ptr, home->win_ptr, p0.x + home->map->mvx, p0.y + home->map->mvy, home->color);
		p0.x += bresen.stpx;
		bresen.am += bresen.dy;
		if(bresen.am >= bresen.dx)
		{
			p0.y += bresen.stpy;
			bresen.am -= bresen.dx;
		}
	}
}

void		draw_line(t_home *home, t_point p0, t_point p1)
{
	t_bresn bresen;

	bresen.dx = p1.x - p0.x;
	bresen.dy= p1.y - p0.y;
	bresen.stpx = bresen.dx >= 0 ? 1 : -1;
	bresen.stpy = bresen.dy >= 0 ? 1 : -1;
	bresen.dx = bresen.dx >= 0 ? bresen.dx : bresen. dx * -1;
	bresen.dy = bresen.dy >= 0 ? bresen.dy : bresen.dy * -1;
	bresen.am= 0;
	if (bresen.dy > bresen.dx)
		slope_less_1(home, bresen, p0, p1);
	if (bresen.dx >= bresen.dy)
		slope_greater_1(home, bresen, p0, p1);
}

void        draw_shape(t_home *home)
{
	int i;
	int j;
	
	i = -1;
	while (++i < home->map->height)
	{
		j = -1;
		while (++j < home->map->width)
		{
			if (j + 1 < home->map->width && j + 1 < WIDTH_WIN && i < HEIGHT_WIN)
			{
				if (home->map->iso == 0 && home->map->prll == 1)
					draw_line(home, home->map->point[i][j], home->map->point[i][j + 1]);
				if (home->map->iso == 1 && home->map->prll == 0)
				{
					draw_line(home, home->map->points_iso[i][j], home->map->points_iso[i][j + 1]);
				}
			}
			if (i + 1 < home->map->height && i + 1 < HEIGHT_WIN && j < WIDTH_WIN)
			{
				if (home->map->iso == 0 && home->map->prll == 1)
					draw_line(home, home->map->point[i][j], home->map->point[i + 1][j]);
				if (home->map->iso == 1 && home->map->prll == 0)
				{
					draw_line(home, home->map->points_iso[i][j], home->map->points_iso[i + 1][j]);
				}
			}
		}
	}
	// mlx_pixel_put(home->mlx_ptr, home->win_ptr, 900,500, RED);
}