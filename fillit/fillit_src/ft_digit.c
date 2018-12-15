/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:26:02 by twitting          #+#    #+#             */
/*   Updated: 2018/12/15 15:58:39 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_digitalyzer(char *str, int fig[27][9], int fignum)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	y = 0;
	x = 0;
	while (x + y * 5 < 20)
	{
		if (x == 4)
		{
			x = 0;
			y++;
		}
		if (str[x + y * 5] == '#')
		{
			if (count > 7)
				return (0);
			fig[fignum][count] = y;
			fig[fignum][count + 1] = x;
			count += 2;
		}
		x++;
	}
	return (1);
}

void	ft_tostart(int fig[27][9], int fignum)
{
	while (fig[fignum][0] > 0)
	{
		fig[fignum][0]--;
		fig[fignum][2]--;
		fig[fignum][4]--;
		fig[fignum][6]--;
	}
	while (fig[fignum][1] > 0)
	{
		fig[fignum][1]--;
		fig[fignum][3]--;
		fig[fignum][5]--;
		fig[fignum][7]--;
	}
	fig[fignum][8] = fignum + 65;
}

int		ft_digit(int fd, int fig[27][9])
{
	ssize_t	readed;
	char	buff[21];
	int		fignum;
	int		i;

	fignum = 0;
	while (fignum < 27)
		fig[fignum++][8] = 0;
	fignum = 0;
	while ((readed = read(fd, buff, 21)) > 0)
	{
		i = -1;
		while (++i < 20)
		{
			if (i != 4 && i != 9 && i != 14 && i != 19 &&
					buff[i] != '.' && buff[i] != '#')
				return (0);
		}
		if (!(ft_digitalyzer(buff, fig, fignum)))
			return (0);
		ft_tostart(fig, fignum);
		fignum++;
	}
	return (1);
}
