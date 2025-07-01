/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:24:58 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:25:00 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nil_check(t_format *spec)
{
	int	size;

	size = 5;
	size += ft_print_width_left(size, spec);
	write(1, "(nil)", 5);
	size += ft_print_width_right(size, spec);
	return (size);
}

int	ft_print_p(void *str, t_format *spec)
{
	char				array_temp[200];
	int					i;
	unsigned long int	nbr;
	int					size;

	if (!str)
		return (nil_check(spec));
	i = 0;
	nbr = (unsigned long int)str;
	while (nbr >= 16)
	{
		array_temp[i] = "0123456789abcdef"[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	array_temp[i] = "0123456789abcdef"[nbr % 16];
	size = i + 3;
	size += ft_print_width_left(size, spec);
	write(1, "0x", 2);
	while ((i) >= 0)
		write(1, &array_temp[i--], 1);
	size += ft_print_width_right(size, spec);
	return (size);
}
