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
	close(fd);
	return (out);
}

// 
t_map	*map_init(char *argv)
{
	t_map	*map_set;
	char	**map_canvas;

	map_set = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map_set)
		return (0);
	map_set->map = map_reader(argv);
	if (!map_set->map)
	{
		free(map_set);
		free(map_set->map);
		return (0);
	}
	map_set->y = ft_count_lines(argv);
	map_set->x = ft_strlen(map_set->map[0]);
	if (!map_checklist(map_set->map, map_set))
		return (0);
	map_set->number_of_c = number_of_c(map_set->map);
	map_canvas = map_blank(map_set->y, map_set->x);
	map_goal_possible(map_set, map_canvas, map_set->p_pos_y, map_set->p_pos_x);
	free_map(map_canvas, map_set->y);
	if (!(map_set->map_goal_exit)
		|| !(map_set->map_goal_c == map_set->number_of_c))
		return (free_t_map(map_set, 'e'));
	return (map_set);
}
