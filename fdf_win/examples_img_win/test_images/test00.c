#include <mlx.h>
#include <stdio.h>

int     main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    int     bpp;
    int     size_line;
    int     endian;
    char    *img_str;
    int i = 0;


    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 800, "test images");
    img_ptr = mlx_new_image(mlx_ptr, 600, 600);
    mlx_string_put(mlx_ptr, win_ptr, 2, 2, 255150, "test image00");
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
    img_str = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
    /****    (1, 2) x = 1, y = 2     ****/
    /****     position pixel = (x * 4) + (4 * line size * y)    ****/
    /****       => 4 +  (4 * 600 * 2) = 4804       ****/
    img_str[4804] = 0;
    img_str[4805] = 255;
    img_str[4806] = 0;
    img_str[4807] = 0;

    return (0);
}