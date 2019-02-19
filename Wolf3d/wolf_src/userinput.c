/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twitting <twitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 16:58:36 by twitting          #+#    #+#             */
/*   Updated: 2019/02/18 17:01:36 by twitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int keyboard(int key, void *param)
{
	if (key == KEY_ESCAPE)
	{
		((t_wolf *)param)->color = 0;
		exit(0);	
	}
	return (0);
}