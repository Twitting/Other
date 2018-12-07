/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:41:18 by twitting          #+#    #+#             */
/*   Updated: 2018/11/29 19:09:38 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ftt_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ftt_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ftt_putchar_fd(s[i], fd);
		i++;
	}
}

void		ft_putendl_fd(char const *s, int fd)
{
	if (s == NULL)
		return ;
	ftt_putstr_fd(s, fd);
	ftt_putchar_fd('\n', fd);
}
