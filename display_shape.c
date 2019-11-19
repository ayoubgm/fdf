/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:44:14 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/19 19:09:21 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        put_pixel_img(t_home *home, int x, int y, int couleur)
{
    home->img_str[(x + (y * WIDTH_IMG))] = couleur;
}

static void		slope_less_1(t_home *home, t_point p0, t_point p1)
{
	while (p0.y != p1.y)
	{
		put_pixel_img(home, p0.x, p0.y, home->color);
		p0.y += home->stpy;
		home->am += home->dx;
		if(home->am >= home->dy)
		{
			p0.x += home->stpx;
			home->am -= home->dy;
		}
	}
}

static void		slope_greater_1(t_home *home, t_point p0, t_point p1)
{
	while (p0.x != p1.x)
	{
		put_pixel_img(home, p0.x, p0.y, home->color);
		p0.x += home->stpx;
		home->am += home->dy;
		if(home->am >= home->dx)
		{
			p0.y += home->stpy;
			home->am -= home->dx;
		}
	}
}


void		draw_line(t_home *home, t_point p0, t_point p1)
{
	home->dx = p1.x - p0.x;
	home->dy= p1.y - p0.y;
	home->stpx = home->dx >= 0 ? 1 : -1;
	home->stpy = home->dy >= 0 ? 1 : -1;
	home->dx = home->dx >= 0 ? home->dx : home-> dx * -1;
	home->dy = home->dy >= 0 ? home->dy : home->dy * -1;
	home->am= 0;
	if (home->dy > home->dx)
		slope_less_1(home, p0, p1);
	if (home->dx >= home->dy)
		slope_greater_1(home, p0, p1);
}

void        draw_shape(t_home *home)
{
	int i;
	int j;
	
	i = 0;
	while (i < home->map->height)
	{
		j = 0;
		while (j < home->map->width)
		{
			if (j + 1 < home->map->width && home->map->point[i][j + 1].x < WIDTH_IMG && home->map->point[i][j + 1].y < HEIGHT_IMG)
				draw_line(home,home->map->point[i][j],home->map->point[i][j + 1]);
			if (i + 1 < home->map->height && home->map->point[i + 1][j].x < WIDTH_IMG && home->map->point[i + 1][j].y < HEIGHT_IMG)
				draw_line(home,home->map->point[i][j],home->map->point[i + 1][j]);
			j++;
		}
		i++;
	}
	// put_pixel_img(home, 500, 255, RED); 
}
