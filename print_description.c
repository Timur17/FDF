/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_description.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:04:48 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/06 19:47:27 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_description(t_mlx_params *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, DEFAULT,
			"To rotate around the x axis press keys 'UP/DOWN'");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, DEFAULT,
			"To rotate around the y axis press keys 'RIGHT/LEFT'");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, DEFAULT,
			"To rotate around the z axis press keys '0/1'");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 70, DEFAULT,
			"To change type of projection to isometric press keys 'I/P'");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 90, DEFAULT,
			"To change zoom press key '+/-' or scroll mouse");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 110, DEFAULT,
			"To make map multi-colored press key 'C'");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 130, DEFAULT,
			"To draw line put two points with the left mouse buttom");
}
