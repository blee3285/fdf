/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:25:52 by blee              #+#    #+#             */
/*   Updated: 2018/12/11 18:00:13 by blee             ###   ########.fr       */
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

int		bad_size(t_data *data, char *buff)
{
	int		len;

	len = line_size(buff);
	if (data->y_size == 0)
		data->x_size = len;
	data->y_size += 1;
	if (len != data->x_size)
		return (2);
	return (0);
}

int		map_error(int err, char *buff)
{
	if (buff)
		free(buff);
	return (err);
}

int		map_size(t_data *data, char *file)
{
	int		fd;
	int		out;
	char	*buff;

	fd = open(file, O_RDONLY);
	while ((out = get_next_line(fd, &buff)))
	{
		if (out == -1)
			return (map_error(1, buff));
		if (!valid_line(buff))
			return (map_error(3, buff));
		if (bad_size(data, buff))
			return (map_error(2, buff));
		free(buff);
	}
	close(fd);
	return (0);
}
