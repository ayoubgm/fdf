/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:03:29 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/31 20:17:14 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void			reset(t_fdf *fdf)
{
	ft_bzero(fdf->img_str, WIDTH_IMG * HEIGTH_IMG * 4);
	draw_shape(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
														fdf->img_ptr, 370, 0);
}

static void			keys_colors_moves(int key, t_fdf *fdf)
{
	if (key == KEY_ONE)
		fdf->color = DRK_BLUE;
	else if (key == KEY_TWO)
		fdf->color = CYAN;
	else if (key == KEY_THREE)
		fdf->color = YELLOW;
	else if (key == KEY_FOUR)
		fdf->color = BROUWN;
	else if (key == KEY_FIVE)
		fdf->color = PURBLE;
	else if (key == KEY_SIX)
		fdf->color = GREEN;
	else if (key == KEY_SEVEN)
		fdf->color = BLUE;
	else if (key == KEY_EIGHT)
		fdf->color = RED;
	else if (key == KEY_MOVE_DOWN)
		fdf->map->mvy += 50;
	else if (key == KEY_MOVE_UP)
		fdf->map->mvy -= 50;
	else if (key == KEY_MOVE_LEFT)
		fdf->map->mvx -= 50;
	else if (key == KEY_MOVE_RIGHT)
		fdf->map->mvx += 50;
}

static void			keys_projection(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
	{
		free_all(fdf);
		exit(0);
	}
	if (key == KEY_PROJ_PRLL)
	{
		fdf->map->iso = 0;
		fdf->map->prll = 1;
		fdf->map->mvx = 0;
		fdf->map->mvy = 0;
		fdf->map->h = 0.1;
		calc_dist(fdf->map);
		change_zoom(fdf->map);
	}
	else if (key == KEY_PROJ_ISO)
	{
		fdf->map->prll = 0;
		fdf->map->iso = 1;
		fdf->map->mvx = 0;
		fdf->map->mvy = 0;
		fdf->map->h = 0.1;
		calc_dist(fdf->map);
		change_zoom(fdf->map);
	}
}

int					key_press(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	keys_projection(key, fdf);
	keys_colors_moves(key, fdf);
	if (key == KEY_ALTT_UP)
	{
		if (fdf->map->h < 3)
			fdf->map->h += 0.1;
		change_altitude(fdf->map);
	}
	else if (key == KEY_ALTT_DOWN)
	{
		if (fdf->map->h > -1)
			fdf->map->h -= 0.1;
		change_altitude(fdf->map);
	}
	reset(fdf);
	return (0);
}

int					mouse_press(int button, int x, int y, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	x += x;
	y += y;
	if (button == 5)
	{
		if (fdf->map->dist < 400)
		{
			fdf->map->dist += 2;
			change_zoom(fdf->map);
		}
	}
	else if (button == 4)
	{
		if (fdf->map->dist > 2)
		{
			fdf->map->dist -= 2;
			change_zoom(fdf->map);
		}
	}
	reset(fdf);
	return (0);
}
