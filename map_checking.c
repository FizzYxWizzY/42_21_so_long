/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:12:31 by mflury            #+#    #+#             */
/*   Updated: 2023/04/17 20:06:45 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"







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

//
//
//
int	map_checker(t_data *var)
{
	if (char_checker(var) != 0)
		return (1);
	if (check_wall(var) != 0)
		return (1);
	return (0);
}
