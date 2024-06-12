/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:54 by ohaida            #+#    #+#             */
/*   Updated: 2024/06/12 06:19:49 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void render_player(int x, int y, void *mlx, void *mlx_win)
{
	void	*img;
	char	*relative_path = "./assets/sprites/player.xpm";
	int		img_width;
	int		img_height;

	
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, x * 32, y * 32);
}

void render_wall(int x, int y, void *mlx, void *mlx_win)
{
	void	*img;
	char	*relative_path = "./assets/sprites/wall.xpm";
	int		img_width;
	int		img_height;

	
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, x * 32, y * 32);
}

void render_coins(int x, int y, void *mlx, void *mlx_win)
{
	void	*img;
	char	*relative_path = "./assets/sprites/coin.xpm";
	int		img_width;
	int		img_height;

	
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, x * 32, y * 32);
}

int   r_int_malloc(int fd)
{
    int     int_malloc;
	char	*map;

    int_malloc = 0;
	map = get_next_line(fd);
    while (map)
    {
        int_malloc++;
		free(map);
		map = get_next_line(fd);
    }
	free(map);
    return (int_malloc);
}

char **ret_map(int int_malloc)
{
	int		fd;
	char    **map;
	char    *line;
	int     i;

	i = 0;
	fd = open("./assets/maps/firstone.ber", O_RDONLY);
	map = (char **)ft_malloc(sizeof(char *) * (int_malloc + 1), 0);
	if (!map)
	{
		ft_malloc(0, 1);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		if (!map[i])
		{
			ft_malloc(0, 1);
			exit(1);
		}
		i++;
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	free(line);
	return (map);
}

void copy_map(t_map *map)
{
    int i = 0, j;
    map->copy = (char **)ft_malloc(sizeof(char *) * (map->y + 1), 0);
    if (!map->copy)
    {
        ft_malloc(0, 1);
        exit(1);
    }
    while (i < map->y)
    {
        map->copy[i] = (char *)ft_malloc(sizeof(char) * (map->x + 1), 0);
        if (!map->copy[i])
        {
            ft_malloc(0, 1);
            exit(1);
        }
        j = 0;
        while (j < map->x)
        {
            map->copy[i][j] = map->map[i][j];
            j++;
        }
        map->copy[i][j] = '\0';
        i++;
    }
    map->copy[i] = NULL;
}

char **read_from_file(void)
{
    int		fd;
	char	**map;
    int     int_malloc;

	fd = open("./assets/maps/firstone.ber", O_RDONLY);
    if (fd == -1)
		return (NULL);
    int_malloc = r_int_malloc(fd);
    if (int_malloc == 0)
	{
		ft_malloc(0, 1);
        exit(1);
	}
	map = ret_map(int_malloc);
	return (map);
}



void render_map(t_vars *vars, t_map *map)
{
	map->coins = 0;
    map->map = read_from_file();
    if (!(map->map))
	{
		ft_malloc(0, 1);
        exit(1);
	}
	map->y = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			if (map->map[map->y][map->x] == '1')
			{
				(map->wall)++;
				render_wall(map->x, map->y, vars->mlx, vars->win);
			}
			else if (map->map[map->y][map->x] == '0')
				(map->empty)++;
			else if (map->map[map->y][map->x] == 'P')
			{
				render_player(map->x, map->y, vars->mlx, vars->win);
				map->player_x = map->x;
				map->player_y = map->y;
                (map->player)++;
			}
			else if (map->map[map->y][map->x] == 'E')
                (map->exit)++;
			else if (map->map[map->y][map->x] == 'C')
			{
				render_coins(map->x, map->y, vars->mlx, vars->win);
				(map->coins)++;
			}
			else
			{
				ft_printf("ErrorSSSS\n");
				ft_malloc(0, 1);
				exit(1);
			}
			(map->x)++;
		}
		(map->y)++;
	}
	slchecker_wall(map);
	if (all_reach(map))
	{
		ft_printf("ErrorKKK\n");
		ft_malloc(0, 1);
		exit(1);
	}
}

int key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
		ft_malloc(0, 1);
        exit(0);
    }
    else if (keycode == 13 || keycode == 126)
        ft_printf("Player moved up\n");
    else if (keycode == 0 || keycode == 123)
        ft_printf("Player moved left\n");
    else if (keycode == 1 || keycode == 125)
        ft_printf("Player moved down\n");
    else if (keycode == 2 || keycode == 124)
        ft_printf("Player moved right\n");
    return (0);
}

int close_event(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    ft_malloc(0, 1);
    exit(0);
}

int main()
{
    t_vars	vars;
	t_map	map;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 34 * 32, 6 * 32, "so_long");
	render_map(&vars, &map);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L<<17, close_event, &vars);
	mlx_loop(vars.mlx);
	ft_malloc(0, 1);
	return (0);
}