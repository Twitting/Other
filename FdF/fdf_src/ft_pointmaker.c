/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointmaker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:41:14 by twitting          #+#    #+#             */
/*   Updated: 2018/12/23 20:32:34 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**arrmaker(char **str, int strnum, int wrdcnt)
{
	t_point	**pnt;
	int		i;

	i = -1;
	if (!(pnt = (t_point **)malloc(wrdcnt * sizeof(t_point *))))
		return (NULL);
	while (str[++i])
	{
		if (!(pnt[i] = (t_point *)malloc(sizeof(t_point))))
		{
			ft_freepnt(pnt, i);
			return (NULL);
		}
		pnt[i]->y = strnum;
		pnt[i]->x = i;
		pnt[i]->z = ft_atoi(str[i]);
	}
	pnt[i] = 0;
	return (pnt);
}

int		ft_wrdcnt(char const *s)
{
	int		i;
	int		j;
	char	c;

	c = ' ';
	i = 0;
	j = 0;
	while (s[j] == c)
		j++;
	while (s[j] != '\0')
	{
		j++;
		while (s[j] == c)
		{
			j++;
			if (s[j] != c && s[j] != '\0')
				i++;
		}
	}
	return (i + 2);
}

int		ft_nlcnt(const char *str)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		i++;
	}
	close(fd);
	return (i + 1);
}

t_point	***ft_pointmaker(char *filename)
{
	char	*line;
	int		strnum;
	t_point	***pts;
	int		fd;

	strnum = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if (!(pts = (t_point ***)malloc(ft_nlcnt(filename) * sizeof(t_point *))))
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (!(pts[strnum] = arrmaker(ft_strsplit(line, ' '),
						strnum, ft_wrdcnt(line))))
		{
			ft_freepts(pts, strnum);
			return (NULL);
		}
		free(line);
		strnum++;
	}
	pts[strnum] = 0;
	close(fd);
	return (pts);
}
