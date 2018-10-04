/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:31:24 by blee              #+#    #+#             */
/*   Updated: 2018/10/03 18:04:42 by blee             ###   ########.fr       */
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
			ft_printf("%d ", data->pxl[y][x]->y_init);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
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
	data = (t_data*)malloc(sizeof(t_data));
	data->x_size = 0;
	data->y_size = 0;
	if (ac == 2)
	{
		map_size(data, av[1]);
		ft_printf("x size: %d\n", data->x_size);
		ft_printf("y size: %d\n", data->y_size);
		read_map(data, av[1]);
		print_maparr(data);
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
	mlx_key_hook(win_ptr, &print_A, (void *)0);
	mlx_mouse_hook(win_ptr, &print_A, (void *)0);
	mlx_loop(mlx_ptr);
	*/
	return (0);
}
