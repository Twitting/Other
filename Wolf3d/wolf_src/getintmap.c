/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:55:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/13 15:15:14 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		getwidth(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] != ' ' && str[j] != '\0')
		{
			i++;
			while (str[j] != ' ' && str[j] != '\0')
				j++;
		}
		if (str[j] == '\0')
			break ;
		j++;
	}
	return (i);
}

int		getmapsize(int *height, int *width, char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (j < getwidth(line))
			j = getwidth(line);
		free(line);
		i++;
	}
	*height = i;
	*width = j;
	close(fd);
	return (1);
}

int		**mapmalloc(int **map, int heigth, int width)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(map = (int **)malloc(sizeof(int *) * (heigth + 1))))
		return (NULL);
	while (i < heigth)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * width)))
			return (NULL);
		while (j < width)
			map[i][j++] = 0;
		i++;
	}
	map[i] = 0;
	return (map);
}

void	makemapstr(int counter, int *mapsize, int **map, char *line)
{
	int i;

	i = 0;
	while (i < mapsize[1])
	{
		map[counter][i] = ft_atoi(line);
		while (*line != ' ' && *line != '\0')
			line++;
		while (*line == ' ')
			line++;
		i++;
	}
}

int		**getintmap(char *filename)
{
	int	**map;
	int fd;
	char	*line;
	int	mapsize[2];
	int		counter;

	counter = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	map = NULL;
	getmapsize(&(mapsize[0]), &(mapsize[1]), filename);
	if (!(map = mapmalloc(map, mapsize[0], mapsize[1])))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		makemapstr(counter, mapsize, map, line);
		free(line);
		counter++;
	}
	close(fd);
	return (map);
}