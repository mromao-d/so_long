#include "so_long.h"

// validate if there is only one player & discovers starting coordinates
int	ft_nb_players_begin(char **map_char, t_map *map)
{
	int	i;
	int	j;
	int	players;

	i = -1;
	players = 0;
	while (map_char[++i])
	{
		j = -1;
		while (map_char[i][++j])
		{
			if (map_char[i][j] == 'P')
			{
				players++;
				map->p_pos_y = i;
				map->p_pos_x = j;
			}
		}
	}
	if (players != 1)
		return (0);
	// data->map_1_start_pos = 1;
	return (1);
}

// /* Funtion checks if the map has 1 exit only ('E').
// If yes return 1, else return 0. */
int	ft_nb_exits(char **map_char, t_map *map_set)
{
	int	i;
	int	j;
	int	exits;

	i = -1;
	exits = 0;
	while (map_char[++i])
	{
		j = -1;
		while (map_char[i][++j])
		{
			if (map_char[i][j] == 'E')
				exits++;
		}
	}
	if (exits != 1)
		return (0);
	return (1);
}

// /* Funtion checks if the map is enclosed (by '1').
// If map is enclosed return 1, else return 0. */
// int	map_is_enclosed(char **map, t_map *map_set)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		if (i == 0 || i == ft_count_map_lines(map) - 1)
// 		{
// 			j = 0;
// 			while (j <= (size_t)(map_set->x - 2))
// 			{
// 				if (map[i][j] != '1')
// 					return (0);
// 				j++;
// 			}
// 		}
// 		if (map[i][0] != '1')
// 			return (0);
// 		if (map[i][ft_strlen(map[i]) - 2] != '1')
// 			return (0);
// 		i++;
// 	}
// 	map_set->map_is_enclosed = 1;
// 	return (1);
// }

// validate uf all rows have the same len
// If map is rectangular return 1, else return 0. */
int	map_is_rectangular(char **map_char)
{
	int	i;
	int rows;
	int	height;

	rows = 0;
	i = ft_strlen(map_char[0]);
	while (map_char[rows] != 0)
	{
		if (map_char[rows + 1] == 0)
		{
			if (ft_strlen(map_char[rows]) + 1 != i)
				return (0);
		}
		else if (ft_strlen(map_char[rows]) != i)
			return (0);
		rows++;
	}
	if (rows < 3)
		return (0);
	return (1);
}

/* Funtion to check if char **map follows some conditions and if not,
 it frees the memory allocated for for the map and returns a 0.*/
int	ft_map_checklist(char **map_char, t_map *map, char *argv)
{
	if (!map_is_rectangular(map_char))
	{
		ft_free_t_map(map, 'a', argv);
		return (0);
	}
	// if (!map_is_enclosed(map, map_set))
	// {
	// 	free_t_map(map_set, 'b');
	// 	return (0);
	// }
	if (!ft_nb_exits(map_char, map) || !ft_nb_players_begin(map_char, map))
	{
		ft_free_t_map(map, 'c', argv);
		return (0);
	}
	// if (!map_has_colectibles(map, map_set) || !map_is_only_01pce(map, map_set))
	// {
	// 	free_t_map(map_set, 'd');
	// 	return (0);
	// }
	return (1);
}