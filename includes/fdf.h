/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:36:43 by blee              #+#    #+#             */
/*   Updated: 2018/09/11 19:06:53 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

typedef struct			s_map_lst
{
	int					*line;
	int					size;
	struct s_map_lst	*next;
}						t_map_lst;

typedef struct			s_map_arr
{
	int					**map;
	int					x_size;
	int					y_size;
}						t_map_arr;

typedef	struct			s_pxls
{
	int					x;
	int					y;
}						t_pxls;	

typedef struct			s_data
{
	t_map_arr			**map;
	t_pxls				**pxls;
	int					x_size;
	int					y_size;
	int					zoom;
	int					height;
}						t_data;

t_map_lst				*read_map(char *file);
int						*atoi_arr(char *line, int *size);
t_map_arr				*lst_to_arr(t_map_lst *lst);

#endif
