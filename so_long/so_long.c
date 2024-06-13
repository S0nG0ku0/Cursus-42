/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaida <ohaida@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:38:54 by ohaida            #+#    #+#             */
/*   Updated: 2024/06/13 03:12:27 by ohaida           ###   ########.fr       */
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
    {
        ft_malloc(0, 1);
        ft_printf("You Win\n");
        exit(0);
    }
    ft_printf("moves: %d\n", vars->map->moves);
}

void render_player(int x, int y, void *mlx, void *mlx_win)
{
    void	*img;
    char	*relative_path = "./assets/sprites/player.xpm";
    int		img_width;
    int		img_height;

    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, x * 64, y * 64);
    mlx_destroy_image(mlx, img);
}

void render_grass(int x, int y, void *mlx, void *mlx_win)
{
    void	*img;
    char	*relative_path = "./assets/sprites/grass.xpm";
    int		img_width;
    int		img_height;

    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, x * 64, y * 64);
    mlx_destroy_image(mlx, img);
}

void render_wall(int x, int y, void *mlx, void *mlx_win)
{
    void	*img;
    char	*relative_path = "./assets/sprites/wall.xpm";
    int		img_width;
    int		img_height;

    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, x * 64, y * 64);
    mlx_destroy_image(mlx, img);
}

void render_door(int x, int y, void *mlx, void *mlx_win)
{
    void	*img;
    char	*relative_path = "./assets/sprites/door.xpm";
    int		img_width;
    int		img_height;

    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, x * 64, y * 64);
    mlx_destroy_image(mlx, img);
}

void render_coins(int x, int y, void *mlx, void *mlx_win)
{
    void	*img;
    char	*relative_path = "./assets/sprites/coin.xpm";
    int		img_width;
    int		img_height;

    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, x * 64, y * 64);
    mlx_destroy_image(mlx, img);
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

char **allocate_map(int int_malloc, t_vars *vars, int *fd)
{
    char    **map;
    *fd = open(vars->path, O_RDONLY);
    map = (char **)ft_malloc(sizeof(char *) * (int_malloc + 1), 0);
    if (!map)
    {
        ft_malloc(0, 1);
        exit(1);
    }
    return map;
}

char **read_lines_into_map(char **map, int fd)
{
    char    *line;
    int     i = 0;

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
    return map;
}

char **ret_map(int int_malloc, t_vars *vars)
{
    int fd;
    char **map = allocate_map(int_malloc, vars, &fd);
    return read_lines_into_map(map, fd);
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

char **read_from_file(t_vars *vars)
{
    int		fd;
	char	**map;
    int     int_malloc;

	fd = open(vars->path, O_RDONLY);
    if (fd == -1)
		return (NULL);
    int_malloc = r_int_malloc(fd);
    if (int_malloc == 0)
	{
		ft_malloc(0, 1);
        exit(1);
	}
	map = ret_map(int_malloc, vars);
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
            else if (vars->map->map[i][j] == 'E')
                render_door(j, i, vars->mlx, vars->win);
            j++;
        }
        i++;
    }
    return (0);
}

void read_and_validate_map(t_vars *vars)
{
    vars->map->coins = 0;
    vars->map->map = read_from_file(vars);
    if (!(vars->map->map))
    {
        ft_malloc(0, 1);
        ft_printf("Error: File Not Found\n");
        exit(1);
    }
}

void process_map_element(t_vars *vars)
{
    if (vars->map->map[vars->map->y][vars->map->x] == '1');
    else if (vars->map->map[vars->map->y][vars->map->x] == '0');
    else if (vars->map->map[vars->map->y][vars->map->x] == 'P')
    {
        (vars->map->player)++;
        vars->map->player_x = vars->map->x;
        vars->map->player_y = vars->map->y;
    }
    else if (vars->map->map[vars->map->y][vars->map->x] == 'E')
        (vars->map->exit)++;
    else if (vars->map->map[vars->map->y][vars->map->x] == 'C')
        (vars->map->coins)++;
    else
    {
        ft_printf("Error: Invalid Map\n");
        ft_malloc(0, 1);
        exit(1);
    }
}

void count_map_elements(t_vars *vars)
{
    while (vars->map->map[vars->map->y])
    {
        vars->map->x = 0;
        while (vars->map->map[vars->map->y][vars->map->x])
        {
            process_map_element(vars);
            (vars->map->x)++;
        }
        (vars->map->y)++;
    }
}

void fill_map(t_vars *vars)
{
    read_and_validate_map(vars);
    count_map_elements(vars);
    slchecker_wall(vars->map);
    if (!(vars->map->exit == 1 && vars->map->player == 1 && vars->map->coins >= 1))
    {
        ft_printf("Error: Invalid Map\n");
        ft_malloc(0, 1);
        exit(1);
    }
    if (all_reach(vars->map))
    {
        ft_printf("Error: Invalid Map\n");
        ft_malloc(0, 1);
        exit(1);
    }
}

int key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        ft_printf("You Exit\n");
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
    ft_printf("You Exit\n");
    ft_malloc(0, 1);
    exit(0);
}

void initialize_vars(t_vars *vars, t_map *map)
{
    vars->map = map;
    vars->map->y = 0;
    vars->map->player = 0;
    vars->map->exit = 0;
    vars->map->moves = 0;
    vars->map->coins = 0;
}

void check_args_and_fill_map(int argc, char **argv, t_vars *vars)
{
    if (argc == 2)
    {
        vars->path = argv[1];
        fill_map(vars);
    }
    else
    {
        ft_printf("Error: ./so_long <path_map>\n");
        ft_malloc(0, 1);
        exit(1);
    }
}

void initialize_mlx_and_window(t_vars *vars)
{
    vars->mlx = mlx_init();
    if (!(5120 / 64 < vars->map->x || 2880 / 64 < vars->map->y))
        vars->win = mlx_new_window(vars->mlx, vars->map->x * 64, vars->map->y * 64, "so_long");
    else
    {
        ft_printf("Error: Map is too big\n");
        ft_malloc(0, 1);
        exit(1);
    }
}

void set_hooks_and_start_loop(t_vars *vars)
{
    mlx_key_hook(vars->win, key_hook, vars);
    mlx_hook(vars->win, 17, 1L<<17, close_event, vars);
    mlx_loop_hook(vars->mlx, render_map, vars);
    mlx_loop(vars->mlx);
    ft_malloc(0, 1);
}

int main(int argc, char **argv)
{
    t_vars	vars;
    t_map	map;

    initialize_vars(&vars, &map);
    check_args_and_fill_map(argc, argv, &vars);
    initialize_mlx_and_window(&vars);
    set_hooks_and_start_loop(&vars);
}
