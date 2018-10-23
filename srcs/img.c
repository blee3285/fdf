/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:22:25 by blee              #+#    #+#             */
/*   Updated: 2018/10/22 19:13:07 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_img(t_data *data)
{
	int		width;
	int		height;

	width = 1080;
	height = 720;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, width, height, "fdf");
}

void	pxl_to_img(t_data *data, t_pxl *pxl)
{
	char	*addr;
	int 	bbp;
	int		lsize;
	int		end;

	addr = mlx_get_data_addr(data->img, &bbp, &lsize, &end);
	if (end == 0)
	{
		addr[pxl->y_win * lsize + pxl->y_win * (bbp / 8)] = 0xFF;
		addr[pxl->y_win * lsize + pxl->y_win * (bbp / 8) + 1] = 0xFF;
		addr[pxl->y_win * lsize + pxl->y_win * (bbp / 8) + 2] = 0xFF;
		addr[pxl->y_win * lsize + pxl->y_win * (bbp / 8) + 3] = 0x00;
	}
}

void	draw_img(t_data *data)
{
	int		x;
	int		y;

	data->img = mlx_new_image(data->mlx, 1080, 720);
	x = 0;
	y = 0;
	while (y < data->y_size)
	{
		x = 0;
		while (x < data->x_size)
		{
			x++;
		}
		y++;
	}
}
