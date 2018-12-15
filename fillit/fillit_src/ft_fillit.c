/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:45:01 by twitting          #+#    #+#             */
/*   Updated: 2018/12/11 19:41:42 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_grid	*ft_makegrid(void)
{
	t_grid	*grid;
	int		i;
	int		j;

	if (!(grid = (t_grid *)malloc(sizeof(t_grid))))
		return (NULL);
	j = 0;
	while (j < 15)
	{
		i = 0;
		while (i < 15)
		{
			grid->grid[j][i] = '.';
			i++;
		}
		j++;
	}
	return (grid);
}

int		ft_minsqrt(int a)
{
	int	sqrt;

	sqrt = 0;
	while (sqrt * sqrt < a)
		sqrt++;
	return (sqrt);
}

void	ft_fillit(int fig[27][9], int fignum)
{
	t_grid	*grid;

	if (!(grid = ft_makegrid()))
	{
		write(1, "error\n", 6);
		exit(0);
	}
	grid->size = ft_minsqrt(4 * fignum);
	while (!(ft_recur(grid, fig, 0)))
		grid->size++;
	ft_disp(grid);
	free(grid);
}

int		main(int argc, char **argv)
{
	int	i;
	int	fig[27][9];
	int	fignum;

	i = 0;
	if (argc == 2)
	{
		if (!(fignum = ft_input(fig, argv[1])))
		{
			write(1, "error\n", 6);
			return (0);
		}
		ft_fillit(fig, fignum);
	}
	else
	{
		write(1, "usage: ./fillit sample.fillit\n", 30);
	}
	return (0);
}
