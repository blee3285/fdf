/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:40:48 by blee              #+#    #+#             */
/*   Updated: 2018/11/14 18:24:09 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		win_pxl(int x, int dist)
{
	float	y;
	float	z;
	float	slope;

	y = x;
	z = dist;
	slope = y / z;
	//add a variable for where the "screen" will be
	return (round((slope * (900))));
}

void	rotate_pxl(t_data *data, t_pxl *pxl)
{
	float	rad;
	float	temp_a;
	float	temp_b;

	rad = (3.14159265 * data->x_deg) / 180.0;
	temp_a = (pxl->z * cos(rad)) + (pxl->y * sin(rad));
	temp_b = (pxl->y * cos(rad)) - (pxl->z * sin(rad));
	pxl->z = round(temp_a);
	pxl->y = round(temp_b);
	rad = (3.14159265 * data->y_deg) / 180.0;
	temp_a = (pxl->x * cos(rad)) + (pxl->z * sin(rad));
	temp_b = (pxl->z * cos(rad)) - (pxl->x * sin(rad));
	pxl->x = round(temp_a);
	pxl->z = round(temp_b);
	rad = (3.14159265 * data->z_deg) / 180.0;
	temp_a = (pxl->x * cos(rad)) + (pxl->y * sin(rad));
	temp_b = (pxl->y * cos(rad)) - (pxl->x * sin(rad));
	pxl->x = round(temp_a);
	pxl->y = round(temp_b);
	new_coord(data, pxl);
}

void	new_coord(t_data *data, t_pxl *pxl)
{
	pxl->x_win = win_pxl(pxl->x, 1000 - pxl->z) + (data->wd / 2);
	pxl->y_win = win_pxl(pxl->y, 1000 - pxl->z) + (data->ht / 2);
}
