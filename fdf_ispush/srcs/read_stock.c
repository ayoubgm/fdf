/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:49:17 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/31 20:17:23 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int					convert_stock(t_map *map)
{
	int			i;
	int			j;

	i = -1;
	calc_dist(map);
	if (!(map->pts = (t_point**)malloc(sizeof(t_point*) * map->height)) ||
		!(map->p_iso = (t_point**)malloc(sizeof(t_point*) * map->height)))
		return (0);
	while (++i < map->height)
	{
		j = -1;
		if (!(map->pts[i] = (t_point*)malloc(sizeof(t_point) * map->width)) ||
		!(map->p_iso[i] = (t_point*)malloc(sizeof(t_point) * map->width)))
			return (0);
		while (++j < map->width)
		{
			map->pts[i][j].x = j * map->dist + WIDTH_IMG / 2 -
												(map->width * map->dist) / 2;
			map->pts[i][j].y = i * map->dist + HEIGTH_IMG / 2 -
												(map->height * map->dist) / 2;
			map->pts[i][j].z = ft_atoi(map->prelines[i][j]) * map->dist;
		}
	}
	return (1);
}

static int					get_width_shape(t_map *map)
{
	int			i;
	int			j;
	int			width;

	i = -1;
	width = 0;
	while (++i < map->height)
	{
		j = -1;
		while (map->prelines[i][++j])
			;
		if (i != 0 && width < j)
			return (-2);
		width = j;
	}
	return (width);
}

static int					spliting(t_fdf *fdf, char *all)
{
	int			i;
	int			j;

	i = 0;
	j = -1;
	fdf->map->lines = ft_strsplit(all, '\n');
	while (fdf->map->lines[i])
		i++;
	fdf->map->height = i;
	fdf->map->prelines = (char ***)ft_memalloc(sizeof(char**) *
														fdf->map->height);
	while (++j < fdf->map->height)
		fdf->map->prelines[j] = ft_strsplit(fdf->map->lines[j], ' ');
	if ((fdf->map->width = get_width_shape(fdf->map)) == -2 ||
												!convert_stock(fdf->map))
	{
		free_lines(fdf);
		free_prelines(fdf);
		return ((fdf->map->width == -2) ? (2) : (0));
	}
	return (1);
}

void						read_file_stock(t_fdf *fdf)
{
	int			rd;
	int			s;
	char		buff[BUFFSIZE + 1];
	char		*tmp;
	char		*all;

	if (!(all = ft_strnew(0)))
		error("Error.\n", NULL, fdf);
	while ((rd = read(fdf->fd, buff, BUFFSIZE)))
	{
		buff[rd] = '\0';
		if (!(tmp = ft_strjoin(all, buff)))
			error("Error.\n", all, fdf);
		free(all);
		all = tmp;
	}
	close(fdf->fd);
	if (!(s = spliting(fdf, all)))
		error("Error.\n", all, fdf);
	else if (s == 2)
		error("Found wrong line length. Exiting.\n", all, fdf);
	free(all);
}
