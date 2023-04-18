/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:12:31 by mflury            #+#    #+#             */
/*   Updated: 2023/04/18 23:17:48 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check if all the first line is only walls. (top of the map)
// check if all the last line is only walls. (bottom of the map)
int	first_last_line(t_data *var)
{
	var->map.tabx = 0;
	while (var->map.tab[0][var->map.tabx] != '\0')
	{
		if (var->map.tab[0][var->map.tabx] != '1')
			return (1);
		var->map.tabx++;
	}
	var->map.tabx = 0;
	while (var->map.tab[var->map.tabmaxy - 1][var->map.tabx] != '\0')
	{
		if (var->map.tab[var->map.tabmaxy - 1][var->map.tabx] != '1')
			return (1);
		var->map.tabx++;
	}
	return (0);
}
// check if all the first column is only walls. (left of the map)
// check if all the last column is only walls. (right of the map)
int	first_last_column(t_data *var)
{
	var->map.taby = 0;
	while (var->map.tab[var->map.taby][0] != '\0')
	{
		if (var->map.tab[var->map.taby][0] != '1')
			return (1);
		var->map.taby++;
	}
	var->map.taby = 0;
	while (var->map.tab[var->map.taby][0] != '\0')
	{
		if (var->map.tab[var->map.taby - 1][var->map.tabmaxx - 1] != '1')
			return (1);
		var->map.taby++;
	}
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
// 2. check if map border is made of walls.
// 3.
int	map_checker(t_data *var)
{
	if (char_checker(var) != 0)
		return (1);
	if (wall_checker(var) != 0)
		return (1);
	if (_checker(var) != 0)
		return (1);
	return (0);
}
