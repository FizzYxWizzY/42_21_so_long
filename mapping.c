/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:06:18 by mflury            #+#    #+#             */
/*   Updated: 2023/03/29 14:57:29 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	door_builder(t_data *var)
/*{
	var->img = mlx_xpm_file_to_image(var->mlx, var->map.relative_path_door,
			&var->img_width, &var->img_height);
	while (var->map.doorx < 1000)
	{
		while (var->map.doory < 1000)
		{
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
				var->map.doorx, var->map.doory);
			var->map.doory += 100;
		}
			var->map.doory = 0;
			var->map.doorx += 100;
	}
	var->map.doorx = 0;
}*/

// void	item_builder(t_data *var)
/*{
	var->img = mlx_xpm_file_to_image(var->mlx, var->map.relative_path_item,
			&var->img_width, &var->img_height);
	while (var->map.itemx < 1000)
	{
		while (var->map.itemy < 1000)
		{
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
				var->map.itemx, var->map.itemy);
			var->map.itemy += 100;
		}
			var->map.itemy = 0;
			var->map.itemx += 100;
	}
	var->map.itemx = 0;
}*/

void	wall_builder(t_data *var)
{
	var->img = mlx_xpm_file_to_image(var->mlx, var->map.relative_path_wall,
			&var->img_width, &var->img_height);
	//while (var->map.wallx < 1000)
	//{
		while (var->map.wally < 1000)
		{
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
				var->map.wallx, var->map.wally);
			var->map.wally += 100;
		}
			var->map.wally = 0;
			var->map.wallx += 100;
	//}
	var->map.wallx = 0;
}

void	ground_builder(t_data *var)
{
	var->img = mlx_xpm_file_to_image(var->mlx, var->map.relative_path_ground,
			&var->img_width, &var->img_height);
	while (var->map.groundx < 1000)
	{
		while (var->map.groundy < 1000)
		{
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->img,
				var->map.groundx, var->map.groundy);
			var->map.groundy += 100;
		}
			var->map.groundy = 0;
			var->map.groundx += 100;
	}
	var->map.groundx = 0;
}

char	*copy_line(t_data *var, char *last_line, int index)
{
	char		*new_line;
	size_t		i;

	i = -1;
	var->map.tab[index] = malloc((ft_strlen(last_line)) * sizeof(char *));
	if (!var->map.tab[index])
		return (0);
	while (++i < ft_strlen(last_line))
		var->map.tab[index][i] = last_line[i];
	var->map.tab[index][i] = '\0';
	free(last_line);
	new_line = get_next_line(var->map.fd);
	return (new_line);
}

int	map_parser(t_data *var)
{
	char	*line;
	int		i;

	i = 0;
	var->map.fd = open("./maps/map1.ber", O_RDONLY);
	line = get_next_line(var->map.fd);
	while (line) // check le nombre de ligne du fichier
	{
		i++;
		line = get_next_line(var->map.fd);
	}
	close(var->map.fd);
	i = 0;
	var->map.tab = malloc(i * sizeof(char *));
	if (!var->map.tab)
		return (1);
	var->map.fd = open("./maps/map1.ber", O_RDONLY);
	line = get_next_line(var->map.fd);
	while (line)
	{
		line = copy_line(var, line, i);
		i++;
	}
	return (0);
}

int	check_char(t_data *var)
{
	var->map.taby = 0;
	while (var->map.tab[var->map.taby])
	{
		var->map.tabx = 0;
		while (var->map.tab[var->map.taby][var->map.tabx])
		{
			if (var->map.tab[var->map.taby][var->map.tabx] == '1')
				var->map.tabx++;
			else if (var->map.tab[var->map.taby][var->map.tabx] == '0')
				var->map.tabx++;
			else if (var->map.tab[var->map.taby][var->map.tabx] == 'E')
				var->map.tabx++;
			else if (var->map.tab[var->map.taby][var->map.tabx] == 'C')
				var->map.tabx++;
			else if (var->map.tab[var->map.taby][var->map.tabx] == 'P')
				var->map.tabx++;
			else if (var->map.tab[var->map.taby][var->map.tabx] == '\n')
				var->map.tabx++;
			else
				printf("y: %d, x: %d c: %c\n", var->map.taby, var->map.tabx, var->map.tab[var->map.taby][var->map.tabx]);
			var->map.tabx++;
		}
		var->map.taby++;
	}
	return (0);
}

int	map_checker(t_data *var)
{
	if (check_char(var) != 0)
		printf("Error\n");
	return (0);
}

/*
int	map_builder(t_data *var)
{
	(void) var;
	return (0);
}
*/

int	init_game(t_data *var)
{
	if (map_parser(var) != 0)
		return (1);
	if (map_checker(var) != 0)
		return (1);
	// if (floodfill(var) != 0)
	// 	return (1);
	// if (map_builder(var) != 0)
	// 	return (1);
	
	free(*var->map.tab);
	return (0);
}