/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_home_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:17:24 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/19 19:06:33 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			put_area_of_pixel(t_home *home)
{
	int x;
	int y;

	y = 0;
	while (y++ <= 150)
	{
		x = 0;
		while (x++ <= 2560)
			mlx_pixel_put(home->mlx_ptr, home->win_ptr, x, y, home->color);
			
	}
	y = 1295;
	while (y++ <= 1395)
	{
		x = 0;
		while (x++ <= 2560)
			mlx_pixel_put(home->mlx_ptr, home->win_ptr, x, y, home->color);
	}
}

static void				display_menu_win(t_home *home)
{
	int i;

	i = 0;
	put_area_of_pixel(home);
	mlx_string_put(home->mlx_ptr,
							home->win_ptr, 1240, 50, 16777215, "FDF 1337");
	mlx_string_put(home->mlx_ptr,
							home->win_ptr, 80, 300, home->color, "Zoom in      : +");
	mlx_string_put(home->mlx_ptr,
							home->win_ptr, 80, 330, home->color, "Zoom out     : -");
	mlx_string_put(home->mlx_ptr,
							home->win_ptr, 80, 360, home->color, "Altitude +   : up");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							80, 390, home->color, "Altitude -   : down");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							2240, 300, home->color, "Scroll to zoom  : +");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							2240, 330, home->color, "Move            : W A S D");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							2240, 360, home->color, "Projection ISO  : I");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							2240, 390, home->color, "Projection PRLL : P");
	
}

void			display_home_menu(t_home *home)
{
	put_area_of_pixel(home);
	display_menu_win(home);
}