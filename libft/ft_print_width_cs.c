/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width_cs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:25:37 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:25:38 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_width_left_cs(int size, t_format *a)
{
	int	i;

	if (size > a->width)
		return (0);
	i = 0;
	if (a->zero_pad == 1)
	{
		while (i < a->width - size - (a->hash * 2) && a->left_just == 0)
			print_filler(&i, a);
	}
	else
	{
		while (i < a->width - size - (a->hash * 2) + (a->sign == -1)
			* -1 && a->left_just == 0)
			print_filler(&i, a);
	}
	return (i);
}

int	ft_print_width_right_cs(int size, t_format *spec)
{
	int	i;

	if (size > spec->width)
		return (0);
	i = 0;
	while (i < spec->width - size && spec->left_just == 1)
	{
		if (spec->zero_pad == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		i++;
	}
	return (i);
}
