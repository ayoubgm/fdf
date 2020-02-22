/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:49:17 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/23 23:35:47 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_dist(t_map *map)
{
	int dist_hei = 1;
	int dist_widt = 1;

	map->dist = 1;
	while (map->width * dist_widt <= WIDTH_WIN / 3)
		dist_widt++;
	while (map->height * dist_hei <= HEIGHT_WIN / 3)
		dist_hei++;
	map->dist = dist_hei > dist_widt ? dist_widt : dist_hei;
}


int			convert_stock(t_map *map)
{
	int i;
	int j;

	i = -1;
	calc_dist(map);
	if (!(map->point = (t_point**)malloc(sizeof(t_point*) * map->height)))
		return (0);
	if (!(map->points_iso = (t_point**)malloc(sizeof(t_point*) * map->height)))
		return (0);
	while (++i < map->height)
	{
		j = -1;
		if (!(map->point[i] = (t_point*)malloc(sizeof(t_point) * map->width)))
			return (0);
		if (!(map->points_iso[i] = (t_point*)malloc(sizeof(t_point) * map->width)))
			return (0);
		while (map->prelines[i][++j])
		{
			map->point[i][j].x = j * map->dist + WIDTH_WIN / 2 - (map->width * map->dist) / 2;
			map->point[i][j].y = i * map->dist + HEIGHT_WIN / 2 - (map->height * map->dist) / 2;
			map->point[i][j].z = ft_atoi(map->prelines[i][j]) * map->dist;
			map->points_iso[i][j].x = j * map->dist + WIDTH_WIN / 2 - (map->width * map->dist) / 2;
			map->points_iso[i][j].y = i * map->dist + HEIGHT_WIN / 2 - (map->height * map->dist) / 2;
			map->points_iso[i][j].z = ft_atoi(map->prelines[i][j]) * map->dist;
			iso(&map->points_iso[i][j]);
		}
	}
	return (1);
}

int				check_lines(char *lines)
{
	int i;
	
	i = -1;
	while (lines[++i])
	{
		while (lines[i] == ' ' || lines[i] == '-' || lines[i] == ',')
			i++;
		if (!ft_isdigit(lines[i]) || !(i = ft_strlen(lines) - 1))
			return (0);
	}
	return (1);
}

int		get_width_shape(t_map *map)
{
	int i;
	int j;
	int width;

	i = 0;
	width = 0;
	while (i < map->height)
	{
		j = -1;
		while (map->prelines[i][++j]) ;
		if (i != 0 && width < j)
			return (-2);
		width = j;
		i++;
	}
	return (width);
}

int		spliting(t_map *map, char *all)
{
	int i = -1;
	int j = 0;

	if (!(map->lines = ft_strsplit(all, '\n')))
		return (0);
	while (map->lines[++i])
		if (!check_lines(map->lines[i]))
			return (0);
	map->height = i;
	if (!(map->prelines = (char ***)ft_memalloc(sizeof(char**) * map->height)))
		return (0);
	while (j < map->height)
	{
		map->prelines[j] = ft_strsplit(map->lines[j], ' ');
		j++;
	}
	if ((map->width = get_width_shape(map)) == -2)
		return (2);
	if (!convert_stock(map))
		return (0);
	return (1);
}

int		read_file_stock(int fd2, t_map *map)
{
	int rd;
	char buff[BUFFSIZE + 1];
	char *all;
	char *tmp;
	int s;

	all = ft_strnew(0);
	while ((rd = read(fd2, buff, BUFFSIZE)))
	{

		buff[rd] = '\0';
		tmp = ft_strjoin(all, buff);
		ft_strdel(&all);
		all = tmp;
	}
	if (!(s = spliting(map, all)))
		return (0);
	else if (s == 2)
		return (2);
	return (1);
}