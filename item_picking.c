/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_picking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 21:37:27 by mflury            #+#    #+#             */
/*   Updated: 2023/05/26 19:30:33 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	item_counter(t_data *var)
{
	var->map.taby = 0;
	var->map.ccount = 0;
	while (var->map.tab[var->map.taby])
	{
		var->map.tabx = 0;
		while (var->map.tab[var->map.taby][var->map.tabx])
		{
			if (var->map.tab[var->map.taby][var->map.tabx] == 'C')
				var->map.ccount++;
			var->map.tabx++;
		}
		var->map.taby++;
	}
}

void	item_picker(t_data *var)
{
	item_counter(var);
	if (var->map.tab[var->player.posy / 100][var->player.posx / 100] == 'C')
	{	
		var->map.tab[var->player.posy / 100][var->player.posx / 100] = '0';
		item_counter(var);
	}
}
