/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:44:25 by twitting          #+#    #+#             */
/*   Updated: 2018/12/02 12:23:10 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	*ftt_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	if (!(newlist = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newlist->next = NULL;
	if (content == NULL)
	{
		newlist->content = NULL;
		newlist->content_size = 0;
		return (newlist);
	}
	newlist->content_size = content_size;
	if (!(newlist->content = (void *)malloc(content_size)))
	{
		free(newlist);
		newlist = NULL;
		return (NULL);
	}
	ftt_memcpy(newlist->content, content, content_size);
	return (newlist);
}
