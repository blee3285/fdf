/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:22:52 by blee              #+#    #+#             */
/*   Updated: 2018/12/11 19:15:15 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_straight(t_pxl *a, t_pxl *b)
{
	if (a->x_win == b->x_win)
		return (1);
	else if (a->y_win == b->y_win)
		return (1);
	return (0);
}

void	connect_pxl(t_data *data, t_pxl *a, t_pxl *b)
{
	if (is_straight(a, b))
		st_line(data, a, b);
	else
		di_line(data, a, b);
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->y_size)
	{
		x = 0;
		while (x < data->x_size)
		{
			if (x < (data->x_size - 1))
				connect_pxl(data, data->pxl[y][x], data->pxl[y][x + 1]);
			if (y < (data->y_size - 1))
				connect_pxl(data, data->pxl[y][x], data->pxl[y + 1][x]);
			x++;
		}
		y++;
	}
}
