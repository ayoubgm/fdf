/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gayoub <gayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:14:26 by gayoub            #+#    #+#             */
/*   Updated: 2019/12/23 18:50:28 by gayoub           ###   ########.fr       */
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
# define KEY_ESC        53
# define KEY_PROJ_PRLL 	35
# define KEY_PROJ_ISO 	34
# define KEY_ALTT_UP    18
# define KEY_ALTT_DOWN  19
# define KEY_MOVE_UP    13
# define KEY_MOVE_DOWN  1
# define KEY_MOVE_RIGHT 2
# define KEY_MOVE_LEFT  0
# define BUFFSIZE       10000
# define WIDTH_IMG	  	2260
# define HEIGTH_IMG     1420
# define WHITE			16777215
# define BLACK			0
# define RED            16711680
# define BLUE           255
# define GREEN          44615
# define PURBLE         9642751
# define BROUWN         9786368
# define YELLOW         16767232
# define CYAN			65535
# define DRK_BLUE		39325

typedef struct			s_point
{
	int			x;
	int			y;
	int			z;
	int			couleur;
}						t_point;

typedef struct			s_map
{
	int			iso;
	int			width;
	int			prll;
	int			height;
	int			mvx;
	int			mvy;
	double		dist;
	double		h;
	double		teta;
	char		***prelines;
	char		**lines;
	t_point		**pts;
	t_point		**p_iso;
}						t_map;

typedef struct			s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_str;
	int			fd;
	int			bpp;
	int			l;
	int			endian;
	int			color;
	t_map		*map;
}						t_fdf;

typedef struct			s_bresn
{
	int			dx;
	int			dy;
	int			stpx;
	int			stpy;
	int			am;
}						t_bresn;

void					init_win_img(t_fdf *fdf);
t_fdf					*init(void);
int						check_fd(char *file, t_fdf *fdf);
void					read_file_stock(t_fdf *fdf);
void					display_fdf_menu(t_fdf *fdf);
void					put_pixel_img(t_fdf *fdf, int x, int y, int couleur);
void					drwln(t_fdf *fdf, t_point p0, t_point p1);
void					draw_shape(t_fdf *hm);
int						key_press(int key, void *param);
int						mouse_press(int button, int x, int y, void *param);
void					iso(t_point *p, double h);
void					change_altitude(t_map *map);
void					calc_dist(t_map *map);
void					change_zoom(t_map *map);
void					error(char *err, char *all, t_fdf *fdf);
void					free_lines(t_fdf *fdf);
void					free_prelines(t_fdf *fdf);
void					free_points(t_fdf *fdf);
void					free_all(t_fdf *fdf);
#endif
