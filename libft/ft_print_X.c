/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:26:06 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:26:07 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_bigx(unsigned int nbr, t_format *spec)
{
	char	array_temp[50];
	int		i;
	int		size_total;
	int		size_nbr;

	i = 0;
	while (nbr >= 16)
	{
		array_temp[i] = "0123456789ABCDEF"[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	array_temp[i] = "0123456789ABCDEF"[nbr % 16];
	size_total = i + 1;
	if (spec->precision_set == 1 && spec->precision == 0 && nbr == 0)
		return (ft_print_width_left(0, spec));
	size_nbr = size_total;
	size_total += ft_print_width_left(size_total, spec);
	size_total += x_bonus_flags(spec, nbr, 'X');
	size_total += ft_print_prec(size_nbr, spec);
	while ((i) >= 0)
		write(1, &array_temp[i--], 1);
	size_total += ft_print_width_right(size_total, spec);
	return (size_total);
}
