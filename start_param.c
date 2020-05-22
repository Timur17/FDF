/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:23:09 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/06 18:42:19 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			start_params(t_mlx_params *mlx, t_map *map, char *name)
{
	fill_mlx_param(mlx, name);
	map->scale = scale_map(map->width, map->height);
	map->offset = get_offset();
	map->colour = DEFAULT;
	map->isometric = 0;
	angle_default(map, 0, 0, 0);
}

void			angle_default(t_map *map, double x, double y, double z)
{
	map->angle_x = x;
	map->angle_y = y;
	map->angle_z = z;
}

void			fill_mlx_param(t_mlx_params *mlx, char *name)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		ft_error("mlx_init error");
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
					WIN_WIDTH, WIN_HEIGHT, name)))
		ft_error("mlx_new_window error");
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		ft_error("mlx_image error");
	if (!(mlx->data_addr = (char*)mlx_get_data_addr(mlx->img_ptr,
					&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian)))
		ft_error("mlx_get_data_addr error");
}

int				scale_map(int width, int height)
{
	int			x;
	int			y;
	int			max;

	x = DEFAULT_SCALE * WIN_WIDTH / width;
	y = DEFAULT_SCALE * WIN_HEIGHT / height;
	if (x > y)
		max = x;
	else
		max = y;
	return (max > 1 ? max : 1);
}

t_point			get_offset(void)
{
	t_point		offset;

	offset.x = WIN_WIDTH / 2;
	offset.y = WIN_HEIGHT / 2;
	return (offset);
}
