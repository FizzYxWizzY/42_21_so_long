/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:38:25 by mflury            #+#    #+#             */
/*   Updated: 2023/04/24 16:52:11 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// count the number of P,C,E in the map.
void	pce_counter(t_data *var)
{
	var->map.taby = 0;
	while (var->map.taby < var->map.tabmaxy)
	{
		var->map.tabx = 0;
		while (var->map.tab[var->map.taby][var->map.tabx] != '\0')
		{
			else if (var->map.tab[var->map.taby][var->map.tabx] == 'E')
			{
				var->map.ecount++;
				var->map.tabx++;
			}
			else if (var->map.tab[var->map.taby][var->map.tabx] == 'C')
			{
				var->map.ccount++;
				var->map.tabx++;
			}
			else if (var->map.tab[var->map.taby][var->map.tabx] == 'P')
				var->map.pcount++;
				var->map.tabx++;
			else
				var->map.tabx++;
		}
		var->map.taby++;
	}
	return ;
}

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
