/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:22:25 by blee              #+#    #+#             */
/*   Updated: 2018/11/19 18:01:20 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pxl_to_img(t_data *data, int x, int y)
{
	char	*addr;
	int 	bbp;
	int		lsize;
	int		end;

	addr = mlx_get_data_addr(data->img, &bbp, &lsize, &end);
	if (end == 0)
	{
		addr[y * lsize + x * (bbp / 8)] = 0xFF;
		addr[y * lsize + x * (bbp / 8) + 1] = 0xFF;
		addr[y * lsize + x * (bbp / 8) + 2] = 0xFF;
		addr[y * lsize + x * (bbp / 8) + 3] = 0x0;
	}
	else if (end == 1)
	{
		addr[y * lsize + x * (bbp / 8)] = 0x0;
		addr[y * lsize + x * (bbp / 8) + 1] = 0xFF;
		addr[y * lsize + x * (bbp / 8) + 2] = 0xFF;
		addr[y * lsize + x * (bbp / 8) + 3] = 0xFF;
	}
}

void	new_img(t_data *data)
{
	resize(data);
	data->img = mlx_new_image(data->mlx, 1080, 720);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}
