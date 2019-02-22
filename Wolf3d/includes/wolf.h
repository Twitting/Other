/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:55:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/21 17:54:24 by twitting         ###   ########.fr       */
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

# define WWIN 2400
# define HWIN 1300
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESCAPE 53
# define TEXS 64
# define SKYSIZE 1920
# define TEX0 "textures/colorstone.xpm"
# define TEX1 "textures/mossy.xpm"
# define TEX2 "textures/purplestone.xpm"
# define TEX3 "textures/redbrick.xpm"
# define TEX4 "textures/bluestone.xpm"
# define TEX5 "textures/eagle.xpm"
# define TEX6 "textures/wood.xpm"
# define TEX7 "textures/greystone.xpm"
# define SKY "textures/sky.xpm"
# define CEILING 0x333333;
# define FLOOR 0x666666;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			txtheight;
	int			txtwidth;
}				t_img;

typedef struct	s_wolf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_img		teximg[9];
	int			**map;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
	int			texnum;
	double		wallx;
	int			texx;
	double		floorxwall;
	double		floorywall;
	double		distplayer;
	double		currentdist;
	double		weight;
	double		currentfloorx;
	double		currentfloory;
	int			floortexx;
	int			floortexy;
	int			skyangle;
}				t_wolf;

void	drawfloor(t_wolf *w, int x);
int		crossclose(void *param);
void	texdraw(t_wolf *w, int x);
void	textoimg(t_wolf *w);
int		keyboard(int key, void *param);
void	caster_init(t_wolf *wolf);
int		**getintmap(char *filename);
int		raycaster(t_wolf *wolf);
int		move_keys(int key, t_wolf *wolf);

#endif