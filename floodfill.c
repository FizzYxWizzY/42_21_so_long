/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:19:13 by mflury            #+#    #+#             */
/*   Updated: 2023/05/17 18:50:57 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// duplicate tab into tmp, so we can modifie it for the floodfill.
// (it makes me sad that i have to copy it)
char	**map_copier(t_data *var)
{
	char	**tmp;

	var->map.taby = 0;
	tmp = malloc((var->map.tabmaxy + 1) * sizeof(char *));
	if (!tmp)
		error("tmp: 1st malloc failed");
	tmp[var->map.tabmaxy] = NULL;
	while (var->map.tab[var->map.taby])
	{
		tmp[var->map.taby] = malloc((var->map.tabmaxx + 1) * sizeof(char *));
		if (!tmp[var->map.taby])
			error("tmp: 2nd malloc failed");
		var->map.tabx = 0;
		while (var->map.tab[var->map.taby][var->map.tabx])
		{
			tmp[var->map.taby][var->map.tabx]
				= var->map.tab[var->map.taby][var->map.tabx];
			var->map.tabx++;
		}
		tmp[var->map.taby][var->map.tabx] = '\0';
		var->map.taby++;
	}
	return (tmp);
}

// find the player (*sip tea*)
void	player_finder(t_data *var, char **copy)
{
	var->map.taby = 0;
	while (copy[var->map.taby])
	{
		var->map.tabx = 0;
		while (copy[var->map.taby][var->map.tabx])
		{
			if (copy[var->map.taby][var->map.tabx] == 'P')
				return ;
			var->map.tabx++;
		}
		var->map.taby++;
	}
}

// looks at the case the floodfill is on, obviously.
void	case_checker(t_data *var, char **copy, int y, int x)
{
	if (copy[y][x] == 'P')
	{	
		copy[y][x] = '1';
		var->map.pcount--;
	}
	if (copy[y][x] == 'C')
	{
		copy[y][x] = '1';
		var->map.ccount--;
	}
	if (copy[y][x] == 'E')
	{	
		copy[y][x] = '1';
		var->map.ecount--;
	}
	if (copy[y][x] == '0')
	{	
		copy[y][x] = '1';
	}
}

// checks all the possible paths and checks if its possible to complet the map.
void	floodfill(t_data *var, char **copy, int y, int x)
{
	if (copy[y][x] == '1')
		return ;
	case_checker(var, copy, y, x);
	floodfill(var, copy, y + 1, x);
	floodfill(var, copy, y - 1, x);
	floodfill(var, copy, y, x + 1);
	floodfill(var, copy, y, x - 1);
}

//use la the things above
int	floodfiller(t_data *var)
{
	char	**copy;
	int		i;
	int		y;
	int		x;

	i = 0;
	copy = map_copier(var);
	player_finder(var, copy);
	y = var->map.taby;
	x = var->map.tabx;
	floodfill(var, copy, y, x);
	free_copy(copy);
	if (var->map.ecount != 0)
		error("Player cant access the exit. (E)");
	if (var->map.ccount != 0)
		error("Player cant access all the items. (C)");
	if (var->map.pcount != 0)
		error("too much or too few player pos. (P)");
	return (0);
}
