/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:31:01 by chzabakh          #+#    #+#             */
/*   Updated: 2019/11/12 20:13:04 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	ft_bresen( int x0, int y0, int x1, int y1, void *mlx_ptr, void * win_ptr)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int stpx = dx >= 0 ?1 : -1;
	int stpy = dy >= 0 ? 1:-1;
	dx = dx >= 0 ? dx: dx * -1;
	dy = dy >= 0 ? dy : dy * -1;
	int am = 0;
	if (dy > dx)
	{
		mlx_pixel_put(mlx_ptr, win_ptr,100 + x0 ,100+ y0, 0xf0134d);
		while (y0 != y1)
		{

			y0 += stpy;
			am += dx;
			if(am >= dy)
			{
				x0 += stpx;
				am -= dy;
			}
			mlx_pixel_put(mlx_ptr, win_ptr,100 + x0,100 + y0, 0xf0134d);
		}
	}

	if (dx >= dy)
	{
		mlx_pixel_put(mlx_ptr, win_ptr,100 + x0,100 + y0, 0xf0134d);
		while (x0 != x1)
		{

			x0 += stpx;
			am += dy;
			if(am >= dx)
			{
				y0 += stpy;
				am -= dx;
			}
			mlx_pixel_put(mlx_ptr, win_ptr,100 + x0, 100 + y0, 0xf0134d);
		}
	}
}


int main()
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "fdf");
	ft_bresen(4, 6, 16, 14, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}
