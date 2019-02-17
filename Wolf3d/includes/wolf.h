/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:55:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/13 15:15:14 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"


#include <stdio.h>/////////////////////////////////

# define WWIN 800
# define HWIN 600
# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_ESCAPE 0xff1b

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_wolf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_wolf;

int		**getintmap(char *filename);

#endif