/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:53:57 by blee              #+#    #+#             */
/*   Updated: 2018/10/09 17:19:48 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	resize_xy(t_data *data, int mult)
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
			data->pxl[y][x]->x = data->pxl[y][x]->x_init * mult;
			data->pxl[y][x]->y = data->pxl[y][x]->y_init * mult;
			x++;
		}
		y++;
	}
}

void	resize_z(t_data *data, int mult)
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
			data->pxl[y][x]->z = data->pxl[y][x]->z_init * mult;
			x++;
		}
		y++;
	}
}

void	resize_all(t_data *data, int mult)
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
			data->pxl[y][x]->x = data->pxl[y][x]->x_init * mult;
			data->pxl[y][x]->y = data->pxl[y][x]->y_init * mult;
			data->pxl[y][x]->z = data->pxl[y][x]->z_init * mult;
			x++;
		}
		y++;
	}
}

void	resize_pxl(t_pxl *pxl, int xy_mod, int z_mod)
{
	pxl->x = pxl->x_init * xy_mod;
	pxl->y = pxl->y_init * xy_mod;
	pxl->z = pxl->z_init * z_mod;
}
