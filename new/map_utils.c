/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:00:19 by mromao-d          #+#    #+#             */
/*   Updated: 2024/01/07 17:19:14 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// count the number of lines the map has, needed to alloc memory and store its content
int	ft_get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line != 0)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (height);
}

// int	ft_get_width(char *file_name)
// {
// 	int	i;

// 	i = 0;
// 	while (file_name[++i] != 0)
// 		;
// 	return i;
// }

// Alloc memoire for the map content in a matrix (array of strings)
char	**ft_read_file(char *file_name)
{
	char	**out;
	int		fd;
	int		i;
	int		height;

	// data->height = ft_get_height(file_name);
	// data->width = ft_get_width(file_name);
	height = ft_get_height(file_name);
	out = (char **)ft_calloc(sizeof(char *), (height + 1));
	if (!out)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || fd > 4096)
		return (0);
	i = 0;
	while (i < height)
	{
		out[i] = get_next_line(fd);
		i++;
	}
	out[i] = 0;
	// ft_print_map(out);
	close(fd);
	return (out);
}

// validate if map has an reachable exit. Paints the canvas paths that has passed with a wall
// and continues till it finds an exit. If it finds the exit, it marks the "has_exit" as 1.
void	ft_validate_map(t_map *map, char **fake_map, int p_pos_y, int p_pos_x)
{
	if (!(p_pos_y >= 0 && p_pos_y < (map->y -1) && p_pos_x >= 0 && p_pos_x < ((map->x) - 1)))
		return ;
	// printf("Here from validate map\n");
	if (map->map[p_pos_y][p_pos_x] == '1')
	{
		// printf("blocked here!\n");
		return ;
	}
	// printf("Here from validate map 2\n");
	if (fake_map[p_pos_y][p_pos_x] == '1')
		return ;
	if (map->map[p_pos_y][p_pos_x] == 'E')
	{
		map->has_exit = 1;
		return ;
	}
	if (map->map[p_pos_y][p_pos_x] == 'C' && fake_map[p_pos_y][p_pos_x] != '1')
		map->nb_coins++;
	fake_map[p_pos_y][p_pos_x] = '1';
	ft_validate_map(map, fake_map, p_pos_y + 1, p_pos_x);
	ft_validate_map(map, fake_map, p_pos_y, p_pos_x + 1);
	ft_validate_map(map, fake_map, p_pos_y - 1, p_pos_x);
	ft_validate_map(map, fake_map, p_pos_y, p_pos_x - 1);
	return ;
}

/* Funtion to create a (char **) with the same size as (char **) map. */
char	**ft_map_clone(int y, int x)
{
	char	**map;
	int		i;

	map = (char **)ft_calloc(y, sizeof(char *));
	i = 0;
	while (i < y)
	{
		map[i] = (char *)ft_calloc(x + 1, sizeof(char));
		i++;
	}
	return (map);
}

void	ft_print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		// printf("\n");
		i++;
	}
}

t_map	*ft_init_map(char *argv)
{
	t_map	*map;
	char	**map_clone;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	map->map = ft_read_file(argv);
	map->argv = ft_strdup(argv);
	printf("%s\n", map->argv);
	// ft_print_map(map->map);
	if (!map->map)
	{
		free(map);
		free(map->map);
		return (0);
	}
	map->y = ft_get_height(argv);
	map->x = ft_strlen(map->map[0]);
	printf("y is: %d, x is : %d\n", map->y, map->x);
	if (!ft_map_checklist(map->map, map, argv))
		return (0);
	map->all_coins = ft_has_coins(map->map);
	printf("coins are: %d\n", map->all_coins);
	if (map->all_coins < 1)
	{	
		printf("No coins");
		return(0);
	}
	// ft_print_map(map->map);
	// printf("%d\n", map->all_coins);
	map_clone = ft_map_clone(map->y, map->x);
	printf("p_pos_y is:	%d	and p_pos_x is:%d\n", map->p_pos_y, map->p_pos_x);
	ft_validate_map(map, map_clone, map->p_pos_y, map->p_pos_x);
	// ft_free_map(map_clone, argv);
	// free_map(map_file, map->y);
	// if (!(map->has_exit)
	// 	|| !(map->nb_coins == map->all_coins))
	// 	return (free_t_map(map, 'e'));
	// ft_print_map(map->map);
	// printf("here from init map\n");
	return (map);
}
