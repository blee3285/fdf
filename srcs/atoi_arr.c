/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:22:42 by blee              #+#    #+#             */
/*   Updated: 2018/08/16 19:06:24 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-' && (!line[i + 1] || line[i + 1] == '-'))
			return (0);
		if (line[i] == ' ' && (!line[i + 1] || line[i + 1] == ' '))
			return (0);
		if (line[i] != '-' || line[i] != ' ' || !ft_isdigit(line[i]))
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
	while (line[i])
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

int		*atoi_arr(char *line)
{
	int		*arr;
	int		i;
	char	*temp;

	i = 0;
	temp = line;
	if (!valid_line(line))
		return (NULL);
	arr = (int*)malloc(sizeof(int) * (num_count(line) + 1));
	if (!arr)
		return (NULL);
	while (*temp)
	{
		if (*temp == '-' || ft_isdigit(*temp))
		{
			arr[i] = ft_atoi(temp);
			while(*temp == '-' || ft_isdigit(*temp))
				temp++;
		}
		if (*temp)
			temp++;
	}
	return (arr);
}
