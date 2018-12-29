/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 17:01:40 by twitting          #+#    #+#             */
/*   Updated: 2018/12/27 17:01:41 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_tilt_alt(int key, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (key == 83 || key == 86)
		mlx->projection = (key == 83) ? mlx->projection + 0.05 :
		mlx->projection - 0.05;
	else if (key == 87 || key == 84)
		(key == 87 ? mlx->altitude++ : mlx->altitude--);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->w_wi, mlx->w_hi);
	ft_fdf(mlx);
}

void	ft_arrows_scale(int key, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	if (key == 123 || key == 124)
		mlx->offset_x = (key == 124) ? mlx->offset_x - 50 : mlx->offset_x + 50;
	else if (key == 125 || key == 126)
		mlx->offset_y = (key == 125) ? mlx->offset_y - 50 : mlx->offset_y + 50;
	else if (key == 78 || key == 69)
		mlx->scale = (key == 69) ? mlx->scale * 2 : mlx->scale / 2;
	if (mlx->scale == 0)
		mlx->scale++;
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->w_wi, mlx->w_hi);
	ft_fdf(mlx);
}

int		ft_keyboard(int key, void *mlx)
{
	if (key == 53)
	{
		ft_freepts(((t_mlx *)mlx)->pts, -1);
		ft_freepts(((t_mlx *)mlx)->ptssmall, -1);
		free(((t_mlx *)mlx)->mlx_ptr);
		free(((t_mlx *)mlx)->win_ptr);
		free(((t_mlx *)mlx)->filename);
		free(mlx);
		exit(0);
	}
	else if (key >= 83 && key <= 87 && key != 85)
		ft_tilt_alt(key, (t_mlx *)mlx);
	else if ((key >= 123 && key <= 126) || key == 78 || key == 69)
		ft_arrows_scale(key, (t_mlx *)mlx);
	return (0);
}

void	ft_putinfo(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1000, 970,
				0xffffff, "Press ESC to exit");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 910,
				0x33dd33, "Num1 and Num4 to rotate");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 930,
				0x33dd33, "Num2 and Num5 to change altitude");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 950,
				0x33dd33, "Arrows to move screen");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 970,
				0x33dd33, "Num+ and Num- to change scale");
}
