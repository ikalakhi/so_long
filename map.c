#include "so_long.h"

char    **read_map(char  *av, t_dimo dimo)
{
    char    **map;
    char    *temp;
    char    *line;
    int     fd;
    int     i;

    map = malloc(sizeof (char *) * (dimo.num_lines + 1));
    fd = open(av,  O_RDONLY);
    if (fd < 0)
        error("ERROR: no such file or directory\n");
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        temp = malloc(sizeof (char *) * (dimo.line_lenth + 1));
        map[i] = ft_strjoin(temp, line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    return(map);
}

t_comp  *map_errors(char *av, char **map, t_dimo dimo, t_comp *comp)
{
    check_extension(av);
    lines(map, dimo);
    rectangular_map(dimo);
    comp = map_components(map, comp);
    check_walls(map);
    return (comp);
}

t_comp  *map_components(char **map, t_comp *comp)
{
    int     i;

    comp->collectible = 0;
    comp->player = 0;
    comp->exit = 0;
    i = 0;
    while(map[i] != NULL)
    {
        components_chrch(map[i], comp);
        i++;
    }
    if (comp->collectible == 0)
        error("ERROR: there's no enough collectible\n");
    if (comp->exit != 1)
    {
        if (comp->exit == 0)
            error("ERROR: there's no EXIT, just like vim ;)\n");
        else
            error("ERROR: only one exite should be\n");
    }
    if (comp->player != 1)
    {
        if (comp->player == 0)
            error("ERROR: there's no player, how you wana play!!!\n");
        else
            error("ERROR: don't cheat you only need one player to win\n");
    }
    return (comp);
}

void    creat_map(t_comp *mlx, t_dimo dimo)
{
    int i;
    int j;

    i = 0;
    j = 0;
    mlx_xpm_file_to_image(mlx->init, "./images/spongebob",
        &dimo.line_lenth, &dimo.num_lines);
    // \mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}
