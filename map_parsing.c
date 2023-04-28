/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:09:35 by mflury            #+#    #+#             */
/*   Updated: 2023/04/28 19:11:08 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	var_init(t_data *var)
{
	var->player.posx = 0;
	var->player.posy = 0;
	var->map.tabx = 0;
	var->map.taby = 0;
	var->map.tabmaxx = 0;
	var->map.tabmaxy = 0;
	var->map.line = NULL;
	// var->map.ecount = 0;
	// var->map.pcount = 0;
	// var->map.ccount = 0;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// copier for map_parser.
// malloc tab for substring,
// write the line,
// pass to the next line,
// free the old gnl line,
// put the next line in the same variable as the last. (wow such optimisation)
char	*line_copier(t_data *var)
{
	var->map.tabx = 0;
	var->map.tab[var->map.taby] = malloc((var->map.tabmaxx + 1) * sizeof(char *));
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
	var->map.tab[var->map.taby][var->map.tabx + 1] = '\0';
	var->map.taby++;
	free(var->map.line);
	var->map.line = get_next_line(var->map.fd);
	return (var->map.line);
}

// read the .ber and make a 2d tab out of it.
// count the numbers of lines,
// malloc the first tab with the number of lines.
// (count the last call "null", so it terminate with a '\0')
// then read line and sent it in tab via copier
int	map_parser(t_data *var)
{
	var->map.fd = open("maps/map1.ber", O_RDONLY);
	if (var->map.fd < 0)
		error("Can't open file");
	var->map.line = get_next_line(var->map.fd);
	while (var->map.line)
	{
		var->map.tabmaxy++;
		var->map.line = get_next_line(var->map.fd);
	}
	close(var->map.fd);
	printf("number of lines: %i\n", var->map.tabmaxy); // actually OK 'til here. 4
	var->map.tab = malloc((var->map.tabmaxy + 1) * sizeof(char *));
	if (!var->map.tab)
		error("1st malloc failed");
	var->map.tab[var->map.tabmaxy + 1] = NULL;
	printf("null terminated 1st malloc: %s\n", var->map.tab[var->map.tabmaxy + 1]); // actually OK 'til here. NULL
	var->map.fd = open("maps/map1.ber", O_RDONLY);
	var->map.line = get_next_line(var->map.fd);
	var->map.tabmaxx = (ft_strlen(var->map.line));
	printf ("line lenght = %d\n", var->map.tabmaxx); // return 7 (count the \n)
	while (var->map.line != NULL)
	{
		printf("LINE= %s", var->map.line); // actually have the right line in it. OK 'til here.
		var->map.line = line_copier(var);
	}
	return (0);
}

// call all the functions to make the map, the if checks for error.
// 1. read the .ber file and write it in a tab. return 1 if there is an error.
// 2. make all the checks to see if map is valid.
// 3. 
// 4. 
int	init_map(t_data *var)
{
	if (map_parser(var) != 0)
		return (1);
	//if (map_checker(var) != 0)
	//	return (1);
	// if (map_builder(var) != 0)
	// 	return (1);
	//if (f(var) != 0)
	//	return (1);

	// free(var->map.tab);
	return (0);
}
