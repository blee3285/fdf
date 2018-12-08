/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:36:43 by blee              #+#    #+#             */
/*   Updated: 2018/12/07 18:53:07 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>

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
	int					x_init;
	int					y_init;
	int					z_init;
	int					x;
	int					y;
	int					z;
	int					x_win;
	int					y_win;
}						t_pxl;

typedef struct			s_data
{
	void				*mlx;
	void				*win;
	void				*img;
	t_pxl				***pxl;
	int					x_size;
	int					y_size;
	int					z_size;
	int					wd;
	int					ht;
	int					xy_mod;
	int					z_mod;
	int					x_deg;
	int					y_deg;
	int					z_deg;
	int					spd;
	int					red;
	int					green;
	int					blue;
	int					p;
	int					mode;
}						t_data;

int						read_map(t_data *data, char *file);
int						*atoi_arr(char *line, int size);
t_pxl					**pxl_arr(t_data *data, char *line, int y);
int						map_size(t_data *data, char *file);
void					rotate_pxl(t_data *data, t_pxl *pxl);
int						win_pxl(int x, int dist);
void					new_coord(t_data *data, t_pxl *pxl);

void					resize(t_data *data);
void					resize_pxl(t_data *data, t_pxl *pxl, int xy_mod, int z_mod);

void					pxl_to_img(t_data *data, int x, int y);
void					color_pxl(t_data *data, int x, int y, int *col);
void					new_img(t_data *data);

void					st_line(t_data *data, t_pxl *a, t_pxl *b);
void					di_line(t_data *data, t_pxl *a, t_pxl *b);
void					draw_map(t_data *data);

int						keyboard(int key, t_data *data);

void					free_data(t_data *data);

int						controls();
int						error(int num, t_data *data);

void					angle_display(t_data *data);
void					colors(int key, t_data *data);
#endif
