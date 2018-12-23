/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:31:25 by twitting          #+#    #+#             */
/*   Updated: 2018/12/23 14:55:33 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		*ft_hiwi(t_point ***pts)
{
	int		*hiwi;
	int		c;

	c = 0;
	if (pts == NULL || !(hiwi = (int *)malloc(sizeof(int) * 2)))
		return (NULL);
	while ((*pts)[c])
		c++;
	hiwi[1] = c;
	c = 0;
	while (pts[c])
		c++;
	hiwi[0] = c;
	return (hiwi);
}

t_line	*ft_makeline(t_point *p1, t_point *p2)
{
	t_line	*line;

	if (p1 == NULL || p2 == NULL ||
			!(line = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	line->x0 = p1->x;
	line->y0 = p1->y;
	line->x1 = p2->x;
	line->y1 = p2->y;
	if ((p1->z >= 0 && p1->z <= 5) || (p2->z >= 0 && p2->z <= 5))
		line->color = 0x0022ff22;
	else if ((p1->z >= 6 && p1->z <= 30) || (p2->z >= 6 && p2->z <= 30))
		line->color = 0x00964b00;
	else
		line->color = 0x00ffffff;
	return (line);
}

int		ft_horizlines(int *hiwi, t_point ***pts, t_mlx *mlx)
{
	int		coln;
	int		strn;
	t_line	*line;

	if (hiwi == NULL || pts == NULL || mlx == NULL)
		return (0);
	strn = 0;
	while (strn < hiwi[0])
	{
		coln = 0;
		while (coln + 1 < hiwi[1])
		{
			if (!(line = ft_makeline(pts[strn][coln], pts[strn][coln + 1])))
				return (0);
			if (ft_putline(mlx, line) == 0)
				return (0);
			free(line);
			coln++;
		}
		strn++;
	}
	return (1);
}

int		ft_vertilines(int *hiwi, t_point ***pts, t_mlx *mlx)
{
	int		coln;
	int		strn;
	t_line	*line;

	if (hiwi == NULL || pts == NULL || mlx == NULL)
		return (0);
	strn = 0;
	while (strn + 1 < hiwi[0])
	{
		coln = 0;
		while (coln < hiwi[1])
		{
			if (!(line = ft_makeline(pts[strn][coln], pts[strn + 1][coln])))
				return (0);
			if (ft_putline(mlx, line) == 0)
				return (0);
			free(line);
			coln++;
		}
		strn++;
	}
	return (1);
}

int		ft_printlines(int *hiwi, t_point ***pts, t_mlx *mlx)
{
	if (hiwi == NULL || pts == NULL || mlx == NULL)
		return (0);
	if (!(ft_vertilines(hiwi, pts, mlx)) || !(ft_horizlines(hiwi, pts, mlx)))
		return (0);
	return (1);
}
