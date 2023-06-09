/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:12:31 by mflury            #+#    #+#             */
/*   Updated: 2023/05/26 19:49:15 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	form_checker(t_data *var)
{
	size_t	lenght;

	var->map.taby = 0;
	lenght = ft_strlen(var->map.tab[var->map.tabmaxy - 1]);
	while (var->map.taby < var->map.tabmaxy - 1)
	{
		if (lenght != ft_strlen(var->map.tab[var->map.taby]))
			return (1);
		var->map.taby++;
	}
	return (0);
}

int	pce_checker(t_data *var)
{
	pce_counter(var);
	if (var->map.pcount != 1)
		return (1);
	if (var->map.ccount < 1)
		return (1);
	if (var->map.ecount != 1)
		return (1);
	else
		return (0);
}

// check if the map is closed by walls.
// 1. check the first and the last line of the tab.
// 2. check the first and last column of the tab.
int	wall_checker(t_data *var)
{
	if (first_last_line(var) != 0)
		return (1);
	if (first_last_column(var) != 0)
		return (1);
	return (0);
}

// function that check all the tab to see if it only contain valid char.
int	char_checker(t_data *var)
{
	var->map.taby = 0;
	while (var->map.taby < var->map.tabmaxy)
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

// test if map is valid.
// 1. check if there is only valid chars (0, 1, P, C, E).
// 2. check if all the map border is made of walls.
// 3. check if there is one player initial position.
//  check if there is an exit.
// 	check if there is at least a collectible.
int	map_checker(t_data *var)
{
	if (form_checker(var) != 0)
	{
		error("map isn't rectangular.\n");
		return (1);
	}
	if (char_checker(var) != 0)
	{
		error("map contains invalid chars.\n");
		return (1);
	}
	if (wall_checker(var) != 0)
	{
		error("map is not closed by walls.\n");
		return (1);
	}
	if (pce_checker(var) != 0)
	{
		error("map doesnt have all the pce required\n");
		return (1);
	}
	floodfiller(var);
	return (0);
}
