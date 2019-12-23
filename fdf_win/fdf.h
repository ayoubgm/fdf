/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:14:26 by gayoub            #+#    #+#             */
/*   Updated: 2019/11/23 21:57:45 by gayoub           ###   ########.fr       */
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

# define KEY_ONE        83
# define KEY_TWO        84
# define KEY_THREE      85
# define KEY_FOUR       86
# define KEY_FIVE       87
# define KEY_SIX        88
# define KEY_SEVEN      89
# define KEY_EIGHT      91
# define KEY_SHIFT      257
# define KEY_ESC        53
# define KEY_SPACE      49
# define KEY_UP         126
# define KEY_DOWN       125
# define KEY_MOVE_UP     13
# define KEY_MOVE_DOWN   1
# define KEY_MOVE_RIGHT  2
# define KEY_MOVE_LEFT   0
# define KEY_PROJ_PRLL 	35
# define KEY_PROJ_ISO 	34
# define SCROL_UP		4
# define SCROL_DOWN		5

# define BUFFSIZE       10000
# define WIDTH_WIN	  	2560
# define HEIGHT_WIN     1395

# define RED            16711680
# define BLUE           255
# define GREEN          44615
# define PURBLE         9642751
# define BROUWN         9786368
# define YELLOW         16767232
# define CYAN           65535
# define DRK_BLUE		39325

typedef struct		s_point
{
	int			x;
	int			y;
	int			z;
	int			couleur;
}					t_point;

typedef struct		s_map
{
	char		**lines;
	char		***prelines;
	int			width;
	int			height;
	int			mvx;
	int			mvy;
	long double		dist;
	int		h;
	int			iso;
	int			prll;
	t_point		**point;
	t_point		**points_iso;
}					t_map;

typedef struct		s_home
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_str;
	int			bpp;
	int			l;
	int			endian;
	int			color;
	int			fd;
	t_map		*map;
}					t_home;

typedef struct		s_bresn
{
	int			dx;
	int			dy;
	int			stpx;
	int			stpy;
	int			am;
}					t_bresn;

void				error(char *err);
void				display_home_menu(t_home *home);
int					read_file_stock(int fd2, t_map *map);
int					check_lines(char *lines);
int					check_data_with_color(char *color);
int					convert_stock(t_map *map);
void				put_pixel_img(t_home *home, int x, int y, int couleur);
void				draw_line(t_home *home, t_point p0, t_point p1);
void				draw_shape(t_home *home);
void				draw_iso_shape(t_home *home);
void				iso(t_point *p);
void				zoom_in(t_home *home);
int					mouse_press(int button, int x, int y, void *param);
int					key_press(int key, void *param);
int					mouse_press(int button, int x, int y, void *param);
void        		free_all(t_home *home);
void        		free_points(t_point **points);
#endif
