#include "so_long.h"

char    **read_map(char  *av)
{
    char    **map;
    char    *temp;
    char    *line;
    int     fd;
    int     i;

   
    map = malloc(sizeof (char *) * (number_of_lines(av) + 1));
    fd = open(av,  O_RDONLY);
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        temp = malloc(sizeof (char *) * (line_lenth(av) + 1));
        map[i] = ft_strjoin(temp, line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    return(map);
}

// char    **help_split(char **map)
// {
//     int i;

//     i = 0;
//     while (map)
//     {
//         map = ft_split(map[i], '\n');
//         i++;
//     }
//     return (map);
// }