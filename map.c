#include "so_long.h"

char    *read_map(char  *av)
{
    char    **map;
    char    *line;
    int     fd;
    int     i;

    fd = open(av,  O_RDONLY);
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        map[i] = malloc(sizeof (char *) * (ft_strlen(line) + 1));
        
    }
    
}