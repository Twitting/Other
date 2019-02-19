/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:55:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/19 13:50:47 by twitting         ###   ########.fr       */
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
# define TEXS 64
# define TEX0 "textures/eagle.xpm"
# define TEX1 "textures/redbrick.xpm"
# define TEX2 "textures/purplestone.xpm"
# define TEX3 "textures/greystone.xpm"
# define TEX4 "textures/bluestone.xpm"
# define TEX5 "textures/mossy.xpm"
# define TEX6 "textures/wood.xpm"
# define TEX7 "textures/colorstone.xpm"

typedef struct	s_img
{
	void		*img_ptr;
	int         *data;
	int			size_l;
	int         bpp;
	int         endian;
}				t_img;

typedef struct	s_txt
{
	void		*txtimg_ptr;
	int			*txtheight;
	int			*txtwidth;
}				t_txt;

typedef struct	s_wolf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_txt		teximg[8];
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
	int			texnum;
	double		wallx;
	int			texx;
}				t_wolf;

//void	textoimg(t_wolf *w);
//void	texgen(t_wolf *w);
int keyboard(int key, void *param);
void    caster_init(t_wolf *wolf);
int		**getintmap(char *filename);
void    raycaster(t_wolf *wolf);

#endif