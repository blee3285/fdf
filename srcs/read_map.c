/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 18:27:50 by blee              #+#    #+#             */
/*   Updated: 2018/08/27 19:44:58 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_lst	*new_map_lst(char *line)
{
	t_map_lst	*new;
	int			size;

	new = (t_map_lst*)malloc(sizeof(t_map_lst));
	new->next = NULL;
	size = 0;
	new->line = atoi_arr(line, &size);
	new->size = size;
	ft_printf("%s\n", new->line);
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
