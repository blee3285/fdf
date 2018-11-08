/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:29:11 by blee              #+#    #+#             */
/*   Updated: 2018/11/07 18:56:10 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	angles(int key, t_data *data)
{
	if (key == 2)
		data->y_deg = (data->y_deg + 10) % 360;
	else if (key == 0)
		data->y_deg -= 10;
	else if (key == 13)
		data->x_deg = (data->x_deg + 10) % 360;
	else if (key == 1)
		data->x_deg -= 10;
	else if (key == 14)
		data->z_deg -= 10;
	else if (key == 12)
		data->z_deg = (data->z_deg + 10) % 360;
	if (data->y_deg < 0)
		data->y_deg += 360;
	if (data->x_deg < 0)
		data->x_deg += 360;
	if (data->z_deg < 0)
		data->z_deg += 360;
}

int		keyboard(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	angles(key, data);
	new_img(data);
	ft_printf("x: %d  y: %d  z: %d\n", data->x_deg, data->y_deg, data->z_deg);
	return (0);
}
