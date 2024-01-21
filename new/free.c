/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   free.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mromao-d <mromao-d@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/07 16:33:06 by mromao-d		  #+#	#+#			 */
/*   Updated: 2024/01/07 16:33:08 by mromao-d		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

// frees map
void	ft_free_map(char **map, char *argv)
{
	int i;
	int j;

	i = -1;
	j = ft_get_height(argv);
	while (++i < j)
		free(map[i]);
	return(free(map));
}

int ft_close_handler(t_data *data)
{
	ft_free_map(data->map->map, data->map->argv);
	exit (0);
}

int	ft_free_mlx(t_data *data, char *argv)
{
	ft_free_map(data->map->map, argv);
	if (data->mlx_ptr && data->win_ptr)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->props->wall);
		mlx_destroy_image(data->mlx_ptr, data->props->coin);
		mlx_destroy_image(data->mlx_ptr, data->props->packman);
		mlx_destroy_image(data->mlx_ptr, data->props->path);
		mlx_destroy_image(data->mlx_ptr, data->props->exit);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	free(data->props);
	free(data->map);
	free(data->mlx_ptr);
	free(data->map->argv);
	free(data);
	exit(0);
	return (1);
}

t_map	*ft_free_t_map(t_map *map, char error, char *argv)
{
	ft_free_map(map->map, argv);
	free(map);
	map = NULL;
	if (error == 'a')
		ft_printf("Error\nMap isn't rectangular\n");
	if (error == 'b')
		ft_printf("Error\nMap isn't enclosed by walls\n");
	if (error == 'c')
		ft_printf("Error\nPlayer start position or map exit \
is different than 1.\n");
	if (error == 'd')
		ft_printf("Error\nMap doesn't have collectibles or \
map has an invalid	element(!01PCE)\n");
	if (error == 'e')
		ft_printf("Error\nIs not possible for the the player \
to reach all collectibles and the exit\n");
	return (map);
}
