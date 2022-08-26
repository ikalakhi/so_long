#include "so_long.h"

int number_of_lines(int fd)
{
    int     number;
    char    *line;

    number = 0;
    line = get_next_line(fd);
    if (line != NULL)
        number++;
    while (line)
    {
        free(line);
        line = get_next_line(fd);
        number++;
    }
    free(line);
    return (number);
}

int line_lenth(int  fd)
{
    int     lenth;
    char    *line;

    lenth = 0;
    line = get_next_line(fd);
    if (!line)
        return (0);
    lenth = ft_strlen(line);
    free(line);
    return (lenth);
}