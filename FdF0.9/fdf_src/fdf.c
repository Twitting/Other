/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:12:37 by twitting          #+#    #+#             */
/*   Updated: 2018/12/23 20:49:34 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_mlx	*ft_init(char *filename)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->altitude = 10;
	mlx->offset_y = 170;
	mlx->filename = NULL;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1200, 1000, filename);
	mlx->projection = 0.7;
	if (!(mlx->filename = ft_strdup(filename)))
	{
		free(mlx->mlx_ptr);
		free(mlx->win_ptr);
		return (NULL);
	}
	return (mlx);
}

void	ft_iso(t_point ***pts, int scale, int offset, t_mlx *mlx)
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
						cos(mlx->projection)));
			pts[i][j]->y = mlx->offset_y +
			(scale * pts[i][j]->z * mlx->altitude / 10 * (-1))
				+ (scale * (prev_x + prev_y) * sin(mlx->projection));
			j++;
		}
		i++;
	}
}

void	ft_fdf(char *filename, t_mlx *mlx)
{
	t_point	***pts;
	int		*hiwi;
	int		scale;
	int		offset;

	hiwi = NULL;
	if (!(pts = ft_pointmaker(filename)) ||
		!(hiwi = ft_hiwi(pts)))
		ft_error(2, pts, mlx, hiwi);
	scale = (hiwi[0] > hiwi[1]) ? 600 / hiwi[0] : 600 / hiwi[1];
	offset = 100 + hiwi[0] * 4 / 5 * scale;
	ft_iso(pts, scale, offset, mlx);
	if (ft_printlines(hiwi, pts, mlx) == 0)
		ft_error(2, pts, mlx, hiwi);
}

int		ft_keyboard(int key, void *mlx)
{
	if (key == 53)
	{
		free(((t_mlx *)mlx)->mlx_ptr);
		free(((t_mlx *)mlx)->win_ptr);
		free(((t_mlx *)mlx)->filename);
		free(mlx);
		exit(0);
	}
	else if (key == 125)
	{
		mlx_clear_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr);
		((t_mlx *)mlx)->projection += 0.05;
		((t_mlx *)mlx)->offset_y = 170 + 800 *
		(cos(((t_mlx *)mlx)->projection - 0.75 + 3.1415) + 1);
		ft_fdf(((t_mlx *)mlx)->filename, mlx);
	}
	else if (key == 126)
	{
		mlx_clear_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr);
		((t_mlx *)mlx)->projection -= 0.05;
		((t_mlx *)mlx)->offset_y = 170 + 800 *
		(cos(((t_mlx *)mlx)->projection - 0.75 + 3.1415) + 1);
		ft_fdf(((t_mlx *)mlx)->filename, mlx);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc >= 2 && argc <= 3)
	{
		if (!(mlx = ft_init(argv[1])))
			ft_error(2, 0, 0, 0);
		if (argc == 3 && ft_atoi(argv[2]) != 0)
			mlx->altitude = ft_atoi(argv[2]);
		ft_fdf(mlx->filename, mlx);
		mlx_key_hook(mlx->win_ptr, ft_keyboard, (void *)mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	else
		ft_error(1, 0, 0, 0);
	return (0);
}
