/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:11:59 by twitting          #+#    #+#             */
/*   Updated: 2018/11/29 19:05:05 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	startwsp(char const *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int	endwsp(char const *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		j++;
		i--;
	}
	return (j);
}

static int	ftt_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (startwsp(s) == ftt_strlen(s))
	{
		if (!(str = (char *)malloc(1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = (char *)malloc(ftt_strlen(s) + 1 - endwsp(s) - startwsp(s))))
		return (NULL);
	i = startwsp(s);
	while (i < (ftt_strlen(s) - endwsp(s)))
		str[j++] = ((char *)s)[i++];
	str[j] = '\0';
	return (str);
}
