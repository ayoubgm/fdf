/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:44:14 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/31 20:16:25 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		put_pixel_img(t_fdf *fdf, int x, int y, int couleur)
{
	if (y >= 0 && y <= HEIGTH_IMG && x >= 0 && x <= WIDTH_IMG)
		fdf->img_str[x + y * WIDTH_IMG] = couleur;
}

static void	slope_less_1(t_fdf *fdf, t_bresn bresen, t_point p0, t_point p1)
{
	while (p0.y != p1.y)
	{
		put_pixel_img(fdf, p0.x, p0.y, fdf->color);
		p0.y += bresen.stpy;
		bresen.am += bresen.dx;
		if (bresen.am >= bresen.dy)
		{
			p0.x += bresen.stpx;
			bresen.am -= bresen.dy;
		}
	}
}

static void	slope_greater_1(t_fdf *fdf, t_bresn brsn, t_point p0, t_point p1)
{
	while (p0.x != p1.x)
	{
		put_pixel_img(fdf, p0.x, p0.y, fdf->color);
		p0.x += brsn.stpx;
		brsn.am += brsn.dy;
		if (brsn.am >= brsn.dx)
		{
			p0.y += brsn.stpy;
			brsn.am -= brsn.dx;
		}
	}
}

void		drwln(t_fdf *fdf, t_point p0, t_point p1)
{
	t_bresn bresen;

	p0.x += fdf->map->mvx;
	p1.x += fdf->map->mvx;
	p0.y += fdf->map->mvy;
	p1.y += fdf->map->mvy;
	bresen.dx = p1.x - p0.x;
	bresen.dy = p1.y - p0.y;
	bresen.stpx = bresen.dx >= 0 ? 1 : -1;
	bresen.stpy = bresen.dy >= 0 ? 1 : -1;
	bresen.dx = bresen.dx >= 0 ? bresen.dx : bresen.dx * -1;
	bresen.dy = bresen.dy >= 0 ? bresen.dy : bresen.dy * -1;
	bresen.am = 0;
	if (bresen.dy > bresen.dx)
		slope_less_1(fdf, bresen, p0, p1);
	if (bresen.dx >= bresen.dy)
		slope_greater_1(fdf, bresen, p0, p1);
}

void		draw_shape(t_fdf *f)
{
	int		i;
	int		j;

	i = -1;
	while (++i < f->map->height)
	{
		j = -1;
		while (++j < f->map->width)
		{
			if (j + 1 < f->map->width)
			{
				if (f->map->iso == 0 && f->map->prll == 1)
					drwln(f, f->map->pts[i][j], f->map->pts[i][j + 1]);
				if (f->map->iso == 1 && f->map->prll == 0)
					drwln(f, f->map->p_iso[i][j], f->map->p_iso[i][j + 1]);
			}
			if (i + 1 < f->map->height)
			{
				if (f->map->iso == 0 && f->map->prll == 1)
					drwln(f, f->map->pts[i][j], f->map->pts[i + 1][j]);
				if (f->map->iso == 1 && f->map->prll == 0)
					drwln(f, f->map->p_iso[i][j], f->map->p_iso[i + 1][j]);
			}
		}
	}
}
