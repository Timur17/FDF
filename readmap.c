/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:57:19 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/06 19:31:02 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				readmap(t_map *map, int fd)
{
	char			*line;
	int				n;
	t_point			*coords;

	map->height = 0;
	coords = NULL;
	while ((n = get_next_line(fd, &line)) > 0)
	{
		parsecoords(map, line, &coords);
		check_height_width(map->width, map->height);
		ft_strdel(&line);
	}
	if (n == -1)
		ft_error("Error reading");
	if ((map->test = (t_point *)coords) == NULL)
		ft_error("File error");
	map->inp_coords = transformcoords(coords, map->height, map->width);
}

void				parsecoords(t_map *map, char *line, t_point **coords)
{
	int				i;

	i = 0;
	map->width = 0;
	while (line[i])
	{
		if (ft_space(line[i]))
		{
			++i;
			continue ;
		}
		full_coords(line, &i, coords, map);
		map->width++;
	}
	map->height++;
}

void				full_coords(char *line, int *index,
		t_point **coords, t_map *map)
{
	static int		i = 0;
	static int		size = 0;
	t_point			*copy;

	if (size <= i)
	{
		size = size + 5000000;
		if ((copy = (t_point *)malloc(sizeof(t_point) * size)) == NULL)
			ft_error("Error allocation of memory");
		copy = (t_point *)ft_memcpy((void *)copy, (void *)*coords,
				i * sizeof(t_point));
		ft_memdel((void **)coords);
		*coords = copy;
	}
	(*coords)[i].x = map->width;
	(*coords)[i].y = map->height;
	(*coords)[i].z = ft_atoi(line + (*index));
	(*coords)[i].colour = parsecolour(line, index);
	i++;
}

int					parsecolour(char *str, int *i)
{
	int				colour;
	char			*s;
	char			*base;

	base = "0123456789ABCDEF0123456789abcdef";
	colour = 0;
	if (str[*i] == '-')
		++(*i);
	while (ft_isdigit(str[*i]))
		++(*i);
	if (ft_space(str[*i]) || !str[*i])
		return (0XFFFFFF);
	if (!ft_strncmp(str + (*i), ",0x", 3) ||
			!ft_strncmp(str + (*i), ",0X", 3))
		(*i) += 2;
	else
		ft_error("Error in map");
	while ((s = ft_strchr(base, str[++(*i)])) && *s)
		colour = colour * 16 + ((s - base) % 16);
	if (!(ft_space(str[*i]) || !str[*i]))
		ft_error("Error in map");
	return (colour);
}

void				check_height_width(int width, int height)
{
	static	int		old_one;

	if (height == 1)
		old_one = width;
	else if (old_one != width)
		ft_error("Wrong width");
}
