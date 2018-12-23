/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:43:24 by twitting          #+#    #+#             */
/*   Updated: 2018/12/23 14:08:03 by twitting         ###   ########.fr       */
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

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

int					ft_putline(t_mlx *mlx, t_line *line);
t_point				***ft_pointmaker(char *filename);
int					ft_printlines(int *hiwi, t_point ***pts, t_mlx *mlx);
int					*ft_hiwi(t_point ***pts);

#endif
