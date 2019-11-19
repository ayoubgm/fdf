/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:03:29 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/19 18:31:44 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_home *home)
{
	mlx_clear_window(home->mlx_ptr, home->win_ptr);
	display_home_menu(home);
	draw_shape(home);
	mlx_put_image_to_window(home->mlx_ptr, home->win_ptr, home->img_ptr, 300, 300);
}

void iso(t_point *p)
{
    int previous_x;
    int previous_y;

    previous_x = p->x;
    previous_y = p->y;
    p->x = (previous_x - previous_y) * cos(0.523599);
    p->y = (previous_x + previous_y) * sin(0.523599) - p->z;
}

void		zoom_in(t_home *home)
{
	home->map->zoom->zoom += 2;
	reset(home);
}

void		gest_colors(int key, t_home *home)
{
	if (key == KEY_ONE)
		home->color = DRK_BLUE;
	else if (key == KEY_TWO)
		home->color = CYAN;
	else if (key == KEY_THREE)
		home->color = YELLOW;
	else if (key == KEY_FOUR)
		home->color = BROUWN;
	else if (key == KEY_FIVE)
		home->color = PURBLE;
	else if (key == KEY_SIX)
		home->color = GREEN;
	else if (key == KEY_SEVEN)
		home->color = BLUE;
	else if (key == KEY_EIGHT)
		home->color = RED;
	reset(home);
}

int			key_press(int key,  void *param)
{
	t_home *home;

	home = (t_home *)param;
	gest_colors(key, home);
	if (key == KEY_ESC)
        exit(0);
	/****		projection		****/
	else if (key == KEY_PROJ_ISO){
		// projection iso
	}
	else if (key == KEY_PROJ_PRLL){
		// projection parll
	}

	/****		  zoom			****/
	else if (key == KEY_ZOOM_IN){
		zoom_in(home);
	}
	else if (key == KEY_ZOOM_OUT){
		// function to zoom out
	}

	/****		altitude		****/
	else if (key == KEY_UP){
		// function to up the altitude
	}
	else if (key == KEY_DOWN){
		// function to down the altitude
	}

	/****		rotation		****/
	else if (key == KEY_ROT_UP){
		// function to rotate the shape to the top
	}
	else if (key == KEY_ROT_RIGHT){
		// function to rotate the shape to the right
	}
	else if (key == KEY_ROT_DOWN){
		// function to rotate the shape down
	}
	else if (key == KEY_ROT_LEFT){
		// function to rotate the shape to the left
	}
	return(0);
}