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

void    map_errors(char *av, char **map, t_dimo dimo)
{
    check_extension(av);
    lines(map, dimo);
    rectangular_map(dimo);
    map_components(map);
    check_walls(map);
}

void    map_components(char **map)
{
    int     i;
    t_comp  t_com;

    t_com.collectible = 0;
    t_com.player = 0;
    t_com.exit = 0;
    i = 0;
    while(map[i] != NULL)
    {
        t_com = components_chrch(map[i], t_com);
        i++;
    }
    if (t_com.collectible < 1)
        error("ERROR: there's no enough collectible\n");
    if (t_com.exit != 1)
    {
        if (t_com.exit == 0)
            error("ERROR: there's no EXIT, just like vim ;)\n");
        else
            error("ERROR: only one exite should be\n");
    }
    if (t_com.player != 1)
    {
        if (t_com.player == 0)
            error("ERROR: there's no player, how you wana play!!!\n");
        else
            error("ERROR: don't cheat you only need one player to win\n");
    }
}

void    creat_map(char **map, t_dimo dimo)
{
    int i;
    int j;

    i = 0;
    
}