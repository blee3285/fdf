/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:29:11 by blee              #+#    #+#             */
/*   Updated: 2018/12/04 17:15:41 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	angles(int key, t_data *data)
{
	if (key == 2)
		data->y_deg = (data->y_deg + (10 * data->spd)) % 360;
	else if (key == 0)
		data->y_deg -= (10 * data->spd);
	else if (key == 13)
		data->x_deg = (data->x_deg + (10 * data->spd)) % 360;
	else if (key == 1)
		data->x_deg -= (10 * data->spd);
	else if (key == 14)
		data->z_deg -= (10* data->spd);
	else if (key == 12)
		data->z_deg = (data->z_deg + (10 * data->spd)) % 360;
	if (data->y_deg < 0)
		data->y_deg += 360;
	if (data->x_deg < 0)
		data->x_deg += 360;
	if (data->z_deg < 0)
		data->z_deg += 360;
}

void	size(int key, t_data *data)
{
	if (key == 125)
		data->z_mod -= 1 * data->spd;
	else if (key == 126)
		data->z_mod += 1 * data->spd;
	else if (key == 123)
		data->xy_mod -= 1 * data->spd;
	else if (key == 124)
		data->xy_mod += 1 * data->spd;
	if (data->z_mod < 0)
		data->z_mod = 0;
	if (data->xy_mod < 1)
		data->xy_mod = 1;
	if ((data->xy_mod * data->x_size) > (data->wd / 2))
		data->xy_mod -= 1 * data->spd;
	if ((data->z_mod * data->z_size) > (data->ht / 3))
		data->z_mod -= 1 * data->spd;
}

void	speed(int key, t_data *data)
{
	if (key == 18)
		data->spd = 1;
	else if (key == 19)
		data->spd = 2;
	else if (key == 20)
		data->spd = 3;
}

void	reset(t_data *data)
{
	data->x_deg = 0;
	data->y_deg = 0;
	data->z_deg = 0;
	data->spd = 1;
	data->xy_mod = (data->wd / 3) / data->x_size;
	data->z_mod = 2;
}

int		keyboard(int key, t_data *data)
{
	if (key == 53)
	{
		free_data(data);
		exit(0);
	}
	angles(key, data);
	size(key, data);
	speed(key, data);
	if (key == 15)
		reset(data);
	new_img(data);
	return (0);
}
