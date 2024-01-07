/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:28:58 by mromao-d          #+#    #+#             */
/*   Updated: 2024/01/07 17:25:40 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include ".mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

# define PX 64


typedef struct s_map
{
	int			x;
	int			y;
	int			map_is_rectangular;
	int			map_is_enclosed;
	int			map_1_exit;
	int			map_1_start_pos;
	int			map_is_only_01pce;
	int			map_has_colectibles;
	int			number_of_c;
	int			map_goal_exit;
	int			map_goal_c;

	int			p_pos_y;
	int			p_pos_x;

	char		**map;
}				t_map;

typedef struct s_sprite
{
	void		*wall;
	void		*collectible;
	void		*player;
	void		*path;
	void		*exit;
}				t_sprite;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	/* t_sprite	*sprite; */
	int			nbr_moves;
	t_map		*map;
}				t_data;

t_map	*ft_init_map(char *argv);

#endif
