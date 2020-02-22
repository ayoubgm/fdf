/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:13:30 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/23 23:28:12 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void		init_win(t_home *home)
{
	home->mlx_ptr = mlx_init();
	home->win_ptr = mlx_new_window(home->mlx_ptr, WIDTH_WIN, HEIGHT_WIN, "fdf");
}

static t_home		*init(t_home *home)
{
	if (!(home = (t_home*)malloc(sizeof(t_home))))
		return (NULL);
	home->color = DRK_BLUE;
	if (!(home->map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	home->map->h = 4;
	home->map->mvx = 0;
	home->map->mvy = 0;
	home->map->iso = 0;
	home->map->prll = 1;
	return (home);
}

int		check_fd(char *line)
{
	int		r;
	int fd1;
	int fd2;
	char buff[BUFFSIZE];

	if ((fd1 = open(line, O_RDONLY)) < 0 ||  (fd2 = open(line, O_RDONLY)) < 0)
	{
		(errno == 2) ? printf("No file %s.\n", line) : printf("Failed to open %s.\n", line);
		return(0);
	}
	if ((fd1 = open(line, O_RDONLY)))
	{
		if ((r = read(fd1, buff, BUFFSIZE)) == 0 || buff[0] == '\n')
		{
			printf("No data found.\n");
			return (0);
		}
		close(fd1);	
	}
	return (fd2);
}

int		main(int ac, char **av)
{
	int		r;
	t_home	*home;

	home = NULL;
	if (ac != 2)
		error("Usage : ./fdf <filename>\n");;
	if (!(home = init(home)))
		exit(0);
	if (!(home->fd = check_fd(av[1])))
		exit(0);
	if (!(home))
		exit(0);
	if (!(r = read_file_stock(home->fd, home->map)))
		error("Error in data.\n");
	else if (r == 2)
		error("Found wrong line length. Exiting.\n");
	init_win(home);
    display_home_menu(home);
	draw_shape(home);
	mlx_hook(home->win_ptr, 2, 0, key_press, home);
	mlx_hook(home->win_ptr, 4, 0, mouse_press, home);
	mlx_loop(home->mlx_ptr);
	return (0);
}