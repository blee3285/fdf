/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:51:56 by blee              #+#    #+#             */
/*   Updated: 2018/11/19 16:30:10 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		controls()
{
	ft_printf("Rotation:\n a/d -> x-axis\n w/s -> y-axis\n");
	ft_printf(" q/e -> z-axis\n\nSize Scaling:\n");
	ft_printf(" up/down arrows -> height\n left/right arrows -> width\n\n");
	ft_printf("Speed:\n 1/2/3 -> slow/faster/fastest\n\n");
	ft_printf("Press 'r' to reset\n");
}

int		error(int num, t_data *data)
{
	if (num == 1)
	{
		ft_printf("\n")
	}
	else if (num == 2)
	{
		ft_printf("")
	}
}
