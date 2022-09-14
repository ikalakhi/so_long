#include "so_long.h"

void    creat_map(char **map, t_comp *mlx, t_dimo dimo)
{
    images_path();
    mlx->init = mlx_init();
    mlx->win = mlx_new_window(mlx->init,  1920, 1080, "so_long");
    fill_window(map, mlx, dimo);
}

void    fill_window(char **map, t_comp *mlx, t_dimo dimo)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == '1')
            {
                mlx->image = mlx_xpm_file_to_image(mlx->init, mlx->w_path, &c, &b);
                mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
            }
            else if (map[i][j] == '0')
            {
                mlx->image = mlx_xpm_file_to_image(mlx->init, mlx->b_path, &c, &b);
                mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
            }
            else if (map[i][j] == 'P')
            {
                mlx->image = mlx_xpm_file_to_image(mlx->init, mlx->p_path, &c, &b);
                mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
            }
            else if (map[i][j] == 'C')
            {
                mlx->image = mlx_xpm_file_to_image(mlx->init, mlx->c_path, &c, &b);
                mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
            }
            else if (map[i][j] == 'E')
            {
                mlx->image = mlx_xpm_file_to_image(mlx->init, mlx->e_path, &c, &b);
                mlx_put_image_to_window(mlx->init, mlx->win, mlx->image, 0, 0);
            }
            j++;
        }
        i++;
    }
}

void    images_path(void)
{
    t_comp *path;

    path->c_path = "images/collectible.xpm";
    path->p_path = "images/spongebob.xpm ";
    path->b_path = "images/backgroud.xpm";
    path->w_path = "images/wall.xpm";
}