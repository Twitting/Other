/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:33:17 by twitting          #+#    #+#             */
/*   Updated: 2018/12/11 19:30:12 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check(t_grid *grid, int *fig, int y, int x)
{
	int c;

	c = 0;
	while (c < 4 && y + fig[c * 2] >= 0 && y + fig[c * 2] < grid->size
			&& x + fig[1 + c * 2] >= 0 && x + fig[1 + c * 2] < grid->size
			&& grid->grid[y + fig[c * 2]][x + fig[1 + c * 2]] == '.')
		c++;
	if (c == 4)
		return (1);
	return (0);
}

void	ft_put(t_grid *grid, int *fig, int y, int x)
{
	int c;

	c = 0;
	while (c < 4)
	{
		grid->grid[y + fig[c * 2]][x + fig[1 + c * 2]] = fig[8];
		c++;
	}
}

void	ft_del(t_grid *grid, int *fig, int y, int x)
{
	int c;

	c = 0;
	while (c < 4)
	{
		grid->grid[y + fig[c * 2]][x + fig[1 + c * 2]] = '.';
		c++;
	}
}

int		ft_recur(t_grid *grid, int fig[27][9], int fignum)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (fig[fignum][8] == 0)
		return (1);
	while (y < grid->size)
	{
		while (x < grid->size)
		{
			if (ft_check(grid, fig[fignum], y, x))
			{
				ft_put(grid, fig[fignum], y, x);
				if (ft_recur(grid, fig, fignum + 1))
					return (1);
				else
					ft_del(grid, fig[fignum], y, x);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
