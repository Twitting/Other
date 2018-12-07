/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:21:15 by twitting          #+#    #+#             */
/*   Updated: 2018/11/26 12:56:34 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ftt_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ret;

	i = 0;
	j = 0;
	if (size >= ftt_strlen(dst))
		ret = ftt_strlen(dst) + ftt_strlen(src);
	else
		ret = size + ftt_strlen(src);
	while (dst[i] != '\0')
		i++;
	while (size - 1 > i && src[j] != '\0' && size != 0)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ret);
}
