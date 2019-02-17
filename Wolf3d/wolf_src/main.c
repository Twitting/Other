/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:55:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/13 15:15:14 by twitting         ###   ########.fr       */
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



int		main(int argc, char **argv)
{
	int	**map;
	int	i = 0;

	map = NULL;
	if (argc == 2)
	{
		if (!(map = getintmap(argv[1])))
			return (1);
		while (map[i] != 0)
		{
			printf("%d %d %d %d %d %d\n", map[i][0],
			map[i][1], map[i][2], map[i][3], map[i][4], map[i][5]);
			i++;
		}
	}
	else
		ft_error(1, NULL);
	if (map != NULL)
		i++;
	return (0);
}
