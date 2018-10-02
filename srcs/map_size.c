/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:25:52 by blee              #+#    #+#             */
/*   Updated: 2018/10/01 17:07:00 by blee             ###   ########.fr       */
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

void	map_size(t_data *data, char *file)
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
			return ;
		}
		len = line_size(buff);
		if (len > data->x_size)
			data->x_size = len;
		data->y_size += 1;
		free(buff);
	}
	close(fd);
}
