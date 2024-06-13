#include "../libft/libft.h"

void slchecker_wall(t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < map->x) {
        if (map->map[0][j] != '1' || map->map[(map->y)-1][j] != '1') {
            ft_printf("Error: Invalid Map\n");
            ft_malloc(0, 1);
            exit(1);
        }
        j++;
    }
    while (i < map->y) {
        if (map->map[i][0] != '1' || map->map[i][(map->x)-1] != '1') {
            ft_printf("Error: Invalid Map\n");
            ft_malloc(0, 1);
            exit(1);
        }
        i++;
    }
}
