/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:22:15 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:22:16 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(char c, t_format *spec)
{
	int	i;

	i = ft_print_width_left_cs(1, spec);
	write(1, &c, 1);
	i += ft_print_width_right_cs(1, spec);
	return (i + 1);
}
