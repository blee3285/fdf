/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:34:20 by blee              #+#    #+#             */
/*   Updated: 2018/11/30 19:05:32 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		angle_display(t_data *data)
{
	char	*tmp;

	tmp = ft_itoa(data->x_deg);
	mlx_string_put(data->mlx, data->win,
			(data->wd / 3) - 15, 5, 0xFFFFFF, "X:");
	mlx_string_put(data->mlx, data->win,
			(data->wd / 3) + 5, 5, 0xFFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(data->y_deg);
	mlx_string_put(data->mlx, data->win,
			(data->wd / 2) - 15, 5, 0xFFFFFF, "Y:");
	mlx_string_put(data->mlx, data->win,
			(data->wd / 2) + 5, 5, 0xFFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(data->z_deg);
	mlx_string_put(data->mlx, data->win,
			((data->wd * 2) / 3) - 15, 5, 0xFFFFFF, "Z:");
	mlx_string_put(data->mlx, data->win,
			((data->wd * 2) / 3) + 5, 5, 0xFFFFFF, tmp);
	free(tmp);
}
