/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:36:43 by blee              #+#    #+#             */
/*   Updated: 2018/10/01 18:28:49 by blee             ###   ########.fr       */
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

typedef	struct			s_pxl
{
	int					x_start;
	int					y_start;
	int					z_start;
	int					x;
	int					y;
	int					z;
}						t_pxl;	

typedef struct			s_data
{
	int					**map;
	t_pxl				**pxl;
	int					x_size;
	int					y_size;
	int					h_mod;
	int					s_mod;
	int					x_ag;
	int					y_ag;
	int					z_ag;
}						t_data;

void					read_map(t_data *data, char *file);
int						*atoi_arr(char *line, int size);
t_map_arr				*lst_to_arr(t_map_lst *lst);
void					map_size(t_data *data, char *file);

#endif
