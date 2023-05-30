/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:09:35 by mflury            #+#    #+#             */
/*   Updated: 2023/05/26 16:56:12 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	var_init(t_data *var)
{
	var->player.posx = 0;
	var->player.posy = 0;
	var->player.move_count = 1;
	var->map.tabx = 0;
	var->map.taby = 0;
	var->map.tabmaxx = 0;
	var->map.tabmaxy = 0;
	var->map.line = NULL;
	var->map.ecount = 0;
	var->map.pcount = 0;
	var->map.ccount = 0;
}

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// copier for map_parser.
// malloc tab for substring,
// write the line,
// pass to the next line,
// free the old gnl line,
// put the next line in the same variable as the last. (wow such optimisation)
char	*line_copier(t_data *var)
{
	var->map.tabx = 0;
	var->map.tab[var->map.taby]
		= malloc((var->map.tabmaxx) * sizeof(char *));
	if (!var->map.tab[var->map.taby])
		error("2nd malloc failed");
	while (var->map.tabx <= var->map.tabmaxx
		&& var->map.line[var->map.tabx] != '\n')
	{
		var->map.tab[var->map.taby][var->map.tabx]
			= var->map.line[var->map.tabx];
		var->map.tabx++;
		if (var->map.line[var->map.tabx] == '\n'
			|| var->map.line[var->map.tabx] == '\0')
			break ;
	}
	var->map.tab[var->map.taby][var->map.tabx] = '\0';
	var->map.taby++;
	free_line(var);
	var->map.line = get_next_line(var->map.fd);
	return (var->map.line);
}

// read the .ber and make a 2d tab out of it.
// count the numbers of lines,
// malloc the first tab with the number of lines.
// (count the last call "null", so it terminate with a '\0')
// then read line and sent it in tab via copier
int	map_parser(t_data *var, char *map_path)
{
	var->map.fd = open(map_path, O_RDONLY);
	if (var->map.fd < 0)
		error("Can't open file");
	var->map.line = get_next_line(var->map.fd);
	while (var->map.line)
	{
		free_line(var);
		var->map.tabmaxy++;
		var->map.line = get_next_line(var->map.fd);
	}
	close(var->map.fd);
	var->map.tab = malloc((var->map.tabmaxy + 1) * sizeof(char *));
	if (!var->map.tab)
		error("1st malloc failed");
	var->map.tab[var->map.tabmaxy] = NULL;
	var->map.fd = open(map_path, O_RDONLY);
	var->map.line = get_next_line(var->map.fd);
	var->map.tabmaxx = (ft_strlen(var->map.line));
	while (var->map.line)
	{
		var->map.line = line_copier(var);
	}
	free_line(var);
	return (0);
}

// call all the functions to make the map, the if checks for error.
// 1. read the .ber file and write it in a tab. return 1 if there is an error.
// 2. make all the checks to see if map is valid.
// 3. 
// 4. 
int	map_init(t_data *var, char *map_path)
{
	if (map_parser(var, map_path) != 0)
	{
		error("map parsing failed");
		return (1);
	}
	if (map_checker(var) != 0)
	{
		error("map checking failed");
		return (1);
	}
	return (0);
}
