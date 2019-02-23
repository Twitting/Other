/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:39:43 by twitting          #+#    #+#             */
/*   Updated: 2019/02/23 19:26:12 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	findsprites(t_wolf *w, int mapsize[2], int **map)
{
	int	i;
	int	j;
	int	k;
	
	k = 0;
	w->sprite = (t_sprite *)malloc(sizeof(t_sprite) * w->sprcount);
	i = 0;
	while (i < mapsize[0])
	{
		j = 0;
		while (j < mapsize[1])
		{
			if (map[i][j] >= 10)
			{
				w->sprite[k].x = j + 0.5;
				w->sprite[k].y = i + 0.5;
				w->sprite[k].texture = map[i][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

void	sortsprite(t_wolf *w)
{
	int	f;
	int i;

	f = 1;
	
	while (f == 1)
	{
		f = 0;
		i = 0;
		while (i < w->sprcount - 1)
		{
			if (w->sprite[i].spritedistance < w->sprite[i + 1].spritedistance && \
			w->sprite[i].spriteorder < w->sprite[i + 1].spriteorder)
			{
				w->sprite[i].spriteorder = w->sprite[i].spriteorder + w->sprite[i + 1].spriteorder;
				w->sprite[i + 1].spriteorder = w->sprite[i].spriteorder - w->sprite[i + 1].spriteorder;
				w->sprite[i].spriteorder -= w->sprite[i + 1].spriteorder;
				f = 1;
			}
			i++;
		}
	}
}

void	spriteplane(t_wolf *w, int j)
{
	double	inv;

	w->spritex = w->sprite[j].x - w->posx;
	w->spritey = w->sprite[j].y - w->posy;
	inv = 1.0 / (w->planex * w->diry - w->dirx * w->planey);
	w->transformx = inv * (w->diry * w->spritex - w->dirx * w->spritey);
	w->transformy = inv * (- w->planey * w->spritex + w->planex * w->spritey);
	w->spritescreenx = (int)((WWIN / 2) * (1 + w->transformx / w->transformy));
	w->spritescreenx = WWIN - 1 - w->spritescreenx;
	w->spriteheight = (int)fabs(HWIN / w->transformy);
	w->drawstarty = (HWIN / 2 - w->spriteheight / 2 < 0) ? 0 : HWIN / 2 - w->spriteheight / 2;
	w->drawendy = (HWIN / 2 + w->spriteheight / 2 >= HWIN) ? HWIN - 1 : HWIN / 2 + w->spriteheight / 2;
	w->spritewidth = (int)fabs(HWIN / w->transformy);
	w->drawstartx = (w->spritescreenx - w->spritewidth / 2 < 0) ? 0 : w->spritescreenx - w->spritewidth / 2;
	w->drawendx = (w->spritescreenx + w->spritewidth / 2 >= WWIN) ? WWIN - 1 : w->spritescreenx + w->spritewidth / 2;
}

void	spriterender(t_wolf *w, int j)
{
	int i;
	int k;

	i = w->drawstartx;
	while (i < w->drawendx)
	{
		k = w->drawstarty;
		w->texx = (int)((i - (w->spritescreenx - w->spritewidth / 2)) * TEXS / w->spritewidth);
		if (w->transformy > 0 && i > 0 && i < WWIN && w->transformy < w->zbuffer[i])
			while(k < w->drawendy)
			{
				w->texy = (k - HWIN / 2 + w->spriteheight / 2) * TEXS / w->spriteheight;
				w->color = w->teximg[w->sprite[j].texture].data[TEXS * w->texy + w->texx];
				if (w->color != 0x000000)
					w->img.data[k * WWIN + i] = w->color;
				k++;
			}
		i++;
	}
	
}

void	spritecaster(t_wolf *w)
{
	int i;
	int	j;

	i = 0;
	while(i < w->sprcount)
	{
		w->sprite[i].spritedistance = (w->posx - w->sprite[i].x) \
		* (w->posx - w->sprite[i].x) + (w->posy - w->sprite[i].y) \
		* (w->posy - w->sprite[i].y);
		w->sprite[i].spriteorder = i;
		i++;
	}
	sortsprite(w);
	i = 0;
	while (i < w->sprcount)
	{
		j = 0;
		while (j < w->sprcount)
		{
			if (w->sprite[j].spriteorder == i)
			{
				spriteplane(w, j);
				spriterender(w, j);
				break;
			}
			j++;
		}
		i++;
	}
}
