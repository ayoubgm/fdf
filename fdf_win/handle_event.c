/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:03:29 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/23 23:44:17 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_point *p)
{
    int previous_x;
    int previous_y;

    previous_x = p->x;
    previous_y = p->y;
    p->x = (previous_x - previous_y) * cos(0.523599);
    p->y = (previous_x + previous_y) * sin(0.523599) - p->z * 0.5;
}

void		reset(t_home *home)
{
	mlx_clear_window(home->mlx_ptr, home->win_ptr);
	display_home_menu(home);
	draw_shape(home);
}

void		gest_colors(int key, t_home *home)
{
	if (key == KEY_ONE)
	{
		home->color = DRK_BLUE;
		reset(home);
	}
	else if (key == KEY_TWO)
	{
		home->color = CYAN;
		reset(home);
	}
	else if (key == KEY_THREE)
	{
		home->color = YELLOW;
		reset(home);
	}
	else if (key == KEY_FOUR)
	{
		home->color = BROUWN;
		reset(home);
	}
	else if (key == KEY_FIVE)
	{
		home->color = PURBLE;
		reset(home);
	}
	else if (key == KEY_SIX)
	{
		home->color = GREEN;
		reset(home);
	}
	else if (key == KEY_SEVEN)
	{
		home->color = BLUE;
		reset(home);
	}
	else if (key == KEY_EIGHT)
	{
		home->color = RED;
		reset(home);
	}
}

int			key_press(int key,  void *param)
{
	t_home *home;

	home = (t_home *)param;
	gest_colors(key, home);
	if (key == KEY_ESC)
        exit(0);
	/****		projection		****/
	else if (key == KEY_PROJ_PRLL)
	{
		home->map->iso = 0;
		home->map->prll = 1;
		home->map->mvx = 0;
		home->map->mvy = 0;
		reset(home);
	}
	else if (key == KEY_PROJ_ISO)
	{
		home->map->prll = 0;
		home->map->iso = 1;
		home->map->mvx = 0;
		home->map->mvy = 0;
		reset(home);
	}
	else if (key == KEY_MOVE_DOWN){
		home->map->mvy+=50;
		reset(home);
	}
	else if (key == KEY_MOVE_UP){
		home->map->mvy-=50;
		reset(home);
	}
	else if (key == KEY_MOVE_LEFT){
		home->map->mvx-= 50;
		reset(home);
	}
	else if (key == KEY_MOVE_RIGHT){
		home->map->mvx+= 50;
		reset(home);
	}
	return(0);
}

int mouse_press(int button, int x, int y, void *param)
{
	t_home *home;

	home = (t_home *)param;
	x = 0;
	y = 0;
	if (button == SCROL_UP)
	{
		home->map->dist--;
		reset(home);
	}
	else if (button == SCROL_DOWN)
	{
		home->map->dist++;
		reset(home);
	}
	return (0);
}