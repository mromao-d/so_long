#include "so_long.h"

int	ft_map_name(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (!(argv[i - 1] == 'r' && argv[i-2] == 'e' && argv[i-3] == 'b' && argv[i-4] == '.'))
	{	
		ft_printf("ERROR\nwrong filename");
		return (0);
	}
	if (ft_strncmp(argv, "maps/", 5) != 0)
	{
		ft_printf("ERROR\nWrong Extension");
		return(0);
	}
	return (1);
}

int	ft_check_args(int argc, char *argv)
{
	int	fd;

	if (argc != 2 || !ft_map_name(argv))
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR!\nWrong filename does not exist!\n");
		return (0);
	}
	close (fd);
	return (1);
}

// validate if the file has all the shitty chars --> others than '0' '1' 'P' 'C' 'E'. returns 1 if true
// protection alert
int	ft_has_all(char	**file_name)
{
	int	i;
	int	j;

	i = -1;
	while (file_name[++i])
	{
		j = -1;
		while (file_name[i][++j])
		{
			if (file_name[i][j] != '0' && file_name[i][j] != '1' && file_name[i][j] != 'P' && file_name[i][j] != 'C' && file_name[i][j] != 'E')
				return (0);
		}
	}
	return (1);
}

// validate if file has coins (C) somewhere. Returns 1 if true
int	ft_has_coins(char	**file_name)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while (file_name[i])
	{
		j = 0;
		while (file_name[i][j])
		{
			if (file_name[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	printf("%d\n", coins);
	return (coins);
}

// validate if the map is rectangular. Returns 1 if true
int	ft_val_rect(char	**file_name)
{
	int	i;
	int	weight;

	i  = 1;
	weight = ft_strlen(file_name[0]);
	if (weight < 3)
		return (0);
	while (file_name[i])
	{
		if (ft_strlen(file_name[i]) != weight)
			return (0);
		i++;
	}
	return (1);
}
