/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:43:24 by twitting          #+#    #+#             */
/*   Updated: 2018/12/29 16:08:24 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

typedef struct		s_line
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				color;
}					t_line;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	float			projection;
	char			*filename;
	int				altitude;
	int				offset_y;
	int				scale;
	int				offset_x;
	int				w_hi;
	int				w_wi;
	t_point			***ptssmall;
	t_point			***pts;
	t_img			img;
}					t_mlx;

void				ft_fdf(t_mlx *mlx);
int					ft_keyboard(int key, void *mlx);
void				ft_error(int n, t_mlx *mlx, int *hiwi);
void				ft_freepnt(t_point **pnt, int px);
void				ft_freepts(t_point ***pts, int py);
int					ft_putline(t_mlx *mlx, t_line *line);
t_point				***ft_pointmaker(char *filename);
int					ft_printlines(int *hiwi, t_mlx *mlx);
int					*ft_hiwi(t_point ***pts);
void				ft_putinfo(t_mlx *mlx);

#endif
