/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:27:50 by blee              #+#    #+#             */
/*   Updated: 2018/12/11 19:10:39 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_pxl_arr(t_pxl **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int		read_map(t_data *data, char *file)
{
	int		fd;
	int		out;
	int		i;
	char	*buff;

	i = 0;
	fd = open(file, O_RDONLY);
	data->pxl = (t_pxl***)malloc(sizeof(t_pxl**) * (data->y_size));
	while ((out = get_next_line(fd, &buff)))
	{
		if (out == -1)
		{
			if (buff)
				free(buff);
			return (1);
		}
		data->pxl[i] = pxl_arr(data, buff, i);
		if (!data->pxl[i])
			return (4);
		i++;
		free(buff);
	}
	close(fd);
	return (0);
}
