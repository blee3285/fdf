/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:25:52 by blee              #+#    #+#             */
/*   Updated: 2018/10/25 17:07:00 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		line_size(char *line)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			size++;
			while (ft_isdigit(line[i]))
				i++;
		}
		if (line[i])
			i++;
	}
	return (size);
}

int		map_size(t_data *data, char *file)
{
	int		fd;
	int		out;
	int		len;
	char	*buff;

	fd = open(file, O_RDONLY);
	while ((out = get_next_line(fd, &buff)))
	{
		if (out == -1)
		{
			if (buff)
				free(buff);
			return (0);
		}
		len = line_size(buff);
		if (data->y_size == 0)
			data->x_size = len;
		data->y_size += 1;
		free(buff);
		if (len != data->x_size)
			return (0);
	}
	close(fd);
	return (1);
}
