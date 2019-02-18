/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:55:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/18 17:01:36 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error(int errnum, t_wolf *wolf)
{
	if (errnum == 1)
		write(1, "Usage: ./wolf3d [map name]\n", 27);
	if (errnum == 2)
		write(2, "Memory allocation is failed, aborting...\n", 41);
	if (errnum == 3 && wolf)
	{
		write(2, "MinilibX initialization is failed, aborting...\n", 41);
		if (wolf->img.img_ptr != NULL)
			free(wolf->img.img_ptr);
		if (wolf->win_ptr != NULL)
			free(wolf->win_ptr);
		if (wolf->mlx_ptr != NULL)
			free(wolf->mlx_ptr);
		free(wolf);
	}
	if (errnum == 4)
		write(2, "POSIX Thread error, aborting...\n", 32);
	exit(errnum);
}

void    wininit(t_wolf *wolf)
{
	wolf->mlx_ptr = mlx_init();
	wolf->win_ptr = mlx_new_window(wolf->mlx_ptr, WWIN, HWIN, "Wolfenstein 3D");
	wolf->img.img_ptr = mlx_new_image(wolf->mlx_ptr, WWIN, HWIN);
	wolf->img.data = (int *)mlx_get_data_addr(wolf->img.img_ptr, &wolf->img.bpp, \
	&wolf->img.size_l, &wolf->img.endian);
}

int		main(int argc, char **argv)
{
	t_wolf wolf;

	if (argc == 2)
	{
		if (!(wolf.map = getintmap(argv[1])))
			return (1);
		wininit(&wolf);
		caster_init(&wolf);
		raycaster(&wolf);
	}
	else
		ft_error(1, NULL);
	mlx_key_hook(wolf.win_ptr, keyboard, &wolf);
	mlx_loop(wolf.mlx_ptr);
	return (0);
}
