/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:03:29 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/19 03:51:12 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int key,  void *param)
{
	t_home *home;

	home = (t_home *)param;
	if (key == KEY_ESC)
        exit(0);
	else if (key == KEY_PROJ_ISO){
		// funtion to zoom in
	}
	else if (key == KEY_PROJ_PRLL){
		// funtion to zoom in
	}
	else if (key == KEY_ZOOM_IN){
		// funtion to zoom in
	}
	else if (key == KEY_ZOOM_OUT){
		// function to zoom out
	}
	else if (key == KEY_UP){
		// function to up the altitude
	}
	else if (key == KEY_DOWN){
		// function to down the altitude
	}
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

void iso(t_point *p)
{
    int previous_x;
    int previous_y;

    previous_x = p->x;
    previous_y = p->y;
    p->x = (previous_x - previous_y) * cos(0.523599);
    p->y = (previous_x + previous_y) * sin(0.523599) - p->z;
}
