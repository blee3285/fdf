/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:22:42 by blee              #+#    #+#             */
/*   Updated: 2018/10/01 18:28:43 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_line(char *line)
{
	int		i;
	int		valid;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		valid = 0;
		if (line[i] == '-' && (!line[i + 1] || line[i + 1] == '-'))
			return (0);
		if (line[i] == '-' || line[i] == ' ' || ft_isdigit(line[i]))
			valid = 1;
		if (!valid)
			return (0);
		i++;
	}
	return (1);
}

int		num_count(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] && line[i] != ' ')
		{
			count++;
			while (line[i] && line[i] != ' ')
				i++;
		}
		if (line[i])
			i++;
	}
	return (count);
}

int		*atoi_arr(char *line, int size)
{
	int		*arr;
	int		i;
	char	*temp;

	i = 0;
	temp = line;
	if (!valid_line(line))
		return (NULL);
	arr = (int*)malloc(sizeof(int) * (size + 1));
	if (!arr)
		return (NULL);
	while (*temp && *temp != '\n')
	{
		if (*temp == '-' || ft_isdigit(*temp))
		{
			arr[i] = ft_atoi(temp);
			while(*temp == '-' || ft_isdigit(*temp))
				temp++;
			i++;
		}
		if (*temp)
			temp++;
	}
	return (arr);
}
