/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:17:24 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/31 20:16:15 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void				put_area_of_pixel(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y++ <= 100)
	{
		x = 0;
		while (x++ <= 370)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, WHITE);
	}
	y = 1295;
	while (y++ <= 1395)
	{
		x = 0;
		while (x++ <= 370)
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, WHITE);
	}
}

static void				display_menu_win(t_fdf *fdf)
{
	put_area_of_pixel(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
							140, 50, BLACK, "FDF 1337");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
							18, 300, WHITE, "Projection ISO  : I");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
							18, 340, WHITE, "Projection PRLL : P");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
							18, 380, WHITE, "Zoom            : Scroll to zoom");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
							18, 420, WHITE, "Move            : W A S D");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
							18, 460, WHITE, "Altitude +      : 1");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
							18, 500, WHITE, "Altitude -      : 2");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 18,
							540, WHITE, "Choose colors   : 1/2/3/4/5/6/7/8");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr,
							100, 580, BLACK, "Author : gayoub");
}

void					display_fdf_menu(t_fdf *fdf)
{
	put_area_of_pixel(fdf);
	display_menu_win(fdf);
}
