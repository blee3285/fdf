/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:36:43 by blee              #+#    #+#             */
/*   Updated: 2018/08/29 19:21:18 by blee             ###   ########.fr       */
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

typedef struct			s_data
{
	int					**map;
	int					size_x;
	int					size_y;
}						t_data;

t_map_lst				*read_map(char *file);
int						*atoi_arr(char *line, int *size);

#endif
