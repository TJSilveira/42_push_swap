/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:25:44 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:25:45 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	big(int i1, int i2)
{
	return (((i1 <= i2) * i2 + (i1 > i2) * i1));
}

void	print_filler(int *i, t_format *a)
{
	if (a->zero_pad == 1)
		write(1, "0", 1);
	else
		write(1, " ", 1);
	(*i)++;
}

int	ft_print_width_left(int size, t_format *a)
{
	int	i;

	if (size > a->width)
		return (0);
	i = 0;
	if (a->zero_pad == 1)
	{
		while (i < a->width - big(size, a->precision) - (a->hash * 2)
			&& a->left_just == 0)
			print_filler(&i, a);
	}
	else
	{
		while (i < a->width - big(size, a->precision) - (a->hash * 2)
			+ (a->sign == -1) * -1 && a->left_just == 0)
			print_filler(&i, a);
	}
	return (i);
}

int	ft_print_width_right(int size, t_format *spec)
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

int	ft_print_prec(int size, t_format *spec)
{
	int	i;

	if (spec->precision_set == 0)
		return (0);
	if (size > spec->precision)
		return (0);
	i = 0;
	while (i < big(size, spec->precision) - size)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}
