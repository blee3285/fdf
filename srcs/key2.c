/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:35:35 by blee              #+#    #+#             */
/*   Updated: 2018/12/07 18:52:04 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colors(int key, t_data *data)
{
	if (key == 12)
		data-> red += 20;
	else if (key == 0)
		data->red -= 20;
	else if (key == 13)
		data->green += 20;
	else if (key == 1)
		data->green -= 20;
	else if (key == 14)
		data->blue += 20;
	else if (key == 2)
		data->blue -= 20;
	if (data->red < 0)
		data->red = 0;
	if (data->blue < 0)
		data->blue = 0;
	if (data->green < 0)
		data->green = 0;
	if (data->red > 255)
		data->red = 255;
	if (data->blue > 255)
		data->blue = 255;
	if (data->green > 255)
		data->green = 255;
}
