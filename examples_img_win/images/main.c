#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

//void fill_pixel(char *img_str, int x, int y, int color);

int close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_str;
	int		bpp;
	int		l;
	int		endian;
	int		i;
	int		j;
	void	*s;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 600, "fdf");
	img_ptr = mlx_new_image(mlx_ptr, 500, 500);
	img_str = (int*)mlx_get_data_addr(img_ptr, &(bpp), &(l), &(endian));
	mlx_hook(win_ptr, 17, 0, close, (void *)&s);

	/*
	   i = 0;
	   while (i < 600)
	   {
	   j = 0;
	   while (j < 600)
	   {
	   img_str[i * 600 + j] = 0xffffff;
	   j++;
	   }
	   i++;
	   }
	   */

	i = 0;
	while (i < 600)
	{
		j = 0;
		while (j < 600)
		{
			if (!((j > 85 && j % 17 && j < 511) && (i % 17 && i > 85 && i < 511)))
				img_str[i * 600 + j] = 0xffffff;
			//else
			//	img_str[i * 600 + j] = 0;

			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 20, 20);
	mlx_loop(mlx_ptr);
	return (0);
}
