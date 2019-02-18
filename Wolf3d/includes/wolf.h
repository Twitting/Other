/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:55:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/18 17:20:39 by twitting         ###   ########.fr       */
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

# define WWIN 1024
# define HWIN 768
# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_ESCAPE 0xff1b

typedef struct	s_img
{
	void  *img_ptr;
	int         *data;
	int			size_l;
	int         bpp;
	int         endian;
}				t_img;

typedef struct	s_wolf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int         **map;
	double      posx;
	double      posy;
	double      dirx;
	double      diry;
	double      planex;
	double      planey;
	double      camerax;
	double      raydirx;
	double      raydiry;
	int         mapx;
	int         mapy;
	double      sidedistx;
	double      sidedisty;
	double      deltadistx;
	double      deltadisty;
	int         stepx;
	int         stepy;
	int         hit;
	int         side;
	double      perpwalldist;
	int         lineheigth;
	int         drawstart;
	int         drawend;
	int         color;
}				t_wolf;

int keyboard(int key, void *param);
void    caster_init(t_wolf *wolf);
int		**getintmap(char *filename);
void    raycaster(t_wolf *wolf);

#endif