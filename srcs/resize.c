/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 15:53:57 by blee              #+#    #+#             */
/*   Updated: 2018/11/07 18:12:53 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	resize(t_data *data)
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
			rotate_pxl(data, data->pxl[y][x]);
			x++;
		}
		y++;
	}
}

void	resize_pxl(t_data *data, t_pxl *pxl, int xy_mod, int z_mod)
{
	pxl->x = (pxl->x_init * xy_mod) - (((data->x_size - 1) * xy_mod) / 2);
	pxl->y = (pxl->y_init * xy_mod) - (((data->y_size - 1) * xy_mod) / 2);
	pxl->z = pxl->z_init * z_mod;
}
