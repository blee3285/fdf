/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:27:50 by blee              #+#    #+#             */
/*   Updated: 2018/10/03 17:42:46 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(t_data *data, char *file)
{
	int		fd;
	int		out;
	int		i;
	char	*buff;

	i = 0;
	fd = open(file, O_RDONLY);
	//check fd here
	data->pxl = (t_pxl***)malloc(sizeof(t_pxl**) * (data->y_size));
	while ((out = get_next_line(fd, &buff)))
	{
		if (out == -1)
		{
			if (buff)
				free(buff);
			return ;
		}
		data->pxl[i] = pxl_arr(data, buff, i);
		i++;
	}
	close(fd);
}
