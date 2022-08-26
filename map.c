#include "so_long.h"

char    **read_map(char  *av)
{
    char    **map;
    char    *line;
    int     fd;
    int     i;

    fd = open(av,  O_RDONLY);
    map = malloc(sizeof (char *) * (number_of_lines(fd) + 1));
    line = get_next_line(fd);
    printf("fd =====> %d\n", fd);
    printf("line =====> %s\n", line);
    i = 0;
    while (i < 1)
    {
        map[i] = join(map[i], line);
        printf("%s\n", map[0]);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    // printf("%s\n", map[0]);
    return(map);
}