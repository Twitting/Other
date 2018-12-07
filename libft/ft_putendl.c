/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:48:23 by twitting          #+#    #+#             */
/*   Updated: 2018/11/29 19:08:47 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ftt_putchar(char c)
{
	write(1, &c, 1);
}

static void	ftt_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ftt_putchar(s[i++]);
	}
}

void		ft_putendl(char const *s)
{
	if (s == NULL)
		return ;
	ftt_putstr(s);
	ftt_putchar('\n');
}
