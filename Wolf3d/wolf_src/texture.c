/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:22:16 by twitting          #+#    #+#             */
/*   Updated: 2019/02/19 13:39:09 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	textoimg(t_wolf *w)
{
	w->teximg[0].txtimg_ptr = mlx_xpm_file_to_image(w->mlx_ptr,TEX0, \
	w->teximg[0].txtwidth, w->teximg[0].txtheight);
	w->teximg[1].txtimg_ptr = mlx_xpm_file_to_image(w->mlx_ptr,TEX1, \
	w->teximg[1].txtwidth, w->teximg[1].txtheight);
	w->teximg[2].txtimg_ptr = mlx_xpm_file_to_image(w->mlx_ptr,TEX2, \
	w->teximg[2].txtwidth, w->teximg[2].txtheight);
	w->teximg[3].txtimg_ptr = mlx_xpm_file_to_image(w->mlx_ptr,TEX3, \
	w->teximg[3].txtwidth, w->teximg[3].txtheight);
	w->teximg[4].txtimg_ptr = mlx_xpm_file_to_image(w->mlx_ptr,TEX4, \
	w->teximg[4].txtwidth, w->teximg[4].txtheight);
	w->teximg[5].txtimg_ptr = mlx_xpm_file_to_image(w->mlx_ptr,TEX5, \
	w->teximg[5].txtwidth, w->teximg[5].txtheight);
	w->teximg[6].txtimg_ptr = mlx_xpm_file_to_image(w->mlx_ptr,TEX6, \
	w->teximg[6].txtwidth, w->teximg[6].txtheight);
	w->teximg[7].txtimg_ptr = mlx_xpm_file_to_image(w->mlx_ptr,TEX7, \
	w->teximg[7].txtwidth, w->teximg[7].txtheight);
}
/*
void	texgen(t_wolf *w)
{
	textoimg(w);
}*/