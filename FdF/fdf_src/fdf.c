/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:12:37 by twitting          #+#    #+#             */
/*   Updated: 2018/12/23 14:56:18 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_mlx	*ft_init(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1200, 1000, "FdF");
	return (mlx);
}

void	ft_iso(t_point ***pts, int scale, int offset)
{
	int prev_x;
	int prev_y;
	int	i;
	int	j;

	i = 0;
	while (pts[i])
	{
		j = 0;
		while (pts[i][j])
		{
			prev_x = pts[i][j]->x;
			prev_y = pts[i][j]->y;
			pts[i][j]->x = offset + (scale * ((prev_x - prev_y) *
						cos(0.46373398)));
			pts[i][j]->y = 200 + (scale * ((pts[i][j]->z) / 10 *
						(-1) + (prev_x + prev_y) * sin(0.46373398)));
			j++;
		}
		i++;
	}
}

void	ft_error(int n)
{
	if (n == 1)
		write(2, "usage: ./FdF filename\n", 22);
	else if (n == 2)
		write(2, "error\n", 6);
	exit(n);
}

int		ft_keyboard(int key, void *param)
{
	param = NULL;
	if (key == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_point	***pts;
	int		*hiwi;
	int		scale;
	int		offset;

	mlx = NULL;
	hiwi = NULL;
	if (argc == 2)
	{
		if (!(pts = ft_pointmaker(argv[1])) ||
				!(mlx = ft_init()) ||
				!(hiwi = ft_hiwi(pts)))
			ft_error(2);
		scale = (hiwi[0] > hiwi[1]) ? 600 / hiwi[0] : 600 / hiwi[1];
		offset = 100 + hiwi[0] * 4 / 5 * scale;
		ft_iso(pts, scale, offset);
		if (ft_printlines(hiwi, pts, mlx) == 0)
			ft_error(2);
		mlx_key_hook(mlx->win_ptr, ft_keyboard, (void *)0);
		mlx_loop(mlx->mlx_ptr);
	}
	else
		ft_error(1);
	return (0);
}
