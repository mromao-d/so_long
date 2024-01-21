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
# include "libft/libft.h"
# include <math.h>


# define PX 64
// # define KEY_ESC 65307
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define UP_ 126
# define DOWN_ 125
# define LEFT_ 123
# define RIGHT_ 124
# define ESC 53


typedef struct s_map
{
	char		**map;
	char		*argv;

	int			x;
	int			y;
	int			nb_img;
	int			all_coins;
	int			has_exit;
	int			nb_coins;
	int			p_pos_y;
	int			p_pos_x;

}				t_map;

typedef struct s_map_props
{
	void		*coin;
	void		*path;
	void		*wall;
	void		*packman;
	void		*exit;
}				t_map_props;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			nbr_moves;
	t_map		*map;
	t_map_props	*props;
}				t_data;

t_map	*ft_init_map(char *argv);
int		ft_has_coins(char	**file_name);
int		ft_get_height(char *file_name);

// map_props
int		ft_load_images(t_data *data);
void	ft_fill_map_w_img(t_data *data);
void	ft_put_image(t_data *data, int height, int width);

// map_utils
void	ft_print_map(char **map);

// free
void	ft_free_map(char **map, char *argv);
int	ft_free_mlx(t_data *data, char *argv);
t_map	*ft_free_t_map(t_map *map, char error, char *argv);

// map_check
int	ft_map_checklist(char **map_char, t_map *map, char *argv);

// key_handler
void	ft_mv_down(t_data *data);
void	ft_mv_up(t_data *data);
void	ft_mv_left(t_data *data);
void	ft_mv_right(t_data *data);


// free
int ft_close_handler(t_data *data);
int	ft_free_mlx(t_data *data, char *argv);

// map_validations
int	ft_check_args(int argc, char *argv);

#endif
