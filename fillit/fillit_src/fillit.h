/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:40:15 by twitting          #+#    #+#             */
/*   Updated: 2018/12/11 19:30:52 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_grid
{
	char			grid[15][15];
	int				size;
}					t_grid;

int					ft_disp(t_grid *grid);
int					ft_digit(int fd, int fig[27][9]);
int					ft_input(int fig[27][9], char *filename);
int					ft_recur(t_grid *grid, int fig[27][9], int fignum);

#endif
