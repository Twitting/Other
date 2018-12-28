/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freepnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 20:15:20 by twitting          #+#    #+#             */
/*   Updated: 2018/12/23 20:34:22 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freepnt(t_point **pnt, int px)
{
	int	i;

	if (pnt == NULL)
		return ;
	if (px == -1)
		px = 2147483647;
	i = 0;
	while (pnt[i] && px > 0)
	{
		free(pnt[i]);
		pnt[i] = NULL;
		i++;
		px--;
	}
	free(pnt);
	pnt = NULL;
}

void	ft_freepts(t_point ***pts, int py)
{
	int	i;

	if (pts == NULL)
		return ;
	if (py == -1)
		py = 2147483647;
	i = 0;
	while (pts[i] && py > 0)
	{
		ft_freepnt(pts[i], -1);
		i++;
		py--;
	}
	free(pts);
	pts = NULL;
}

void	ft_error(int n, t_mlx *mlx, int *hiwi)
{
	if (mlx)
	{
		ft_freepts(mlx->pts, -1);
		ft_freepts(mlx->ptssmall, -1);
		free(mlx->mlx_ptr);
		free(mlx->win_ptr);
		free(mlx->filename);
		free(mlx);
	}
	if (hiwi)
		free(hiwi);
	if (n == 1)
		write(2, "usage: ./fdf filename [altitude scale, 10 by default]\n", 54);
	else if (n == 2)
		write(2, "error\n", 6);
	exit(n);
}
