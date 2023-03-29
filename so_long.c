/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:55:11 by mflury            #+#    #+#             */
/*   Updated: 2023/03/29 14:57:37 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keeb_listener(int keycode, t_data *var)
{
	if (keycode == 53)
	{
		printf("ESC pressed(%d)\n", keycode);
		exit (0);
	}
	else if (keycode == 13 || keycode == 126)
	{
		move_up(keycode, var);
	}
	else if (keycode == 0 || keycode == 123)
	{
		move_left(keycode, var);
	}
	else if (keycode == 1 || keycode == 125)
	{
		move_down(keycode, var);
	}
	else if (keycode == 2 || keycode == 124)
	{
		move_right(keycode, var);
	}
	else
		printf("Keycode : %d\nimagine being too dumb to use wasd...\n", keycode);
	return (0);
}

int	redcross_close(t_data *var)
{
	(void) var;
	printf("RED CROSS pressed\n");
	exit (0);
	return (0);
}

void	var_init(t_data *var)
{
	var->player.posx = 0;
	var->player.posy = 0;
	var->map.groundx = 0;
	var->map.groundy = 0;
	var->map.wallx = 0;
	var->map.wally = 0;
	var->map.itemx = 0;
	var->map.itemy = 0;
	var->map.doorx = 0;
	var->map.doory = 0;
	var->map.tabx = 0;
	var->map.taby = 0;
}

void	initial_frame(t_data *var)
{
	var->player.relative_path_player = "./images/pigeon_100px_right.xpm";
	var->map.relative_path_ground = "./images/ground_100px.xpm";
	var->map.relative_path_wall = "./images/wall_100px.xpm";
	var->mlx_win = mlx_new_window(var->mlx, 1000, 1000, "3.14 x Rambo!");
	var->img = mlx_new_image(var->mlx, 1000, 1000);
	var->addr = mlx_get_data_addr(var->img, &var->bits_per_pixel, &var->line_length,
			&var->endian);
	// put an image from an xpm file, then push it to the window.
	ground_builder(var);
	wall_builder(var);
	var->img = mlx_xpm_file_to_image(var->mlx,
			var->player.relative_path_player,
			&var->img_width, &var->img_height);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
		var->player.posx, var->player.posy);
}

int	so_long(void)
{
	t_data	var;

	var_init(&var);
	// initialize a connection to graphical server.
	var.mlx = mlx_init();
	// make the first frame.
	initial_frame(&var);
	// make map builder
	init_game(&var);
	// hook for esc key event, ESC clean close.
	mlx_hook(var.mlx_win, ON_KEYDOWN, 0, keeb_listener, &var);
	// hook for red cross event, REDCROSS clean close.
	mlx_hook(var.mlx_win, ON_DESTROY, 0, redcross_close, &var);
	// loop hook to render next frame.
	// mlx_loop_hook(var.mlx, render_next_frame, &var);

	// loop the mlx instancy so it keeps running.
	mlx_loop(var.mlx);
	return (0);
}

int	main(void)
{
	so_long();
	return (0);
}
