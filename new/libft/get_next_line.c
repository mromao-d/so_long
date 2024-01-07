/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mromao-d <mromao-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:59:50 by mromao-d          #+#    #+#             */
/*   Updated: 2023/10/15 14:39:34 by mromao-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bzero_line(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
	return (s);
}

void	*ft_calloc_line(size_t nmemb, size_t size)
{
	char	*output;

	output = malloc(sizeof(char) * (nmemb * size));
	if (output == NULL)
		return (NULL);
	ft_bzero_line(output, nmemb * size);
	return (output);
}

static int	ft_lb_pos(char *str)
{
	int	i;
	int	j;
	int	hasnl;

	i = 0;
	hasnl = 0;
	j = 0;
	while (str && str[i])
	{
		if (hasnl == 1)
			str[j++] = str[i];
		if (str[i] == '\n')
			hasnl = 1;
		str[i] = 0;
		i++;
	}
	return (hasnl);
}

char	*ft_strdjoin(char *s1, char *s2)
{
	char	*output;
	int		i;
	int		keep_size;

	output = (char *)ft_calloc_line(sizeof(char), (ft_strlen_(s1)
				+ ft_strlen_(s2) + 1));
	if (!output)
		return (0);
	keep_size = ft_strlen_(s2);
	i = 0;
	while (s1 && s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2 && *s2 && *s2 != '\n' && i < (keep_size + ft_strlen_(s1)))
		output[i++] = *s2++;
	if (*s2 == '\n')
		output[i++] = '\n';
	output[i] = 0;
	free(s1);
	return (output);
}

char	*get_next_line(int fd)
{
	static char	stack[BUFFER_SIZE + 1];
	char		*line;
	int			end;

	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = ft_strdup_(stack);
	if (ft_lb_pos(stack))
		return (line);
	end = BUFFER_SIZE;
	while (end > 0)
	{
		end = read(fd, stack, BUFFER_SIZE);
		if (end == -1 || (end == 0 && line[0] == 0))
		{
			free(line);
			return (0);
		}
		line = ft_strdjoin(line, stack);
		if (ft_lb_pos(stack))
			break ;
	}
	return (line);
}

/* int	main(void)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open("foobar2.txt", O_RDONLY);
	while (i < 10)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close (fd); 
	return (0);
}
 */

/* int	main(void)
{
	int		fd;
	int		i;
	char	str[100];

	i = 0;
	fd = open("1char.txt", O_RDONLY);
	while (i < 2)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
	close (fd); 
	return (0);
} */
/* int main(void)
{
	str[100] = "asdoishdoisa as\n asd asd";
	ft_lb_pos(str);
	printf("%s , %d", str, ft_strlen((char *)ft_strlen));
	return (0);
} */
/* int	main(void)
{
	printf("%s", ft_strdjoin("grande ", "pota"));
	return (0);
}
 */