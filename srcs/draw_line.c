/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:59:20 by blee              #+#    #+#             */
/*   Updated: 2018/11/01 18:47:31 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	up_down(t_data *data, t_pxl *a, t_pxl *b)
{
	int		y;

	y = a->y_win;
	if (a->y_win > b->y_win)
	{
		while (y != b->y_win)
		{
			pxl_to_img(data, a->x_win, y);
			y--;
		}
	}
	else if (a->y_win < b->y_win)
	{
		while (y != b->y_win)
		{
			pxl_to_img(data, a->x_win, y);
			y++;
		}
	}
}

void	left_right(t_data *data, t_pxl *a, t_pxl *b)
{
	int		x;

	x = a->x_win;
	if (a->x_win > b->x_win)
	{
		while (x != b->x_win)
		{
			pxl_to_img(data, x, a->y_win);
			x--;
		}
	}
	else if (a->x_win < b->x_win)
	{
		while (x != b->x_win)
		{
			pxl_to_img(data, x, a->y_win);
			x++;
		}
	}

}

void	st_line(t_data *data, t_pxl *a, t_pxl *b)
{
	if (a->x_win == b->x_win)
		up_down(data, a, b);
	else if (a->y_win == b->y_win)
		left_right(data, a, b);
}
/*
float	get_slope(int x0, int y0, int x1, int y1)
{
	float	x;
	float	y;

	x = x1 - x0;
	y = y1 - y0;
	return (y / x);
}

void	di_line(t_data *data, t_pxl *a, t_pxl *b)
{
	float	slope;
	float	temp_x;
	int		x;
	int		y;

	x  = a->x_win;
	slope = get_slope(a->x_win, a->y_win, b->x_win, b->y_win);
	while (x <= b->x_win)
	{
		temp_x = x - a->x_win;
		y = round(slope * temp_x) + a->y_win;
		pxl_to_img(data, x, y);
		x++;
	}
}
*/