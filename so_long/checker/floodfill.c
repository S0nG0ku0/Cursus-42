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
    flood_fill(map, map->player_y, map->player_x);
    if (map->c == map->coins && map->e == map->exit)
        return (0);
    else
        return (1);
    return (0);
}
