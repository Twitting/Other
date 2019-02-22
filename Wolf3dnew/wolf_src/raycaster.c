/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:59:41 by twitting          #+#    #+#             */
/*   Updated: 2019/02/21 17:13:49 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    caster_init(t_wolf *wolf)
{
	wolf->posx = 10;
	wolf->posy = 4;
	wolf->dirx = -1;
	wolf->diry = 0;
	wolf->planex = 0;
	wolf->planey = 0.66;
	wolf->skyangle = 0;
}

void    sidecalc(t_wolf *w)
{
	if (w->raydirx < 0)
	{
		w->stepx = -1;
		w->sidedistx = (w->posx - w->mapx) * w->deltadistx;
	}
	else
	{
		w->stepx = 1;
		w->sidedistx = (w->mapx + 1.0 - w->posx) * w->deltadistx;
	}
	if (w->raydiry >= 0)
	{
		w->stepy = 1;
		w->sidedisty = (w->mapy + 1.0 - w->posy) * w->deltadisty;
	}
	else
	{
		w->stepy = -1;
		w->sidedisty = (w->posy - w->mapy) * w->deltadisty;
	}
}

void    findhit(t_wolf *w)
{
	while (w->hit == 0)
	{
		if (w->sidedistx < w->sidedisty)
		{
			w->sidedistx += w->deltadistx;
			w->mapx += w->stepx;
			if (w->raydirx < 0)
				w->side = 0;
			else
				w->side = 2;
		}
		else
		{
			w->sidedisty += w->deltadisty;
			w->mapy += w->stepy;
			if (w->raydiry < 0)
				w->side = 1;
			else
				w->side = 3;		
		}
		if (w->map[w->mapy][w->mapx] > 0)
			w->hit = 1;
	}
	if (w->side == 0 || w->side == 2)
		w->perpwalldist = (double)(w->mapx - w->posx + (1 - w->stepx) / 2.0) / w->raydirx;
	else
		w->perpwalldist = (double)(w->mapy - w->posy + (1 - w->stepy) / 2.0) / w->raydiry;
}

void    drawline(t_wolf *w, int x)
{
	x = (WWIN - 1) - x;
	w->lineheight = (int)(HWIN / w->perpwalldist);
	w->drawstart = -1 * w->lineheight / 2 + HWIN / 2;
	if (w->drawstart < 0)
		w->drawstart = 0;
	w->drawend = w->lineheight / 2 + HWIN / 2;
	if (w->drawend >= HWIN)
		w->drawend = HWIN - 1;
	texdraw(w, x);
}

int    raycaster(t_wolf *w)
{
	int     x;

	x = 0;
	while (x < WWIN)
	{
		w->color = 0x3333ff;
		w->hit = 0;
		w->camerax = 2.0 * (double)x / (double)WWIN - 1.0;
		w->raydirx = w->dirx + w->planex * w->camerax;
		w->raydiry = w->diry + w->planey * w->camerax;
		w->mapx = (int)(w->posx);
		w->mapy = (int)(w->posy);
		w->deltadistx = fabs(1 / w->raydirx);
		w->deltadisty = fabs(1 / w->raydiry);
		sidecalc(w);
		findhit(w);
		drawline(w, x);
		drawfloor(w, x);
		x++;
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img.img_ptr, 0, 0);
	return (0);
}