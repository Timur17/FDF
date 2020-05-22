/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:00:46 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/06 20:59:04 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				put_pixel(t_mlx_params *mlx, int x, int y, int colour)
{
	int				i;
	int				bytes;

	if ((x < WIN_WIDTH) && (y < WIN_HEIGHT) && (x >= 0) && (y >= 0))
	{
		bytes = mlx->bits_per_pixel / 8;
		i = bytes * (x + y * WIN_WIDTH);
		if (i >= 0 && i < (WIN_HEIGHT * WIN_WIDTH * bytes))
		{
			if (mlx->endian)
			{
				mlx->data_addr[i] = 0;
				mlx->data_addr[++i] = colour >> 16;
				mlx->data_addr[++i] = colour >> 8;
				mlx->data_addr[++i] = colour;
			}
			else
			{
				mlx->data_addr[i] = colour;
				mlx->data_addr[++i] = colour >> 8;
				mlx->data_addr[++i] = colour >> 16;
				mlx->data_addr[++i] = 0;
			}
		}
	}
}

void				draw_line(t_mlx_params *mlx, t_point start, t_point end)
{
	t_point			delta;
	t_point			sign;
	t_point			error;
	t_point			curr;

	curr = start;
	delta.x = ft_abs(end.x, start.x);
	delta.y = ft_abs(end.y, start.y);
	sign.x = (start.x < end.x) ? 1 : -1;
	sign.y = (start.y < end.y) ? 1 : -1;
	error.x = delta.x - delta.y;
	while (!(curr.x == end.x && curr.y == end.y))
	{
		put_pixel(mlx, curr.x, curr.y, get_colour(curr, start, end, delta));
		if ((error.y = error.x * 2) > -delta.y)
		{
			error.x = error.x - delta.y;
			curr.x = curr.x + sign.x;
		}
		if (error.y < delta.x)
		{
			error.x = error.x + delta.x;
			curr.y = curr.y + sign.y;
		}
	}
}

void				draw_map(t_mlx_params *mlx, t_map *map)
{
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				draw_line(mlx, change_coords(x, y, map),
						change_coords(x + 1, y, map));
			if (y < map->height - 1)
				draw_line(mlx, change_coords(x, y, map),
						change_coords(x, y + 1, map));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	print_description(mlx);
}

void				ft_mlx(t_map *map, char *name)
{
	t_mlx_params	mlx;
	t_fdf			fdf;

	start_params(&mlx, map, name);
	draw_map(&mlx, map);
	fdf.map = map;
	fdf.mlx = mlx;
	mlx_hook(mlx.win_ptr, 2, 0, deel_key, &fdf);
	mlx_hook(mlx.win_ptr, 4, 0, deel_mouse, &fdf);
	mlx_hook(mlx.win_ptr, 17, 0, ft_window_close, NULL);
	mlx_loop(mlx.mlx_ptr);
}

t_point				change_coords(int x, int y, t_map *map)
{
	t_point			point;
	int				i;

	i = y * map->width + x;
	point.x = map->inp_coords[i].x * map->scale;
	point.y = map->inp_coords[i].y * map->scale;
	point.z = map->inp_coords[i].z * map->scale;
	point.colour = map->inp_coords[i].colour;
	rotation_x(&point.y, &point.z, map->angle_x);
	rotation_y(&point.x, &point.z, map->angle_y);
	rotation_z(&point.x, &point.y, map->angle_z);
	if (map->isometric != 0)
		isometric(&point.x, &point.y, point.z);
	point.x = point.x + map->offset.x;
	point.y = point.y + map->offset.y;
	return (point);
}
