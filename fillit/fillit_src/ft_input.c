/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:19:25 by twitting          #+#    #+#             */
/*   Updated: 2018/12/11 19:26:05 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_n(int y1, int x1, int y2, int x2)
{
	if (y1 == y2)
	{
		if (x1 - x2 == 1 || x1 - x2 == -1)
			return (1);
	}
	if (x1 == x2)
	{
		if (y1 - y2 == 1 || y1 - y2 == -1)
			return (1);
	}
	return (0);
}

int	ft_valid(int fig[9])
{
	int c;

	c = ft_n(fig[0], fig[1], fig[2], fig[3]) +
		ft_n(fig[0], fig[1], fig[4], fig[5]) +
		ft_n(fig[0], fig[1], fig[6], fig[7]) +
		ft_n(fig[2], fig[3], fig[0], fig[1]) +
		ft_n(fig[2], fig[3], fig[4], fig[5]) +
		ft_n(fig[2], fig[3], fig[6], fig[7]) +
		ft_n(fig[4], fig[5], fig[0], fig[1]) +
		ft_n(fig[4], fig[5], fig[2], fig[3]) +
		ft_n(fig[4], fig[5], fig[6], fig[7]) +
		ft_n(fig[6], fig[7], fig[0], fig[1]) +
		ft_n(fig[6], fig[7], fig[2], fig[3]) +
		ft_n(fig[6], fig[7], fig[4], fig[5]);
	if (c >= 6)
		return (1);
	return (0);
}

int	ft_check1(int fd)
{
	ssize_t	readed;
	char	buff[21];
	int		i;

	while ((readed = read(fd, buff, 21)) > 0)
	{
		if (readed < 20)
			return (0);
		buff[readed] = '\0';
		i = 4;
		while (i < 20)
		{
			if (buff[i] != '\n' || (readed == 21 && buff[20] != '\n'))
				return (0);
			i += 5;
		}
	}
	if (readed < 0 || buff[20] != '\0')
		return (0);
	return (1);
}

int	ft_input(int fig[27][9], char *filename)
{
	int	fd;
	int	fignum;

	fd = open(filename, O_RDONLY);
	if (!(ft_check1(fd)))
		return (0);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (!(ft_digit(fd, fig)))
		return (0);
	fignum = 0;
	while (fig[fignum][8] != 0 && fignum < 27)
	{
		if (!(ft_valid(fig[fignum])))
			return (0);
		fignum++;
	}
	return (fignum);
}
