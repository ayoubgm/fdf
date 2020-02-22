/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:21:29 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/31 20:16:39 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			free_lines(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->map->height)
		ft_strdel(&fdf->map->lines[i]);
	ft_strdel(fdf->map->lines);
}

void			free_prelines(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->map->height)
	{
		j = -1;
		while (++j < fdf->map->width)
			ft_strdel(&fdf->map->prelines[i][j]);
		ft_strdel(fdf->map->prelines[i]);
	}
}

void			free_points(t_fdf *fdf)
{
	int		i;

	i = -1;
	while (++i < fdf->map->height)
		ft_memdel((void**)&fdf->map->pts[i]);
	ft_memdel((void**)fdf->map->pts);
	i = -1;
	while (++i < fdf->map->height)
		ft_memdel((void**)&fdf->map->p_iso[i]);
	ft_memdel((void**)fdf->map->p_iso);
}

void			free_all(t_fdf *fdf)
{
	free_lines(fdf);
	free_prelines(fdf);
	free_points(fdf);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf);
}
