/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:08:19 by mflury            #+#    #+#             */
/*   Updated: 2023/06/05 17:01:29 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *var)
{
	mlx_clear_window(var->mlx, var->mlx_win);
	item_picker(var);
	map_builder(var);
	ft_printf("player moves: %d\n", var->player.move_count++);
	var->img = mlx_xpm_file_to_image(var->mlx, var->player.relative_path_player,
			&var->img_width, &var->img_height);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
		var->player.posx, var->player.posy);
}

void	move_up(t_data *var)
{
	if (var->player.posy <= 0
		|| var->map.tab[(var->player.posy - 1) / 100]
		[var->player.posx / 100] == '1')
		return ;
	if (var->map.ccount == 0
		&& var->map.tab[(var->player.posy - 1) / 100]
		[var->player.posx / 100] == 'E')
		exit(ft_succes_finish(var));
	var->player.posy -= 100;
	move_player(var);
}

void	move_left(t_data *var)
{
	if (var->player.posx <= 0 || var->map.tab[var->player.posy / 100]
		[(var->player.posx - 100) / 100] == '1')
		return ;
	if (var->map.ccount == 0
		&& var->map.tab[var->player.posy / 100]
		[(var->player.posx - 100) / 100] == 'E')
		exit(ft_succes_finish(var));
	var->player.relative_path_player = "./images/pigeon_100px_left.xpm";
	var->player.posx -= 100;
	move_player(var);
}

void	move_down(t_data *var)
{
	if (var->player.posy >= (var->map.tabmaxy - 1) * 100
		|| var->map.tab[(var->player.posy + 100) / 100]
		[var->player.posx / 100] == '1')
		return ;
	if (var->map.ccount == 0
		&& var->map.tab[(var->player.posy + 100) / 100]
		[var->player.posx / 100] == 'E')
		exit(ft_succes_finish(var));
	var->player.posy += 100;
	move_player(var);
}

void	move_right(t_data *var)
{
	if (var->player.posx >= (var->map.tabmaxx - 2) * 100
		|| var->map.tab[var->player.posy / 100]
		[(var->player.posx + 100) / 100] == '1')
		return ;
	if (var->map.ccount == 0
		&& var->map.tab[var->player.posy / 100]
		[(var->player.posx + 100) / 100] == 'E')
		exit(ft_succes_finish(var));
	var->player.relative_path_player = "./images/pigeon_100px_right.xpm";
	var->player.posx += 100;
	move_player(var);
}
