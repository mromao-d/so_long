#include "so_long.h"

// loads the images files. the loaded images are mapped throught pointers
int	ft_load_images(t_data *data)
{
	int			x;
	int			y;
	t_map_props	*props;

	x = PX;
	y = PX;
	props = (t_map_props *)ft_calloc(sizeof(props), 1);
	if (!props)
		return (0);
	props->coin = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/monster_64x64-overlay.xpm", &x, &y);
	props->path = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/dirt_path_64x64-overlay.xpm", &x, &y);
	props->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/bushes_64x64-overlay.xpm", &x, &y);
	props->packman = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/saitama_64x64-overlay.xpm", &x, &y);
	props->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/food_64x64-overlay.xpm", &x, &y);
	data->props = props;
	// printf("here from load imgs\n");
	return (1);
}

// put the images into the window
void	ft_put_image(t_data *data, int height, int width)
{
	if (data->map->map[height][width] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->props->coin, width * PX, height * PX);
	else if (data->map->map[height][width] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->props->path, width * PX, height * PX);
	else if (data->map->map[height][width] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->props->wall, width * PX, height * PX);
	else if (data->map->map[height][width] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->props->packman, width * PX, height * PX);
	else if (data->map->map[height][width] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->props->exit, width * PX, height * PX);
}

// fill the map area with the images
void	ft_fill_map_w_img(t_data *data)
{
	int	height;
	int	width;

	height = 0;
	while (height < data->map->y)
	{
		width = 0;
		while (width < data->map->x)
		{
			ft_put_image(data, height, width);
			width++;
		}
		height++;
	}
	return ;
}
