#include "../libft/libft.h"

void flood_fill(t_map *map, int x, int y) 
{
    if (x < 0 || x >= map->x || y < 0 || y >= map->y || (map->copy[y][x] != '0' && map->copy[y][x] != 'P' && map->copy[y][x] != 'C' && map->copy[y][x] != 'E'))
    {
        return ;
    }
    if (map->copy[y][x] != 'P')
    {
        if(map->copy[y][x] == 'C')
            (map->c)++;
        else if(map->copy[y][x] == 'E')
            (map->e)++;
        map->copy[y][x] = 'b';
    }
    flood_fill(map, x + 1, y);
    flood_fill(map, x - 1, y);
    flood_fill(map, x, y + 1);
    flood_fill(map, x, y - 1);
}

int all_reach(t_map *map)
{
    map->c = 0;
    map->e = 0;
    copy_map(map);
    if (!(map->player == 1 && map->coins >= 1))
        return (0);
    flood_fill(map, map->player_y, map->player_x);
    for (int i = 0; map->map[i]; i++)
        ft_printf("%s\n", map->map[i]);
    ft_printf("\n");
    for (int i = 0; map->map[i]; i++)
        ft_printf("%s\n", map->copy[i]);
    ft_printf("map->c = %d\n", map->c);
    ft_printf("map->e = %d\n", map->e);
    ft_printf("map->coins = %d\n", map->coins);
    ft_printf("map->exit = %d\n", map->exit);
    if (map->c == map->coins && map->e == map->exit && map->exit == 1)
        return (0);
    else
        return (1);
}