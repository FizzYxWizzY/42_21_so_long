/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflury <mflury@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:53:16 by mflury            #+#    #+#             */
/*   Updated: 2023/04/18 23:17:43 by mflury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <mlx.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_pdata {
	char		*relative_path_player;
	int			posx;
	int			posy;
}				t_pdata;

typedef struct s_mdata {
	int			fd;
	char		*line;
	char		**tab; 
	int			tabx;
	int			taby;
	int			tabmaxx; // set in map_parser, used to know the end of the line.
	int			tabmaxy; // set in map_parser, used to know end of tab[]
	// int			groundx;
	// int			groundy;
	// int			wallx;
	// int			wally;
	// int			doorx;
	// int			doory;
	// int			itemx;
	// int			itemy;
	char		*relative_path_ground;
	char		*relative_path_wall;
	char		*relative_path_door;
	char		*relative_path_item;
	
}				t_mdata;

typedef struct s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	t_pdata		player;
	t_mdata		map;
}				t_data;

int		so_long(void);

void	move_up(int keycode, t_data *var);
void	move_left(int keycode, t_data *var);
void	move_down(int keycode, t_data *var);
void	move_right(int keycode, t_data *var);

int		init_game(t_data *var);
int		init_map(t_data *var)
int		map_parser(t_data *var);
char	*line_copier(t_data *var, char *line);
int		map_checker(t_data *var);
int		char_checker(t_data *var);
int		wall_checker(t_data *var);
int		first_last_column(t_data *var);
int		first_last_line(t_data *var);

// void	ground_builder(t_data *var);
// void	wall_builder(t_data *var);
// void	item_builder(t_data *var);

#endif

/*
		  0|1|2|3|4|5|6| 7| 8|
-----------|-|-|-|-|-|-|--|--|
tab [0] | 1|1|1|1|1|1|3|\n|\0|
tab [1] | 1|0|0|0|C|0|1|\n|\0|

tab[1][4] = C


		// definis le nombre d index du tableau (int)
tab = malloc(2 * sizeof(char *));
		// definis le nombre de cases a l'index x du tableau
tab[0] = malloc(8 * sizeof(char));
tab[1] = malloc(8 * sizeof(char));

*/