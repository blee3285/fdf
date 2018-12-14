/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:51:56 by blee              #+#    #+#             */
/*   Updated: 2018/12/13 19:07:47 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		controls(void)
{
	ft_printf("Rotation:\n a/d -> x-axis\n w/s -> y-axis\n");
	ft_printf(" q/e -> z-axis\n\nSize:\n");
	ft_printf(" up/down arrows -> height\n left/right arrows -> width\n\n");
	ft_printf("Speed:\n 1/2/3 -> slow/faster/fastest\n\n");
	ft_printf("Color Mode:\n shift -> switch modes\n q/a -> red\n");
	ft_printf(" w/s -> green\n e/d -> blue\n\n");
	ft_printf("Press 'z' for parallel projection\n");
	ft_printf("Press 'x' for isometric projection\nPress 'r' to reset\n");
	return (0);
}

void	error_out(t_data *data, char *msg)
{
	ft_printf(msg);
	free(data);
	exit(0);
}

int		error(int num, t_data *data)
{
	if (num == 1)
		error_out(data, "File error\n");
	else if (num == 2)
		error_out(data, "Mismatched line lengths\n");
	else if (num == 3)
		error_out(data, "Invalid characters in line\n");
	else if (num == 4)
		error_out(data, "Malloc error");
	return (0);
}
