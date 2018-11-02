/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:22:23 by blee              #+#    #+#             */
/*   Updated: 2018/11/01 18:49:28 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_slope(int x0, int y0, int x1, int y1)
{
	float	x;
	float	y;

	x = x1 - x0;
	y = y1 - y0;
	return (y / x);
}

void	small_slope(t_data *data, t_pxl *a, t_pxl *b)
{
	float	slope;
	float	temp_x;
	int		x;
	int		y;

	x = a->x_win;
	slope = get_slope(a->x_win, a->y_win, b->x_win, b->y_win);
	while (x <= b->x_win)
	{
		temp_x = x - a->x_win;
		y = round(slope * temp_x) + a->y_win;
		pxl_to_img(data, x, y);
		x++;
	}
}

void	big_slope(t_data *data, t_pxl *a, t_pxl *b)
{
	float	slope;
	float	temp_y;
	int		x;
	int		y;

	y = a->y_win;
	slope = get_slope(a->y_win, a->x_win, b->y_win, b->x_win);
	while (y <= b->y_win)
	{
		temp_y = y - a->y_win;
		x = round(slope * temp_y) + a->x_win;
		pxl_to_img(data, x, y);
		y++;
	}
}

void	di_line(t_data *data, t_pxl *a, t_pxl *b)
{
	int		i;

	i = abs(a->x_win - b->x_win) - abs(a->y_win - b->y_win);
	if (i > 0)
	{
		if (a->x_win < b->x_win)
			small_slope(data, a, b);
		else
			small_slope(data, b, a);
	}
	else
	{
		if (a->y_win < b->y_win)
			big_slope(data, a, b);
		else
			big_slope(data, b, a);
	}
}
