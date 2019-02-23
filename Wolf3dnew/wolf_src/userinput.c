/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:58:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/23 18:19:35 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rotation(t_wolf *w)
{
	double	tempx;
	double	temppl;

	if (w->righttoggler == 1 && w->lefttoggler == 0)
	{
		tempx = w->dirx;
		w->dirx = tempx * cos(3 * M_PI / 180) - w->diry * sin(3 * M_PI / 180);
		w->diry = tempx * sin(3 * M_PI / 180) + w->diry * cos(3 * M_PI / 180);
		temppl = w->planex;
		w->planex = temppl * cos(3 * M_PI / 180) - w->planey * sin(3 * M_PI / 180);
		w->planey = temppl * sin(3 * M_PI / 180) + w->planey * cos(3 * M_PI / 180);
		w->skyangle += w->skyangle == 1920 ? -1904 : 16;
	}
	if (w->lefttoggler == 1 && w->righttoggler == 0)
	{
		tempx = w->dirx;
		w->dirx = tempx * cos(3 * M_PI / 180) + w->diry * sin(3 * M_PI / 180);
		w->diry = - tempx * sin(3 * M_PI / 180) + w->diry * cos(3 * M_PI / 180);
		temppl = w->planex;
		w->planex = temppl * cos(3 * M_PI / 180) + w->planey * sin(3 * M_PI / 180);
		w->planey = - temppl * sin(3 * M_PI / 180) + w->planey * cos(3 * M_PI / 180);
		w->skyangle -= w->skyangle == 0 ? -1904 : 16;
	}
}

void	moving(t_wolf *w)
{
	if (w->uptoggler == 1 && w->downtoggler == 0)
	{
		if (w->map[(int)w->posy][(int)(w->posx + w->dirx * 0.3)] == 0)
			w->posx += w->dirx * 0.1;
		if (w->map[(int)(w->posy + w->diry * 0.3)][(int)w->posx] == 0)
			w->posy += w->diry *  0.1;
	}
	if (w->downtoggler == 1 && w->uptoggler == 0)
	{
		if (w->map[(int)w->posy][(int)(w->posx - w->dirx * 0.3)] == 0)
			w->posx -= w->dirx * 0.1;
		if (w->map[(int)(w->posy - w->diry * 0.3)][(int)w->posx] == 0)
			w->posy -= w->diry *  0.1;
	}
	rotation(w);
}

int		crossclose(void *param)
{
	(void)param;
	system("killall afplay");
	exit(0);
	return (0);
}

int		key_press(int key, t_wolf *w)
{
	if (key == KEY_UP)
		if (w->uptoggler == 0)
			w->uptoggler = 1;
	if (key == KEY_DOWN)
		if (w->downtoggler == 0)
			w->downtoggler = 1;
	if (key == KEY_LEFT)
		if (w->lefttoggler == 0)
			w->lefttoggler = 1;
	if (key == KEY_RIGHT)
		if (w->righttoggler == 0)
			w->righttoggler = 1;
	return (0);
}

int		key_release(int key, t_wolf *w)
{
	if (key == KEY_UP)
		w->uptoggler = 0;
	if (key == KEY_DOWN)
		w->downtoggler = 0;
	if (key == KEY_LEFT)
		w->lefttoggler = 0;
	if (key == KEY_RIGHT)
		w->righttoggler = 0;
	if (key == KEY_ESCAPE)
	{
		system("killall afplay");
		exit(0);
	}
	return (0);
}