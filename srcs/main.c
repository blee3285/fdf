/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:31:24 by blee              #+#    #+#             */
/*   Updated: 2018/11/07 18:56:59 by blee             ###   ########.fr       */
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

	width = 1080;
	height = 720;
	data->win = mlx_new_window(data->mlx, width, height, "fdf");
}

t_data	*init_data()
{
	t_data		*data;

	data = (t_data*)malloc(sizeof(t_data));
	data->x_size = 0;
	data->y_size = 0;
	data->xy_mod = 30;
	data->z_mod = 10;
	data->dist = 500;
	data->x_deg = 0;
	data->y_deg = 0;
	data->z_deg = 0;
	data->mlx = mlx_init();
	return (data);
}

int		main(int ac, char **av)
{
	//void		*mlx_ptr;
	//void		*win_ptr;
	//int		color;
	//void		*img;
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
		resize(data);
		init_win(data);
		new_img(data);
		mlx_key_hook(data->win, &keyboard, data);
		mlx_loop(data->mlx);
	}
	/*
	color = 0;
	color += 255;
	color = color << 8;
	color += 255;
	color = color << 8;
	color += 255;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "test");
	mlx_pixel_put(mlx_ptr, win_ptr, 10, 10, color);
	//img = mlx_new_image(mlx_ptr, 500, 500);
	//mlx_put_image_to_window(mlx_ptr, win_ptr, img, 0, 0);
	*/
	return (0);
}
