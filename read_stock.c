/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:49:17 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/19 04:01:28 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			convert_stock(t_map *map)
{
	int i;
	int j;

	i = -1;
	if (!(map->point = (t_point**)malloc(sizeof(t_point*) * map->height)))
		return (0);
	while (++i < map->height)
	{
		j = -1;
		if (!(map->point[i] = (t_point*)malloc(sizeof(t_point) * map->width)))
			return (0);
		while (map->prelines[i][++j])
		{
			map->point[i][j].x = (j + 50)*20;
			map->point[i][j].y = (i) * 20;
			map->point[i][j].z = ft_atoi(map->prelines[i][j]) + map->point[i][j].offst;
			iso(&map->point[i][j]);
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
		while (lines[i] == ' ' || lines[i] == '-')
			i++;
		if (lines[i] == ',')
		{
			i++;
			while(lines[i] != ' ')
			{
				if (lines[i] == 'x')
					i++;
				if (!ft_isxdigit(lines[i]))
					return (0);
				i++;
			}
			while (lines[i] == ' ')
				i++;
		}
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
		j = 0;
		while (map->prelines[i][j])
		{
			j++;
		}
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

	all = ft_strnew(0);
	while ((rd = read(fd2, buff, BUFFSIZE)))
	{
		buff[rd] = '\0';
		tmp = ft_strjoin(all, buff);
		ft_strdel(&all);
		all = tmp;
	}
	if (!(spliting(map, all)))
		return (0);
	else if ((spliting(map, all)) == 2)
		return (2);
	return (1);
}