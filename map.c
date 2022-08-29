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

void    map_errors(char *av, char **map)
{
    check_extension(av);
    map_components(map, av);
}