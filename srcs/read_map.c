/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:27:50 by blee              #+#    #+#             */
/*   Updated: 2018/10/01 18:30:36 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
t_map_lst	*new_map_lst(char *line)
{
	t_map_lst	*new;
	int			size;

	new = (t_map_lst*)malloc(sizeof(t_map_lst));
	new->next = NULL;
	size = 0;
	new->line = atoi_arr(line, &size);
	new->size = size;
	return (new);
}

void		add_map_lst(t_map_lst **lst, char *line)
{
	t_map_lst	*new;
	t_map_lst	*temp;

	new = new_map_lst(line);
	temp = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
*/
/*
t_map_lst	*read_map(char *file)
{
	t_map_lst	*lst;
	int			fd;
	int			out;
	char		*buff;

	lst = NULL;
	fd = open(file, O_RDONLY);
	while ((out = get_next_line(fd, &buff)))
	{
		if (out == -1)
		{
			if (buff)
				free(buff);
			//free lst too
			return (NULL);
		}
		add_map_lst(&lst, buff);
		free(buff);
	}
	return (lst);
}
*/


void	read_map(t_data *data, char *file)
{
	int		fd;
	int		out;
	int		i;
	char	*buff;

	i = 0;
	fd = open(file, O_RDONLY);
	//check fd here
	data->map = (int**)malloc(sizeof(int*) * (data->y_size));
	while ((out = get_next_line(fd, &buff)))
	{
		if (out == -1)
		{
			if (buff)
				free(buff);
			return ;
		}
		data->map[i] = atoi_arr(buff, data->x_size);
		i++;
	}
	close(fd);
}
