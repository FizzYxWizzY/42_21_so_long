/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:29:02 by mflury            #+#    #+#             */
/*   Updated: 2023/05/26 20:02:30 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

void	error(char *msg)
{
	ft_printf("Error:\n%s\n", msg);
	exit (EXIT_FAILURE);
}

int	path_check(char *map_path)
{
	int	i;

	i = 0;
	while (map_path[i])
	{
		if (map_path[i] == '.' && map_path[i + 1] == 'b'
			&& map_path[i + 2] == 'e'
			&& map_path[i + 3] == 'r' && map_path[i + 4] == '\0' )
			return (0);
		i++;
	}
	return (1);
}

int	ft_succes_finish(t_data *var)
{
	ft_printf("player moves: %d\n", var->player.move_count);
	free_tab(var);
	free_line(var);
	exit (EXIT_SUCCESS);
}
