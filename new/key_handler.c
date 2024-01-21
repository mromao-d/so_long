#include "so_long.h"

int	ft_coin_pls_end(t_data *data, int y, int x)
{
	if (data->map->map[y][x] == 'C')
		data->map->nb_coins--;
	if (data->map->map[y][x] == 'E' && data->map->nb_coins > 0)
		return (0);
	if (data->map->map[y][x] == 'E' && data->map->nb_coins == 0)
	{
		ft_close_handler(data);
		printf("You won mate!");
	}
	return (1);
}

void	ft_mv_down(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->map->p_pos_x;
	pos_y = data->map->p_pos_y;
	if ((pos_y + 1 < data->map->y) && (data->map->map[pos_y + 1][pos_x] != '1' ))
	{
		if (!(ft_coin_pls_end(data, pos_y + 1, pos_x)))
			return ;
		data->map->p_pos_y++;
		data->map->map[pos_y + 1][pos_x] = 'P';
		data->map->map[pos_y][pos_x] = '0';
		ft_put_image(data, pos_y, pos_x);
		ft_put_image(data, pos_y + 1, pos_x);
	}
	return ;
}

void	ft_mv_up(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->map->p_pos_x;
	pos_y = data->map->p_pos_y;
	if ((pos_y - 1 > 0) && (data->map->map[pos_y - 1][pos_x] != '1' ))
	{
		if (!(ft_coin_pls_end(data, pos_y - 1, pos_x)))
			return ;
		data->map->p_pos_y--;
		data->map->map[pos_y - 1][pos_x] = 'P';
		data->map->map[pos_y][pos_x] = '0';
		ft_put_image(data, pos_y, pos_x);
		ft_put_image(data, pos_y - 1, pos_x);
	}
	return ;
}

void	ft_mv_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->map->p_pos_x;
	pos_y = data->map->p_pos_y;
	if ((pos_x - 1 > 0) && (data->map->map[pos_y][pos_x - 1] != '1' ))
	{
		if (!(ft_coin_pls_end(data, pos_y, pos_x - 1)))
			return ;
		data->map->p_pos_x--;
		data->map->map[pos_y][pos_x - 1] = 'P';
		data->map->map[pos_y][pos_x] = '0';
		ft_put_image(data, pos_y, pos_x);
		ft_put_image(data, pos_y, pos_x - 1);
	}
	return ;
}

void	ft_mv_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->map->p_pos_x;
	pos_y = data->map->p_pos_y;
	if ((pos_x + 1 < data->map->x - 1) && (data->map->map[pos_y][pos_x + 1] != '1' ))
	{
		if (!(ft_coin_pls_end(data, pos_y, pos_x + 1)))
			return ;
		data->map->p_pos_x++;
		data->map->map[pos_y][pos_x + 1] = 'P';
		data->map->map[pos_y][pos_x] = '0';
		ft_put_image(data, pos_y, pos_x + 1);
		ft_put_image(data, pos_y, pos_x);
	}
	return ;
}
