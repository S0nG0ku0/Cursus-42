/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:54 by ohaida            #+#    #+#             */
/*   Updated: 2024/06/13 00:31:00 by ohaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void    ft_move(t_vars *vars, int a, int b)
{
    char    c;

    c = vars->map->map[vars->map->player_y + a][vars->map->player_x + b];
    if (c == 'C' || c == '0')
    {
        if (c == 'C')
            (vars->map->coins)--;
        vars->map->map[vars->map->player_y][vars->map->player_x] = '0';
        vars->map->map[vars->map->player_y + a][vars->map->player_x + b] = 'P';
        (vars->map->player_y) += a;
        (vars->map->player_x) += b;
        (vars->map->moves)++;
    }
    else if(c == 'E'  && vars->map->coins == 0)
            exit(ft_printf("exit reached"));
}

void render_player(int x, int y, void *mlx, void *mlx_win)
{
	void	*img;
	char	*relative_path = "./assets/sprites/player.xpm";
	int		img_width;
	int		img_height;

	
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, x * 32, y * 32);
}

void render_grass(int x, int y, void *mlx, void *mlx_win)
{
	void	*img;
	char	*relative_path = "./assets/sprites/grass.xpm";
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

int render_map(t_vars *vars)
{
    int i = 0;
    int j;
    while (vars->map->map[i])
    {
        j = 0;
        while (vars->map->map[i][j])
        {
            if (vars->map->map[i][j] == '1')
                render_wall(j, i, vars->mlx, vars->win);
            else if (vars->map->map[i][j] == 'C')
                render_coins(j, i, vars->mlx, vars->win);
            else if (vars->map->map[i][j] == 'P')
                render_player(j, i, vars->mlx, vars->win);
            else if (vars->map->map[i][j] == '0')
                render_grass(j, i, vars->mlx, vars->win);
            j++;
        }
        i++;
    }
    return (0);
}

void fill_map(t_vars *vars)
{
    vars->map->coins = 0;
    vars->map->map = read_from_file();
    if (!(vars->map->map))
	{
		ft_malloc(0, 1);
        exit(1);
	}
	vars->map->y = 0;
	while (vars->map->map[vars->map->y])
	{
		vars->map->x = 0;
		while (vars->map->map[vars->map->y][vars->map->x])
		{
			if (vars->map->map[vars->map->y][vars->map->x] == '1')
				(vars->map->wall)++;
			else if (vars->map->map[vars->map->y][vars->map->x] == '0')
				(vars->map->empty)++;
			else if (vars->map->map[vars->map->y][vars->map->x] == 'P')
			{
				vars->map->player_x = vars->map->x;
				vars->map->player_y = vars->map->y;
                (vars->map->player)++;
			}
			else if (vars->map->map[vars->map->y][vars->map->x] == 'E')
                (vars->map->exit)++;
			else if (vars->map->map[vars->map->y][vars->map->x] == 'C')
				(vars->map->coins)++;
			else
			{
				ft_printf("ErrorSSSS\n");
				ft_malloc(0, 1);
				exit(1);
			}
			(vars->map->x)++;
		}
		(vars->map->y)++;
	}
	slchecker_wall(vars->map);
	if (all_reach(vars->map))
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
        ft_move(vars, -1, 0);
    else if (keycode == 0 || keycode == 123)
        ft_move(vars, 0, -1);
    else if (keycode == 1 || keycode == 125)
        ft_move(vars, 1, 0);
    else if (keycode == 2 || keycode == 124)
        ft_move(vars, 0, 1);
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
    
    vars.map = &map;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 34 * 32, 6 * 32, "so_long");
	fill_map(&vars);
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 17, 1L<<17, close_event, &vars);
    mlx_loop_hook(vars.mlx, render_map, &vars);
    mlx_loop(vars.mlx);
    ft_malloc(0, 1);
    return (0);
}