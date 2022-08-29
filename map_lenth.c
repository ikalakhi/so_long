#include "so_long.h"

int number_of_lines(char *av)
{
    int     fd;
    int     number;
    char    *line;

    number = 0;
    fd = open(av,  O_RDONLY);
    if (fd < 0)
        error("ERROR: no such file or directory\n");
    line = get_next_line(fd);
    if (line != NULL)
        number++;
    while (line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        number++;
    }
    free(line);
    close (fd);
    return (number);
}

int line_lenth(char *av)
{
    int     fd;
    int     lenth;
    char    *line;

    lenth = 0;
    fd = open(av,  O_RDONLY);
    if (fd < 0)
        error("ERROR: no such file or directory\n");
    line = get_next_line(fd);
    if (!line)
        return (0);
    lenth = ft_strlen(line);
    free(line);
    close (fd);
    return (lenth);
}

t_dimo  map_dimension(char  *av)
{
    t_dimo  dimo;

    dimo.line_lenth = line_lenth(av);
    dimo.num_lines = number_of_lines(av);
    return (dimo);
}