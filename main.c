/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:39:42 by mflury            #+#    #+#             */
/*   Updated: 2023/04/28 19:11:06 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	var;
	int	i = 0;

	var_init(&var);
	map_parser(&var);
	// while (var.map.tab)
	// {
	// printf("%s", var.map.tab[i]);
	// i++;
	// }
	printf("\n\n");
	while (var.map.tab[i])
	{
	printf("tab= %s\n", var.map.tab[i]);
	i++;
	}
	return (0);
}
