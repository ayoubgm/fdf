/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:13:30 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/19 03:46:15 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_fd(char *file)
{
	int fd1;
	int fd2;
	int	r;
	char buff[BUFFSIZE];

	if ((fd1 = open(file, O_RDONLY)) < 0 ||  (fd2 = open(file, O_RDONLY)) < 0)
	{
		(errno == 2) ? ft_putstr("No file") : printf("Failed to open");
		ft_putstr(file);
		ft_putstr(".\n");
		return(0);
	}
	if ((fd1 = open(file, O_RDONLY)))
	{
		if ((r = read(fd1, buff, BUFFSIZE)) == 0 || buff[0] == '\n')
			error("No data found.");
		close(fd1);	
	}
	return (fd2);
}

static	void		init_win_img(t_home *home)
{
	int		bpp;
	int		l;
	int		endian;

	home->mlx_ptr = mlx_init();
	home->win_ptr = mlx_new_window(home->mlx_ptr, 2560, 1395, "fdf");
	home->img_ptr = mlx_new_image(home->mlx_ptr, WIDTH_IMG, HEIGHT_IMG);
	home->img_str = (int*)mlx_get_data_addr(home->img_ptr, &(bpp), &(l), &(endian));
}

static t_home		*init(t_home *home)
{
	if (!(home = (t_home*)malloc(sizeof(t_home))))
		return (NULL);
	if (!(home->map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	return (home);
}

int		main(int ac, char **av)
{
	int		fd;
	int		r;
	t_home	*home;

	home = NULL;
	if (ac != 2)
		error("Usage : ./fdf <filename>\n");
	if (!(fd = check_fd(av[1])))
		exit(0);
	home = init(home);
	if (!(home))
		exit(0);
	if (!(r = read_file_stock(fd, home->map)))
		error("Error in data.");
	else if (r == 2)
		error("Found wrong line length. Exiting.\n");
	init_win_img(home);
    display_home_menu(home);
	draw_shape(home);
	mlx_hook(home->win_ptr, 2, 0, key_press, home);
	mlx_put_image_to_window(home->mlx_ptr, home->win_ptr, home->img_ptr, 300, 300);
	mlx_loop(home->mlx_ptr);
	return (0);
}