/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:22:03 by twitting          #+#    #+#             */
/*   Updated: 2018/12/01 14:59:08 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(size + 1)) || size + 1 == 0)
		return (NULL);
	while (size)
		((unsigned char *)str)[size--] = '\0';
	((unsigned char *)str)[size] = '\0';
	return (str);
}
