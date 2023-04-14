TODO: REFACTOR THE MAPPING FUNCTIONS!













char	*line_copier(t_data *var, char *line)
{
	var->map.tab[var->map.taby] = malloc(ft_strlen(line) * sizeof(char *));
	if (!var->map.tab[var->map.taby])
		return (1);
	while ()
}

// read the .ber and make a 2d tab out of it.
// count the numbers of lines,
// malloc the first tab with the number of lines.
// then read line and sent it in tab via copier
int	map_parser(t_data *var)
{
	var->map.fd = open("./maps/map1.ber", O_RDONLY);
	line = get_next_line(var->map.fd);
	while (line)
	{
		var->map.tabmaxy++;
		line = get_next_line(var->map.fd);
	}
	close(var->map.fd);
	var->map.tab = malloc(var->map.tabmaxy * sizeof(char *));
	if (!var->map.tab)
		return (1);
	var->map.fd = open("./maps/map1.ber", O_RDONLY);
	line = get_next_line(var->map.fd);
	while (line)
	{
		line = line_copier(var, line);
	}
	return (0);
}

// call all the functions to make the map, the if checks for error.
// 1. read the .ber file and write it in a tab. return 1 if there is an error.
// 2. 
int	init_map(t_data *var)
{
	if (map_parser(var) != 0)
		return (1);
	if (f(var) != 0)
		return (1);
	if (f(var) != 0)
		return (1);
	if (f(var) != 0)
		return (1);

	free(var->map.tab);
	return (0);
}
