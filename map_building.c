/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_building.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:47:11 by mflury            #+#    #+#             */
/*   Updated: 2023/05/19 20:14:12 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ground_builder(t_data *var)
{
	var->img = mlx_xpm_file_to_image(var->mlx, var->map.relative_path_ground,
			&var->img_width, &var->img_height);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
		var->map.tabx * 100, var->map.taby * 100);
}

void	wall_builder(t_data *var)
{
	var->img = mlx_xpm_file_to_image(var->mlx, var->map.relative_path_wall,
			&var->img_width, &var->img_height);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
		var->map.tabx * 100, var->map.taby * 100);
}

void	item_builder(t_data *var)
{
	var->img = mlx_xpm_file_to_image(var->mlx, var->map.relative_path_item,
			&var->img_width, &var->img_height);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
		var->map.tabx * 100, var->map.taby * 100);
}

void	exit_builder(t_data *var)
{
	var->img = mlx_xpm_file_to_image(var->mlx, var->map.relative_path_exit,
			&var->img_width, &var->img_height);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
		var->map.tabx * 100, var->map.taby * 100);
}

void	map_builder(t_data *var)
{
	var->map.taby = 0;
	while (var->map.tab[var->map.taby])
	{
		var->map.tabx = 0;
		while (var->map.tab[var->map.taby][var->map.tabx])
		{
			if (var->map.tab[var->map.taby][var->map.tabx] == '0'
				|| var->map.tab[var->map.taby][var->map.tabx] == 'P')
				ground_builder(var);
			if (var->map.tab[var->map.taby][var->map.tabx] == '1')
				wall_builder(var);
			if (var->map.tab[var->map.taby][var->map.tabx] == 'E')
			{
				ground_builder(var);
				exit_builder(var);
			}
			if (var->map.tab[var->map.taby][var->map.tabx] == 'C')
			{
				ground_builder(var);
				item_builder(var);
			}
			var->map.tabx++;
		}
		var->map.taby++;
	}
}
