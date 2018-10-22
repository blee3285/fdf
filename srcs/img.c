/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:22:25 by blee              #+#    #+#             */
/*   Updated: 2018/10/22 01:59:24 by blee             ###   ########.fr       */
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
	data->img = mlx_new_image(data->mlx, width, height);
}

int	win_pxl(int x, int dist)
{
	float	y;
	float	z;

	y = x;
	z = dist;
	return ((y / z) * (dist * 0.75));
}

void	draw_img(t_data *data, t_pxl *pxl)
{
	
}
