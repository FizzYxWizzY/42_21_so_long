/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:06:18 by mflury            #+#    #+#             */
/*   Updated: 2023/04/17 19:29:02 by mflury           ###   ########.fr       */
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
	while (var->map.groundx < (maxsizex * 100))
	{
		while (var->map.groundy < (maxsizey * 100))
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

	i = 0;
	var->map.tab[index] = malloc((ft_strlen(last_line)) * sizeof(char *));
	if (!var->map.tab[index])
		return (0);
	while (i < ft_strlen(last_line) && last_line[i] != '\n')
	{
		var->map.tab[index][i] = last_line[i];
		printf("%c", var->map.tab[index][i]);
		if (last_line[i + 1] == '\n' || last_line[i + 1] == '\0')
			break ;
		i++;
	}
	printf("\n");
	var->map.tab[index][i + 1] = '\0';
	free(last_line);
	new_line = get_next_line(var->map.fd);
	return (new_line);
}

int	map_parser(t_data *var)
{
	char	*line;
	int		i;

	var->map.max_size_y = 0;
	var->map.fd = open("./maps/map1.ber", O_RDONLY);
	line = get_next_line(var->map.fd);
	while (line) // check le nombre de ligne du fichier
	{
		var->map.max_size_y++;
		line = get_next_line(var->map.fd);
	}
	close(var->map.fd);
	var->map.tab = malloc(var->map.max_size_y * sizeof(char *));
	if (!var->map.tab)
		return (1);
	var->map.fd = open("./maps/map1.ber", O_RDONLY);
	line = get_next_line(var->map.fd);
	i = 0;
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
	while (var->map.taby < var->map.max_size_y)
	{
		var->map.tabx = 0;
		while (var->map.tab[var->map.taby][var->map.tabx] != '\0')
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
			else
				return (1);
		}
		var->map.taby++;
	}
	return (0);
}

int	first_last(t_data *var)
{
	int	i;

	i = 0;
	while (i < var->map.max_size_x)
	{
		if (var->map.tab[0][i] != '1')
			return (1);
		if (var->map.tab[var->map.max_size_y - 1][i] != '1')
			return (1);
		if (var->map.tab[var->map.max_size_y - 1][i + 1] == '\0' && i == var->map.max_size_x - 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_data *var)
{
	int	i;

	var->map.max_size_x = 0;
	i = 0;
	while (var->map.tab[0][var->map.max_size_x] != '\0')
		var->map.max_size_x++;
	printf("size_x: %d\n", var->map.max_size_x);
	if (first_last(var) != 0)
		return (1);
	return (0);
}

int	map_checker(t_data *var)
{
	if (check_char(var) != 0)
		return (1);
	if (check_wall(var) != 0)
		return (1);
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