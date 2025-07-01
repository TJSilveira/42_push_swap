/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:25:23 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:25:24 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(unsigned int nbr, t_format *spec)
{
	int				counter_total;
	int				counter_nbr;
	unsigned int	nbr_temp;

	counter_total = 0;
	nbr_temp = nbr;
	while (nbr_temp > 9)
	{
		nbr_temp = nbr_temp / 10;
		counter_total++;
	}
	counter_total++;
	counter_nbr = counter_total;
	if (spec->precision_set == 1 && spec->precision == 0 && nbr == 0)
		return (ft_print_width_left(0, spec));
	counter_total += ft_print_width_left(counter_total, spec);
	counter_total += ft_print_prec(counter_nbr, spec);
	ft_putunsnbr_fd(nbr, 1);
	counter_total += ft_print_width_right(counter_total, spec);
	return (counter_total);
}
