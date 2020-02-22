/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:13:30 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/31 20:17:57 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void				init_win_img(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 2560, 1395, "fdf");
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH_IMG, HEIGTH_IMG);
	fdf->img_str = (int*)mlx_get_data_addr(fdf->img_ptr, &(fdf->bpp),
													&fdf->l, &fdf->endian);
}

t_fdf				*init(void)
{
	t_fdf *fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		return (NULL);
	fdf->color = DRK_BLUE;
	if (!(fdf->map = (t_map*)malloc(sizeof(t_map))))
	{
		ft_memdel((void**)&fdf);
		return (NULL);
	}
	fdf->map->h = 0.1;
	fdf->map->mvx = 0;
	fdf->map->mvy = 0;
	fdf->map->iso = 0;
	fdf->map->prll = 1;
	fdf->map->teta = 0;
	return (fdf);
}

int					check_fd(char *file, t_fdf *fdf)
{
	int		r;
	int		fd1;
	int		fd2;
	char	buff[BUFFSIZE];

	fd1 = open(file, O_RDONLY);
	fd2 = open(file, O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		(errno == 2) ? error("No such file.\n", NULL, fdf) :
									error("Failed to open.\n", NULL, fdf);
	}
	if ((r = read(fd1, buff, BUFFSIZE)) == 0 || buff[0] == '\n' || r < 0)
		error("No data found.\n", NULL, fdf);
	close(fd1);
	return (fd2);
}

int					main(int ac, char **av)
{
	t_fdf	*fdf;

	if (!(fdf = init()))
		exit(EXIT_FAILURE);
	if (ac != 2)
		error("Usage : ./fdf <filename>\n", NULL, fdf);
	fdf->fd = check_fd(av[1], fdf);
	read_file_stock(fdf);
	init_win_img(fdf);
	display_fdf_menu(fdf);
	draw_shape(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
													fdf->img_ptr, 370, 0);
	mlx_loop(fdf->mlx_ptr);
	exit(EXIT_SUCCESS);
}
