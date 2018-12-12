/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:31:24 by blee              #+#    #+#             */
/*   Updated: 2018/12/11 19:14:10 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_win(t_data *data)
{
	int		width;
	int		height;
	int		max;

	if (data->x_size > data->y_size)
		max = data->x_size;
	else
		max = data->y_size;
	width = max * 10;
	if (width > 1920)
		width = 1920;
	if (width < 960)
		width = 960;
	height = (width * 9) / 16;
	data->wd = width;
	data->ht = height;
	data->xy_mod = (width / 3) / max;
	if (data->xy_mod == 0)
		data->xy_mod = 1;
	data->win = mlx_new_window(data->mlx, width, height, "fdf");
}

t_data	*init_data(void)
{
	t_data		*data;

	data = (t_data*)malloc(sizeof(t_data));
	data->x_size = 0;
	data->y_size = 0;
	data->z_size = 0;
	data->xy_mod = 0;
	data->z_mod = 2;
	data->x_deg = 0;
	data->y_deg = 0;
	data->z_deg = 0;
	data->mlx = mlx_init();
	data->spd = 1;
	data->red = 255;
	data->green = 255;
	data->blue = 255;
	data->p = 1;
	data->mode = 1;
	return (data);
}

int		main(int ac, char **av)
{
	int			i;
	t_data		*data;

	i = 0;
	data = init_data();
	if (ac == 2)
	{
		error(map_size(data, av[1]), data);
		error(read_map(data, av[1]), data);
		init_win(data);
		resize(data);
		controls();
		new_img(data);
		mlx_key_hook(data->win, &keyboard, data);
		mlx_loop(data->mlx);
	}
	return (0);
}
