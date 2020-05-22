/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:41:37 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/06 17:11:12 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			isometric(int *x, int *y, int z)
{
	int			previous_x;
	int			previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void			rotation_x(int *y, int *z, double angle_x)
{
	int			y_copy;
	int			z_copy;

	if (angle_x == 0.0)
		return ;
	y_copy = *y;
	z_copy = *z;
	*y = y_copy * cos(angle_x) + z_copy * sin(angle_x);
	*z = -y_copy * sin(angle_x) + z_copy * cos(angle_x);
}

void			rotation_y(int *x, int *z, double angle_y)
{
	int			x_copy;
	int			z_copy;

	if (angle_y == 0.0)
		return ;
	x_copy = *x;
	z_copy = *z;
	*x = x_copy * cos(angle_y) + z_copy * sin(angle_y);
	*z = -x_copy * sin(angle_y) + z_copy * cos(angle_y);
}

void			rotation_z(int *x, int *y, double angle_z)
{
	int			x_copy;
	int			y_copy;

	if (angle_z == 0.0)
		return ;
	x_copy = *x;
	y_copy = *y;
	*x = x_copy * cos(angle_z) + y_copy * sin(angle_z);
	*y = -x_copy * sin(angle_z) + y_copy * cos(angle_z);
}
