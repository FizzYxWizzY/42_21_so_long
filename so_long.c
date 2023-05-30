/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:05:02 by mflury            #+#    #+#             */
/*   Updated: 2023/05/26 19:34:36 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keeb_listener(int keycode, t_data *var)
{
	if (keycode == 53)
	{
		exit (0);
	}
	else if (keycode == 13 || keycode == 126)
	{
		move_up(var);
	}
	else if (keycode == 0 || keycode == 123)
	{
		move_left(var);
	}
	else if (keycode == 1 || keycode == 125)
	{
		move_down(var);
	}
	else if (keycode == 2 || keycode == 124)
	{
		move_right(var);
	}
	else
		ft_printf("\nimagine being too dumb to use wasd...\n");
	return (0);
}

int	redcross_close(t_data *var)
{
	free_tab(var);
	exit (0);
	return (0);
}

void	player_start(t_data *var)
{
	static int	i;

	if (i > 0)
		return ;
	i = 0;
	player_finder(var, var->map.tab);
	var->player.posy = var->map.taby * 100;
	var->player.posx = var->map.tabx * 100;
	var->img = mlx_xpm_file_to_image(var->mlx, var->player.relative_path_player,
			&var->img_width, &var->img_height);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
		var->player.posx, var->player.posy);
	i++;
}

void	initial_frame(t_data *var)
{
	var->player.relative_path_player = "./images/pigeon_100px_right.xpm";
	var->map.relative_path_ground = "./images/ground_100px.xpm";
	var->map.relative_path_wall = "./images/wall_100px.xpm";
	var->map.relative_path_exit = "./images/exit_100px.xpm";
	var->map.relative_path_item = "./images/item_100px.xpm";
	var->mlx_win = mlx_new_window(var->mlx,
			(var->map.tabmaxx - 1) * 100,
			(var->map.tabmaxy) * 100, "3.14 x Rambo!");
	var->img = mlx_new_image(var->mlx,
			var->map.tabmaxx * 100, var->map.tabmaxy * 100);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel,
			&var->line_length, &var->endian);
	map_builder(var);
	player_start(var);
	item_counter(var);
	var->img = mlx_xpm_file_to_image(var->mlx,
			var->player.relative_path_player,
			&var->img_width, &var->img_height);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
		var->player.posx, var->player.posy);
}

int	main(int argc, char **args)
{
	t_data	var;
	char	*map_path;

	if (argc > 2)
		error("too much arguments.");
	if (argc < 2)
		error("need a map path as argument.");
	if (path_check(args[1]) != 0)
		error("map path is trash.");
	map_path = args[1];
	var_init(&var);
	if (map_init(&var, map_path) != 0)
		exit (0);
	var.mlx = mlx_init();
	initial_frame(&var);
	mlx_hook(var.mlx_win, ON_KEYDOWN, 0, keeb_listener, &var);
	mlx_hook(var.mlx_win, ON_DESTROY, 0, redcross_close, &var);
	mlx_loop(var.mlx);
	return (0);
}
