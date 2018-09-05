/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 19:04:36 by blee              #+#    #+#             */
/*   Updated: 2018/09/04 17:17:34 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		map_len(t_map_lst *lst)
{
	int			i;
	t_map_lst	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int		*cpy_int_arr(t_map_lst *lst)
{
	int		*cpy;
	int		i;

	i = 0;
	cpy = ft_intarray(lst->size);
	while (i < lst->size)
	{
		cpy[i] = lst->line[i];
		i++;
	}
	return (cpy);
}

int			**convert_to_arr(t_map_lst *lst)
{
	int			len;
	int			i;
	int			**arr;
	t_map_lst	*temp;

	i = 0;
	len = map_len(lst);
	temp = lst;
	arr = (int**)malloc(sizeof(int*) * len);
	while (i < len)
	{
		arr[i] = cpy_int_arr(temp);
		temp = temp->next;
		i++;
	}
	return (arr);
}

t_map_arr	*lst_to_arr(t_map_lst *lst)
{
	t_map_arr	*new;
	t_map_lst	*temp;

	new = (t_map_arr*)malloc(sizeof(t_map_arr));
	new->map = convert_to_arr(lst);
	new->x_size = 0;
	new->y_size = 0;
	temp = lst;
	while (temp)
	{
		if (temp->size > new->x_size)
			new->x_size = temp->size;
		new->y_size++;
		temp = temp->next;
	}
	return (new);
}
