#include "so_long.h"

int number_of_lines(char *av)
{
    int     fd;
    int     number;
    char    *line;

    number = 0;
    fd = open(av,  O_RDONLY);
    line = get_next_line(fd);
    if (line != NULL)
        number++;
    while (line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        number++;
    //printf("%s\n", line);
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
    line = get_next_line(fd);
    if (!line)
        return (0);
    lenth = ft_strlen(line);
    free(line);
    close (fd);
    return (lenth);
}