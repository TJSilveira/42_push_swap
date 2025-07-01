/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:26:01 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:26:01 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	x_bonus_flags(t_format *spec, unsigned int nbr, char option)
{
	int	counter;

	counter = 0;
	if (spec->hash == 1 && option == 'x' && nbr != 0)
	{
		ft_putstr_fd("0x", 1);
		counter += 2;
	}
	else if (spec->hash == 1 && option == 'X' && nbr != 0)
	{
		ft_putstr_fd("0X", 1);
		counter += 2;
	}
	return (counter);
}

int	ft_print_x(unsigned int nbr, t_format *spec)
{
	char	array_temp[50];
	int		i;
	int		size_total;
	int		size_nbr;

	i = 0;
	while (nbr >= 16)
	{
		array_temp[i] = "0123456789abcdef"[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	array_temp[i] = "0123456789abcdef"[nbr % 16];
	size_total = i + 1;
	if (spec->precision_set == 1 && spec->precision == 0 && nbr == 0)
		return (ft_print_width_left(0, spec));
	size_nbr = size_total;
	size_total += ft_print_width_left(size_total, spec);
	size_total += x_bonus_flags(spec, nbr, 'x');
	size_total += ft_print_prec(size_nbr, spec);
	while ((i) >= 0)
		write(1, &array_temp[i--], 1);
	size_total += ft_print_width_right(size_total, spec);
	return (size_total);
}
