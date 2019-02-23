/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:55:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/23 18:20:45 by twitting         ###   ########.fr       */
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
	wolf->lefttoggler = 0;
	wolf->righttoggler = 0;
	wolf->uptoggler = 0;
	wolf->downtoggler = 0;
	wolf->fps = 0;
	wolf->timer = 0;
	textoimg(wolf);
	system("afplay music.mp3 &");
}

int		main(int argc, char **argv)
{
	t_wolf wolf;

	if (argc == 2)
	{
		wolf.sprcount = 0;
		if (!(wolf.map = getintmap(argv[1], &wolf)))
			return (1);
		wininit(&wolf);
		caster_init(&wolf);	
	}
	else
		ft_error(1, NULL);
	mlx_loop_hook(wolf.mlx_ptr, raycaster, &wolf);
	mlx_hook(wolf.win_ptr, 2, 1L << 0, key_press, &wolf);
	mlx_hook(wolf.win_ptr, 3, 1L << 0, key_release, &wolf);
	//mlx_hook(wolf.win_ptr, 6, 1L << 6, mouse_move, &wolf);
	mlx_hook(wolf.win_ptr, 17, 1L << 17, crossclose, &wolf);
	mlx_loop(wolf.mlx_ptr);
	return (0);
}
