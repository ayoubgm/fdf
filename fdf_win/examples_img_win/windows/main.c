/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:53:51 by chzabakh          #+#    #+#             */
/*   Updated: 2019/11/12 20:12:44 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
	void *win_ptr2;
	char *str;
}				t_mlx;

int		key_press(int keycode, void *p)
{
	t_mlx	*s;

	s = (t_mlx *)p;
	puts(s->str);
	if (keycode == 4)
		mlx_string_put(s->mlx_ptr, s->win_ptr, 170, 210, 0xff, s->str);
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int close(void *param)
{
	(void)param;
	exit(0);
}

int main()
{
	t_mlx	s;

	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window(s.mlx_ptr, 500, 500, "fdf");
	mlx_pixel_put(s.mlx_ptr, s.win_ptr, 280,208, 0xf0134d);
	s.str = malloc(sizeof(5));
	int i = -1;
	while (++i < 4)
		s.str[i] = 'a';
	s.str[i] = '\0';
	mlx_string_put(s.mlx_ptr, s.win_ptr, 270, 210, 0xf0134d, "hello");
	mlx_hook(s.win_ptr, 2, 0, key_press, (void *)&s);
	mlx_hook(s.win_ptr, 17, 0, close, (void *)&s);
	mlx_loop(s.mlx_ptr);
	return (0);
}
