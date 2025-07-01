/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:25:15 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:25:16 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	min(int n1, int n2)
{
	if (n1 <= n2)
		return (n1);
	else
		return (n2);
}

int	ft_print_s(char *str, t_format *spec)
{
	int	i;
	int	len;

	if (!str)
	{
		len = 6;
		len += ft_print_width_left_cs(len, spec);
		write(1, "(null)", 6);
		len += ft_print_width_right_cs(len, spec);
		return (len);
	}
	len = ft_strlen(str);
	i = ft_print_width_left_cs(len, spec);
	if (spec->precision_set)
	{
		write(1, str, min(spec->precision, len));
		i += ft_print_width_right_cs(len, spec);
		return (min(spec->precision, len) + i);
	}
	else
	{
		write(1, str, len);
		i += ft_print_width_right_cs(len, spec);
		return (len + i);
	}
}
