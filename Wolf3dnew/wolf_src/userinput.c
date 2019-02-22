/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebednar <ebednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:58:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/21 19:20:33 by ebednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		keyboard(int key, void *param)
{
	if (key == KEY_ESCAPE)
	{
		((t_wolf *)param)->color = 0;
		system("killall afplay");
		exit(0);
	}
	return (0);
}

void	rotation(int key, t_wolf *w)
{
	double	tempx;
	double	temppl;

	if (key == KEY_RIGHT)
	{
		tempx = w->dirx;
		w->dirx = tempx * cos(6 * M_PI / 180) - w->diry * sin(6 * M_PI / 180);
		w->diry = tempx * sin(6 * M_PI / 180) + w->diry * cos(6 * M_PI / 180);
		temppl = w->planex;
		w->planex = temppl * cos(6 * M_PI / 180) - w->planey * sin(6 * M_PI / 180);
		w->planey = temppl * sin(6 * M_PI / 180) + w->planey * cos(6 * M_PI / 180);
		if (w->skyangle == 1920)
		 	w->skyangle = 0;
		w->skyangle += 32;
	}
	if (key == KEY_LEFT)
	{
		tempx = w->dirx;
		w->dirx = tempx * cos(6 * M_PI / 180) + w->diry * sin(6 * M_PI / 180);
		w->diry = - tempx * sin(6 * M_PI / 180) + w->diry * cos(6 * M_PI / 180);
		temppl = w->planex;
		w->planex = temppl * cos(6 * M_PI / 180) + w->planey * sin(6 * M_PI / 180);
		w->planey = - temppl * sin(6 * M_PI / 180) + w->planey * cos(6 * M_PI / 180);
		if (w->skyangle == 0)
			w->skyangle = 1920;
		w->skyangle -= 32;
	}
}

int		move_keys(int key, t_wolf *w)
{
	if (key == KEY_UP)
	{
		if (w->map[(int)w->posy][(int)(w->posx + w->dirx * 0.3)] == 0)
			w->posx += w->dirx * 0.2;
		if (w->map[(int)(w->posy + w->diry * 0.3)][(int)w->posx] == 0)
			w->posy += w->diry *  0.2;
	}
	if (key == KEY_DOWN)
	{
		if (w->map[(int)w->posy][(int)(w->posx - w->dirx * 0.3)] == 0)
			w->posx -= w->dirx * 0.2;
		if (w->map[(int)(w->posy - w->diry * 0.3)][(int)w->posx] == 0)
			w->posy -= w->diry *  0.2;
	}
	if (key == KEY_RIGHT || key == KEY_LEFT)
		rotation(key, w);
	return (0);
}

int		crossclose(void *param)
{
	(void)param;
	system("killall afplay");
	exit(0);
	return (0);
}
