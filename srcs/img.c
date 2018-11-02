/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:22:25 by blee              #+#    #+#             */
/*   Updated: 2018/11/01 16:31:28 by blee             ###   ########.fr       */
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
