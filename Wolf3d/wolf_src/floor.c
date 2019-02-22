/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:16:05 by twitting          #+#    #+#             */
/*   Updated: 2019/02/21 15:49:34 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	floortexcoords(t_wolf *w)
{
	if (w->side == 2)
	{
		w->floorxwall = w->mapx;
		w->floorywall = w->mapy + w->wallx;
	}
	else if (w->side == 0)
	{
		w->floorxwall = w->mapx + 1.0;
		w->floorywall = w->mapy + w->wallx;
	}
	else if (w->side == 3)
	{
		w->floorxwall = w->mapx + w->wallx;
		w->floorywall = w->mapy;
	}
	else if (w->side == 1)
	{
		w->floorxwall = w->mapx + w->wallx;
		w->floorywall = w->mapy + 1.0;
	}
}

void	drawfloor(t_wolf *w, int x)
{
	int y;

	y = w->drawend;
	floortexcoords(w);
	w->distplayer = 0.0;
	while (y < HWIN)
	{
		w->currentdist = HWIN / (2.0 * y - HWIN);
		w->weight = (w->currentdist - w->distplayer) / (w->perpwalldist - w->distplayer);
		w->currentfloorx = w->weight * w->floorxwall + (1.0 - w->weight) * w->posx;
		w->currentfloory = w->weight * w->floorywall + (1.0 - w->weight) * w->posy;
		w->floortexx = (int)(w->currentfloorx * TEXS) % TEXS;
		w->floortexy = (int)(w->currentfloory * TEXS) % TEXS;
		w->color = w->teximg[6].data[TEXS * w->floortexy + w->floortexx];
		w->img.data[y * WWIN + x] = w->color;
		y++;
	}
}