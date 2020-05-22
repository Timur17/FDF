/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:43:37 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/06 20:55:56 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 1500
# define WIN_HEIGHT 1000
# define DEFAULT_SCALE 0.5
# define DEFAULT 0XFFFFFF
# define YELLOW 0XFFF000
# define RED 0XFF0000
# define GREEN 0X00FF00
# define PLUS 24
# define CHANGE_COLOUR 8
# define MINUS 27
# define ESC 53
# define KEI_I 34
# define KEI_P 35
# define RIGHT 123
# define LEFT 124
# define UP 126
# define DOWN 125
# define PI_32 M_PI_4 / 8

typedef struct			s_mlx_params
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
	int			size_line;
	int			endian;
	int			bits_per_pixel;
}						t_mlx_params;

typedef struct			s_point
{
	int			x;
	int			y;
	int			z;
	int			colour;
}						t_point;

typedef struct			s_map
{
	t_point		*inp_coords;
	t_point		offset;
	t_point		*test;
	int			width;
	int			height;
	int			colour;
	int			scale;
	int			isometric;
	double		angle_x;
	double		angle_y;
	double		angle_z;
}						t_map;

typedef struct			s_fdf
{
	t_map			*map;
	t_mlx_params	mlx;
	t_point			start;
	t_point			end;
}						t_fdf;

typedef struct			s_add
{
	int				max;
	int				min;
	int				i;
	int				size;
}						t_add;

void					readmap(t_map *map, int fd);
void					ft_error(char *str);
void					parsecoords(t_map *map, char *line, t_point **coords);
void					full_coords(char *line,
		int *i, t_point **coords, t_map *map);
int						parsecolour(char *str, int *i);
void					check_height_width(int width, int height);
t_point					*transformcoords(t_point *coords,
		int height, int width);
void					ft_mlx(t_map *map, char *name);
void					start_params(t_mlx_params *mlx, t_map *map, char *name);
void					fill_mlx_param(t_mlx_params *mlx, char *name);
int						scale_map(int width, int height);
t_point					get_offset();
void					draw_line(t_mlx_params *mlx,
		t_point start, t_point end);
t_point					change_coords(int x, int y, t_map *map);
int						get_colour(t_point current, t_point start,
		t_point end, t_point delta);
int						deel_key(int key, t_fdf *fdf);
void					isometric(int *x, int *y, int z);
void					draw_map(t_mlx_params *mlx, t_map *map);
int						deel_mouse(int key, int x, int y, t_fdf *fdf);
void					rotation_x(int *y, int *z, double angle_x);
void					rotation_y(int *x, int *z, double angle_y);
void					rotation_z(int *x, int *y, double angle_z);
void					angle_default(t_map *map, double x, double y, double z);
void					put_pixel(t_mlx_params *mlx, int x, int y, int colour);
void					bzero_line(t_point *start, t_point *end);
void					print_description(t_mlx_params *mlx);
int						ft_window_close(void);

#endif
