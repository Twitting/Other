/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:45:43 by twitting          #+#    #+#             */
/*   Updated: 2018/12/28 15:12:03 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putlinelow(t_mlx *mlx, t_line *l)
{
	int		x;
	int		yi;
	int		dy;
	int		f;

	dy = l->y1 - l->y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	f = 2 * dy - (l->x1 - l->x0);
	x = l->x0 - 1;
	while (++x <= l->x1)
	{
		if (x >= 0 && x < mlx->w_wi && l->y0 >= 0 && l->y0 < mlx->w_hi)
			mlx->img.data[l->y0 * mlx->w_wi + x] = l->color;
		if (f > 0)
		{
			l->y0 = l->y0 + yi;
			f = f - 2 * (l->x1 - l->x0);
		}
		f = f + 2 * dy;
	}
}

void	ft_putlinehigh(t_mlx *mlx, t_line *l)
{
	int		y;
	int		xi;
	int		dx;
	int		f;

	dx = l->x1 - l->x0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	f = 2 * dx - (l->y1 - l->y0);
	y = l->y0 - 1;
	while (++y <= l->y1)
	{
		if (l->x0 >= 0 && l->x0 < mlx->w_wi && y >= 0 && y < mlx->w_hi)
			mlx->img.data[y * mlx->w_wi + l->x0] = l->color;
		if (f > 0)
		{
			l->x0 = l->x0 + xi;
			f = f - 2 * (l->y1 - l->y0);
		}
		f = f + 2 * dx;
	}
}

t_line	*ft_revln(t_line *l)
{
	int	tmp;

	tmp = l->x1;
	l->x1 = l->x0;
	l->x0 = tmp;
	tmp = l->y1;
	l->y1 = l->y0;
	l->y0 = tmp;
	return (l);
}

int		ft_putline(t_mlx *mlx, t_line *l)
{
	if (mlx == NULL || l == NULL)
		return (0);
	if ((int)fabs((double)(l->y1 - l->y0)) < (int)fabs((double)(l->x1 - l->x0)))
	{
		if (l->x0 > l->x1)
			ft_putlinelow(mlx, ft_revln(l));
		else
			ft_putlinelow(mlx, l);
	}
	else
	{
		if (l->y0 > l->y1)
			ft_putlinehigh(mlx, ft_revln(l));
		else
			ft_putlinehigh(mlx, l);
	}
	return (1);
}
