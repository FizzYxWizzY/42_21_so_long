/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:35:24 by mflury            #+#    #+#             */
/*   Updated: 2023/05/10 17:25:47 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_line(t_data *var)
{
	if (!var->map.line)
		return ;
	free(var->map.line);
	var->map.line = NULL;
}

void	free_copy(char **copy)
{
	int	i;

	i = 0;
	if (!copy)
		return ;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
	copy = NULL;
}

void	free_tab(t_data *var)
{
	int	i;

	i = 0;
	if (!var->map.tab)
		return ;
	while (var->map.tab[i])
	{
		free(var->map.tab[i]);
		i++;
	}
	free(var->map.tab);
	var->map.tab = NULL;
}