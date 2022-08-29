#include "so_long.h"

void    error(char *s)
{
    int     i;

    i = 0;
    while (s[i] != '\0')
    {
        write (1, &s[i], 1);
        i++;
    }
    exit(EXIT_FAILURE);
}


void check_extension(char *av)
{
    int     i;
    int     j;
    char    *extension;

    j = 0;
    i = ft_strlen(av) - 4;
    extension = ".ber";
    while(av[i] ==  extension[j] && extension)
    {
        if (av[i] == '\0')
            return ;
        i++;
        j++;
    }
    if (av[i] != '\0')
        error("ERROR: wrong file 'file extension should be .ber'\n");
}

void    check_walls(char **map)
{
    int i;
    int j;

    i = 0;
    j = ft_strlen(map[i]) - 2;
    while(j > 0)
    {
        if (map[i][j] != '1')
            error("ERROR: you have a hole in your wall! (fixe it please)\n");
        j--;
    }
    j = ft_strlen(map[i]) - 2; //use lien lenth
    while (map[i])
    {
        if (map[i][0] != '1' || map[i][j] != '1')
            error("ERROR: you have a hole in your wall! (fixe it please)\n");
        i++;
    }
    i = i - 1;
    while(j > 0)
    {
        if (map[i][j] != '1')
            error("ERROR: you have a hole in your wall! (fixe it please)\n");
        j--;
    }
}

void    lines(char  **map, t_dimo dimo)
{
    int i;
    int j;

    i = dimo.num_lines;
    j = ft_strlen(map[0]);
    while (i > 0)
    {
        if (j > dimo.line_lenth)
            error("ERROR: dimensios are not valid\n");
        j = ft_strlen(map[i]);
        i--;
    }
}

void    rectangular_map(t_dimo dimo)
{
    if (dimo.line_lenth < dimo.num_lines)
        error("ERROR: your map must be rectangular\n");
}