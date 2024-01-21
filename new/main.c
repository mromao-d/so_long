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

int	ft_deal_key(int key, t_data *data)
{
	printf("%d\n", key);
	if (key == ESC)
		ft_close_handler(data);
	if (key == RIGHT || key == RIGHT_)
		ft_mv_right(data);
	if (key == UP || key == UP_)
		ft_mv_up(data);
	if (key == DOWN || key == DOWN_)
		ft_mv_down(data);
	if (key == LEFT || key == LEFT_)
		ft_mv_left(data);

	// free(fdf);
	// if (key == 65363)
	// 	fdf->shift_x += 10;
	// if (key == 65361)
	// 	fdf->shift_x -= 10;
	// if (key == 65364)
	// 	fdf->shift_y += 10;
	// if (key == 65362)
	// 	fdf->shift_y -= 10;
	// // // else
	// // // 	return (0);
	// // mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	// // ft_draw(fdf, img);
	// // mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, img.img, 0, 0);
	return (0);
}

static int	ft_init_game(t_data   *data, char *argv)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (ft_free_mlx(data, argv));
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->map->x - 1) * PX, data->map->y * PX, "so_long");
	if (!data->win_ptr)
		return (ft_free_mlx(data, argv));
	if (!ft_load_images(data))
	{
		printf("impossible to print images\n");
		return (ft_free_mlx(data, argv));
	}
	ft_fill_map_w_img(data);
	mlx_hook(data->win_ptr, 17, 1L << 17, ft_press_cross, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, ft_deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*win;

	if (!(ft_check_args(argc, argv[1])))
		return (0);
	win = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!win)
		return (0);
	win->map = ft_init_map(argv[1]);
	win->map->nb_img=0;
	if (!win->map)
	{
		return (free(win), 0);
	}
	// printf("here from another here\n");
	ft_init_game(win, argv[1]);
}
