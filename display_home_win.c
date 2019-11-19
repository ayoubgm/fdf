/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_home_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:17:24 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/19 03:48:18 by gayoub           ###   ########.fr       */
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
			mlx_pixel_put(home->mlx_ptr, home->win_ptr, x, y, 38348);
			
	}
	y = 1295;
	while (y++ <= 1395)
	{
		x = 0;
		while (x++ <= 2560)
			mlx_pixel_put(home->mlx_ptr, home->win_ptr, x, y, 38348);
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
							home->win_ptr, 80, 300, 38348, "Zoom in      : +");
	mlx_string_put(home->mlx_ptr,
							home->win_ptr, 80, 330, 38348, "Zoom out     : -");
	mlx_string_put(home->mlx_ptr,
							home->win_ptr, 80, 360, 38348, "Altitude +   : up");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							80, 390, 38348, "Altitude -   : down");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							2240, 300, 38348, "Scroll to zoom  : +");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							2240, 330, 38348, "Move            : W A S D");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							2240, 360, 38348, "Projection ISO  : I");
	mlx_string_put(home->mlx_ptr, home->win_ptr,
							2240, 390, 38348, "Projection PRLL : P");
	
}

void			display_home_menu(t_home *home)
{
	put_area_of_pixel(home);
	display_menu_win(home);
}