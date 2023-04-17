/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:09:35 by mflury            #+#    #+#             */
/*   Updated: 2023/04/17 20:06:47 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// copier for map_parser.
// malloc tab for substring,
// write the line,
// pass to the next line,
// free the old gnl line,
// put the next line in the same variable as the last. (wow such optimisation)
char	*line_copier(t_data *var, char *line)
{
	var->map.tab[var->map.taby] = malloc(var->map.tabmaxx * sizeof(char *));
	if (!var->map.tab[var->map.taby])
		return (1);
	while (var->map.tabx < var->map.tabmaxx && line[var->map.tabx] != '\n')
	{
		var->map.tab[var->map.taby][var->map.tabx] = line[var->map.tabx];
		if (line[var->map.tabx + 1] = '\n' || line[var->map.tabx + 1] = '\0')
			break ;
		var->map.tabx++;
	}
	var->map.tab[var->map.taby][var->map.tabx + 1] = '\0';
	free(line);
	line = get_next_line(var->map.fd);
	return (line);
}

// read the .ber and make a 2d tab out of it.
// count the numbers of lines,
// malloc the first tab with the number of lines.
// (count the last call "null", so it terminate with a '\0')
// then read line and sent it in tab via copier
int	map_parser(t_data *var)
{
	var->map.fd = open("./maps/map1.ber", O_RDONLY);
	line = get_next_line(var->map.fd);
	while (line)
	{
		var->map.tabmaxy++;
		line = get_next_line(var->map.fd);
	}
	close(var->map.fd);
	var->map.tab = malloc(var->map.tabmaxy * sizeof(char *));
	if (!var->map.tab)
		return (1);
	var->map.fd = open("./maps/map1.ber", O_RDONLY);
	line = get_next_line(var->map.fd);
	var->map.tabmaxx = ft_strlen(line);
	while (line)
	{
		line = line_copier(var, line);
	}
	return (0);
}

// call all the functions to make the map, the if checks for error.
// 1. read the .ber file and write it in a tab. return 1 if there is an error.
// 2. 
int	init_map(t_data *var)
{
	if (map_parser(var) != 0)
		return (1);
	if (map_checker(var) != 0)
		return (1);
	if (f(var) != 0)
		return (1);
	if (f(var) != 0)
		return (1);

	free(var->map.tab);
	return (0);
}
