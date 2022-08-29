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

void    map_components(char **map, char *av)
{
    int i;

    number_of_lines(av);
    i = 0;
    while(map[i++])
    {
        components_chrch(map[i]);
    }
}
