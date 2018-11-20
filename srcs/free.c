/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:30:28 by blee              #+#    #+#             */
/*   Updated: 2018/11/19 17:53:06 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_pxl(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < y_size)
	{
		i = 0;
		while (i < x_size)
		{
			free(data->pxl[j][i]);
			i++;
		}
		free(data->pxl[j]);
		j++;
	}
	free(data->pxl);
}

void	free_data(t_data *data)
{
	free_pxl(data);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
}
