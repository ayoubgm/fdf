/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:14:26 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/19 03:51:08 by gayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/headers/libft.h"
# include "libft/headers/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_ZOOM_IN 24
# define KEY_ZOOM_OUT 27
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_ROT_UP 13
# define KEY_ROT_DOWN 1
# define KEY_ROT_RIGHT 2
# define KEY_ROT_LEFT 0
# define KEY_PROJ_ISO 34
# define KEY_PROJ_PRLL 35
# define BUFFSIZE 10000
# define RED 16711680

# define WIDTH_IMG 1900
# define HEIGHT_IMG 900

typedef struct      s_camera
{
    int             iso;
    int             parll;
}                   t_camera;

typedef struct      s_point
{
    int		x;
	int		y;
	int		z;
	int		couleur;
    int     offst;
}                   t_point;

typedef struct      s_map
{
    char            **lines;
    char            ***prelines;
    int             **digits;
    int             width;
    int             height;
    t_point         **point;
    t_camera        *camera;
}                   t_map;


typedef struct      s_home
{
    void            *mlx_ptr;
    void            *win_ptr;
    void            *img_ptr;
    int             *img_str;
    int             dx;
	int             dy;
	int             stpx;
	int             stpy;
	int             am;
    t_map           *map;
}                  t_home;

void        error(char *err);
void		display_home_menu(t_home *home);
int 		read_file_stock(int fd2, t_map *map);
int			check_lines(char *lines);
int			check_data_with_color(char *color);
int			convert_stock(t_map *map);
void        put_pixel_img(t_home *home, int x, int y, int couleur);
void		draw_line(t_home *home, t_point p0, t_point p1);
void		draw_shape(t_home *home);
void        iso(t_point *p);
int 		key_press(int key,  void *param);

#endif