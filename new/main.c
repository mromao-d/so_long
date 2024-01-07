/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:17:35 by mromao-d          #+#    #+#             */
/*   Updated: 2024/01/07 17:01:43 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_press_cross(t_data *data)
{
	int	line;

	line = 0;
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	// while (line <= data->height)
	// {
	// 	free(data->z_matrix_int[line]);
	// 	line++;
	// }
	// free(data->z_matrix_int);
	free(data);
	exit(0);
}

int	ft_close_window(t_data *data)
{
	// ft_free_matrix(data);
	if (!data->win_ptr || !data->win_ptr)
	{
		free(data);
		exit(0);
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
}

int	ft_deal_key(int key, t_data *fdf)
{
	printf("%d\n", key);
	free(fdf);
	// if (key == 65363)
	// 	fdf->shift_x += 10;
	// if (key == 65361)
	// 	fdf->shift_x -= 10;
	// if (key == 65364)
	// 	fdf->shift_y += 10;
	// if (key == 65362)
	// 	fdf->shift_y -= 10;
	// if (key == 65307)
	// 	ft_close_window(fdf);
	// // // else
	// // // 	return (0);
	// // mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	// // ft_draw(fdf, img);
	// // mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, img.img, 0, 0);
	return (0);
}

static int	ft_init(t_data   *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
		// return (free_mlx(data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->map->x - 1) * PX, data->map->y * PX, "so_long");
	if (!data->win_ptr)
		return (1);
		// return (free_mlx(data));
	// if (!open_image(data))
	// 	return (1);
		// return (free_mlx(data));
	// add_images_to_game(data);
	mlx_hook(data->win_ptr, 17, 1L << 17, ft_press_cross, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, ft_deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*win;

	(void) argv;
	(void) argc;
	win = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!win)
		return (0);
	// win->map = ft_init_map(argv[1]);
	if (!win->map)
	{
		free(win);
		return (0);
	}
	ft_init(win);
}
