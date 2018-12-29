/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 15:12:37 by twitting          #+#    #+#             */
/*   Updated: 2018/12/28 13:14:23 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*ft_init(char *filename)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->altitude = 10;
	mlx->scale = -1;
	mlx->pts = NULL;
	mlx->ptssmall = NULL;
	mlx->offset_x = -1;
	mlx->offset_y = 170;
	mlx->w_hi = 1000;
	mlx->w_wi = 1200;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->w_wi, mlx->w_hi, filename);
	mlx->projection = 0.7;
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->w_wi, mlx->w_hi);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, \
					&mlx->img.size_l, &mlx->img.endian);
	if (!(mlx->filename = ft_strdup(filename)))
	{
		free(mlx->mlx_ptr);
		free(mlx->win_ptr);
		return (NULL);
	}
	return (mlx);
}

void	ft_iso(t_point ***ptssmall, t_mlx *mlx)
{
	int prev_x;
	int prev_y;
	int	i;
	int	j;

	i = 0;
	while (ptssmall[i])
	{
		j = 0;
		while (ptssmall[i][j])
		{
			prev_x = ptssmall[i][j]->x;
			prev_y = ptssmall[i][j]->y;
			mlx->pts[i][j]->x = mlx->offset_x + (mlx->scale *
				(prev_x * cos(mlx->projection) - prev_y *
				sin(mlx->projection)) * cos(0.46373398));
			mlx->pts[i][j]->y = mlx->offset_y + (mlx->scale *
				ptssmall[i][j]->z * mlx->altitude / 10 * (-1)) +
				(mlx->scale * (prev_x * sin(mlx->projection) +
				prev_y * cos(mlx->projection)) * sin(0.46373398));
			j++;
		}
		i++;
	}
}

void	ft_fdf(t_mlx *mlx)
{
	int		*hiwi;

	hiwi = NULL;
	if (!(hiwi = ft_hiwi(mlx->ptssmall)))
		ft_error(2, mlx, hiwi);
	if (mlx->scale == -1 || mlx->offset_x == -1)
	{
		mlx->scale = (hiwi[0] > hiwi[1]) ? 600 / hiwi[0] : 600 / hiwi[1];
		mlx->offset_x = 200 + hiwi[0] * 4 / 5 * mlx->scale;
	}
	ft_iso(mlx->ptssmall, mlx);
	if (ft_printlines(hiwi, mlx) == 0)
		ft_error(2, mlx, hiwi);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc >= 2 && argc <= 3)
	{
		if (!(mlx = ft_init(argv[1])))
			ft_error(2, 0, 0);
		if (argc == 3 && ft_atoi(argv[2]) != 0)
			mlx->altitude = ft_atoi(argv[2]);
		if (!(mlx->ptssmall = ft_pointmaker(argv[1])))
			ft_error(2, mlx, 0);
		if (!(mlx->pts = ft_pointmaker(argv[1])))
			ft_error(2, mlx, 0);
		ft_fdf(mlx);
		mlx_key_hook(mlx->win_ptr, ft_keyboard, (void *)mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	else
		ft_error(1, 0, 0);
	return (0);
}
