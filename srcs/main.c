/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:31:24 by blee              #+#    #+#             */
/*   Updated: 2018/12/04 17:23:32 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		print_A(int key, void *param)
{
	void	*z;

	z = param;
	ft_putnbr(key);
	ft_putchar(' ');
	if (key == 53)
		exit(0);
	return (0);
}

void	print_maparr(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->y_size)
	{
		x = 0;
		while (x < data->x_size)
		{
			resize_pxl(data, data->pxl[y][x], data->xy_mod, data->z_mod);
			ft_printf("%d %d %d  ", data->pxl[y][x]->x, data->pxl[y][x]->y, data->pxl[y][x]->z);
			rotate_pxl(data, data->pxl[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	print_maparr2(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < data->y_size)
	{
		x = 0;
		while (x < data->x_size)
		{
			ft_printf("%d ", data->pxl[y][x]->x_win);
			ft_printf("%d  ", data->pxl[y][x]->y_win);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	init_win(t_data *data)
{
	int		width;
	int		height;
	int		max;

	if (data->x_size > data->y_size)
		max = data->x_size;
	else
		max = data->y_size;
	//if (data->z_size > max)
	//	max = data->z_size;
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

t_data	*init_data()
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
		map_size(data, av[1]);
		ft_printf("x size: %d\n", data->x_size);
		ft_printf("y size: %d\n", data->y_size);
		read_map(data, av[1]);
		init_win(data);
		ft_printf("win size: %d %d\n", data->wd, data->ht);
		resize(data);
		new_img(data);
		mlx_key_hook(data->win, &keyboard, data);
		mlx_loop(data->mlx);
	}
	return (0);
}
