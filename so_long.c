/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:55:11 by mflury            #+#    #+#             */
/*   Updated: 2023/03/20 16:14:36 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
}				t_data;

void	my_mlx_pixel_put(t_data *var, int x, int y, int color)
{
	char	*dst;

	dst = var->addr + (y * var->line_length + x * (var->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_close(int keycode, t_data *var)
{
	printf("Keycode : %d\n", keycode);
	(void) var;
	if (keycode == 53)
	{
		// mlx_destroy_window(var->mlx, var->mlx_win);
		printf("pressed esc = %d\n", keycode);
		exit (0);
	}
	return (0);
}

int	my_close2(t_data *var)
{

	printf("red cross");
	mlx_destroy_window(var->mlx, var->mlx_win);
	exit (0);
	return (0);
}

int	main(void)
{
	t_data	var;

	var.mlx = mlx_init();
	var.mlx_win = mlx_new_window(var.mlx, 1920, 1080, "mlx de merde!");
	var.img = mlx_new_image(var.mlx, 1920, 1080);
	var.addr = mlx_get_data_addr(var.img, &var.bits_per_pixel, &var.line_length,
			&var.endian);
	my_mlx_pixel_put(&var, 500, 500, 0x00FF0000);
	mlx_put_image_to_window(var.mlx, var.mlx_win, var.img, 0, 0);
	mlx_hook(var.mlx_win, ON_KEYDOWN, 0, &my_close, var.mlx);
	mlx_hook(var.mlx_win, ON_DESTROY, 0, &my_close2, var.mlx);
	mlx_loop(var.mlx);
}
