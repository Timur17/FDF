/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:40:37 by wtorwold          #+#    #+#             */
/*   Updated: 2019/12/06 21:58:48 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_window_close(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	char	*name;
	int		fd;
	t_map	map;

	if (ac != 2)
		ft_error("Usage : ./fdf <filename>\n");
	if ((name = ft_strrchr(av[1], '/')) == NULL)
		name = av[1];
	else
		name++;
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("Open error");
	readmap(&map, fd);
	if (close(fd) < 0)
		ft_error("Close error");
	ft_mlx(&map, name);
	exit(EXIT_SUCCESS);
}
