/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformcoords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:03:25 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/06 18:23:06 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point			*transformcoords(t_point *coords, int height, int width)
{
	int			i;
	int			size;
	t_point		offset_map;

	if (coords == NULL)
		return (NULL);
	i = -1;
	size = height * width;
	offset_map.x = width / 2;
	offset_map.y = height / 2;
	while (++i < size)
	{
		coords[i].x = coords[i].x - offset_map.x;
		coords[i].y = coords[i].y - offset_map.y;
	}
	return (coords);
}
