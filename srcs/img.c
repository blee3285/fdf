/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:22:25 by blee              #+#    #+#             */
/*   Updated: 2018/12/07 16:37:19 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pxl_to_img(t_data *data, int x, int y)
{
	char	*addr;
	int 	bbp;
	int		lsize;
	int		end;
	int		i;

	if (x < 0 || y < 0 || x > data->wd || y > data->ht)
		return ;
	i = 0;
	addr = mlx_get_data_addr(data->img, &bbp, &lsize, &end);
	if (end == 0)
	{
		while (i < (bbp / 8))
		{
			addr[y * lsize + x * (bbp / 8) + i] = (char)data->blue;
			addr[y * lsize + x * (bbp / 8) + i + 1] = (char)data->green;
			addr[y * lsize + x * (bbp / 8) + i + 2] = (char)data->red;
			addr[y * lsize + x * (bbp / 8) + i + 3] = 0x0;
			i += 4;
		}
	}
}

void	new_img(t_data *data)
{
	resize(data);
	data->img = mlx_new_image(data->mlx, data->wd, data->ht);
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	//angle_display(data);
}
