/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:08:19 by mflury            #+#    #+#             */
/*   Updated: 2023/03/29 14:57:33 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *var)
{
	mlx_clear_window(var->mlx, var->mlx_win);
	ground_builder(var);
	wall_builder(var);
	var->img = mlx_xpm_file_to_image(var->mlx, var->player.relative_path_player,
			&var->img_width, &var->img_height);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
		var->player.posx, var->player.posy);
}

void	move_up(int keycode, t_data *var)
{
	printf("W pressed(%d)\n", keycode);
	if (var->player.posy <= 0)
		return ;
	var->player.posy -= 100;
	move_player(var);
}

void	move_left(int keycode, t_data *var)
{
	printf("A pressed(%d)\n", keycode);
	if (var->player.posx <= 0)
		return ;
	var->player.relative_path_player = "./images/pigeon_100px_left.xpm";
	var->player.posx -= 100;
	move_player(var);
}

void	move_down(int keycode, t_data *var)
{
	printf("S pressed(%d)\n", keycode);
	if (var->player.posy >= 900)
		return ;
	var->player.posy += 100;
	move_player(var);
}

void	move_right(int keycode, t_data *var)
{
	printf("D pressed(%d)\n", keycode);
	if (var->player.posx >= 900)
		return ;
	var->player.relative_path_player = "./images/pigeon_100px_right.xpm";
	var->player.posx += 100;
	move_player(var);
}
