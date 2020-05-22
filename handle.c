/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 21:01:39 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/06 19:41:44 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					change_colour(t_map *map)
{
	t_add				add;

	add.max = 0;
	add.min = 0;
	add.i = -1;
	add.size = 0;
	add.size = map->width * map->height;
	while (add.size > ++add.i)
	{
		if (map->inp_coords[add.i].z > add.max)
			add.max = map->inp_coords[add.i].z;
		if (map->inp_coords[add.i].z < add.min)
			add.min = map->inp_coords[add.i].z;
	}
	add.i = -1;
	while (add.size > ++add.i)
	{
		if (map->inp_coords[add.i].z > add.max * 0.7)
			map->inp_coords[add.i].colour = RED;
		else if (map->inp_coords[add.i].z < add.max * 0.3)
			map->inp_coords[add.i].colour = GREEN;
		else
			map->inp_coords[add.i].colour = YELLOW;
	}
}

int						deel_key(int key, t_fdf *fdf)
{
	t_mlx_params		*test;

	test = &fdf->mlx;
	key == CHANGE_COLOUR ? change_colour(fdf->map) : 0;
	key == ESC ? exit(EXIT_SUCCESS) : 0;
	key == PLUS ? fdf->map->scale++ : 0;
	key == MINUS ? fdf->map->scale-- : 0;
	key == KEI_I ? fdf->map->isometric = 1 : 0;
	if (key == KEI_P)
	{
		angle_default(fdf->map, 0, 0, 0);
		fdf->map->isometric = 0;
	}
	key == DOWN ? fdf->map->angle_x += PI_32 : 0;
	key == UP ? fdf->map->angle_x -= PI_32 : 0;
	key == LEFT ? fdf->map->angle_y += PI_32 : 0;
	key == RIGHT ? fdf->map->angle_y -= PI_32 : 0;
	key == 83 ? fdf->map->angle_z += PI_32 : 0;
	key == 82 ? fdf->map->angle_z -= PI_32 : 0;
	ft_bzero(fdf->mlx.data_addr, WIN_WIDTH * WIN_HEIGHT *
			(fdf->mlx.bits_per_pixel / 8));
	draw_map(&fdf->mlx, fdf->map);
	return (0);
}

void					bzero_line(t_point *start, t_point *end)
{
	start->x = 0;
	start->y = 0;
	start->colour = DEFAULT;
	end->x = 0;
	end->y = 0;
	end->colour = DEFAULT;
}

int						ft_line(t_point *start, t_point *end, int x, int y)
{
	static	int			x1;
	static	int			y1;

	if (x1 == 0 && y1 == 0)
	{
		bzero_line(start, end);
		x1 = x;
		y1 = y;
	}
	else
	{
		start->x = x1;
		start->y = y1;
		end->x = x;
		end->y = y;
		x1 = 0;
		y1 = 0;
		return (1);
	}
	return (0);
}

int						deel_mouse(int key, int x, int y, t_fdf *fdf)
{
	t_point				start;
	t_point				end;

	if (key == 4)
		fdf->map->scale++;
	if (key == 5)
		fdf->map->scale--;
	ft_bzero(fdf->mlx.data_addr, WIN_WIDTH * WIN_HEIGHT *
			(fdf->mlx.bits_per_pixel / 8));
	if (ft_line(&start, &end, x, y))
		draw_line(&fdf->mlx, start, end);
	put_pixel(&fdf->mlx, x, y, DEFAULT);
	draw_map(&fdf->mlx, fdf->map);
	return (0);
}
