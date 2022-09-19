#include "so_long.h"

void    creat_map(char **map, t_comp *mlx, t_dimo dimo)
{
    mlx->init = mlx_init();
    images_path(mlx);
    mlx->win = mlx_new_window(mlx->init,  (dimo.line_lenth - 1) * 64, dimo.num_lines * 64, "so_long");
    fill_window(map, mlx);
}

void    images_path(t_comp *mlx)
{
    int img_width;
	int img_height;

    mlx->w_image = mlx_xpm_file_to_image(mlx->init, "./images/wall.xpm", &img_width, &img_height);
    mlx->b_image = mlx_xpm_file_to_image(mlx->init, "./images/backgroud.xpm", &img_width, &img_height);
    mlx->p_image = mlx_xpm_file_to_image(mlx->init, "./images/spongebob.xpm", &img_width, &img_height);
    mlx->c_image = mlx_xpm_file_to_image(mlx->init, "./images/collectible.xpm", &img_width, &img_height);
    mlx->e_image = mlx_xpm_file_to_image(mlx->init, "./images/exit.xpm", &img_width, &img_height);
}

void    fill_window(char **map, t_comp *mlx)
{
    int i;
    int j;

    push_backgroud(map, mlx);
    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(mlx->init, mlx->win, mlx->w_image, j * 64, i * 64);
            else if (map[i][j] == 'P')
                mlx_put_image_to_window(mlx->init, mlx->win, mlx->p_image, j * 64, i * 64);
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(mlx->init, mlx->win, mlx->c_image, j * 64, i * 64);
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(mlx->init, mlx->win, mlx->e_image, j * 64, i * 64);
            j++;
        }
        i++;
    }
}
void    push_backgroud(char **map, t_comp *mlx)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            mlx_put_image_to_window(mlx->init, mlx->win, mlx->b_image, j * 64, i * 64);
            j++;
        }
        i++;
    }
}