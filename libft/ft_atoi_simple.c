/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:21:46 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:21:48 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_simple(const char *nptr, int *i)
{
	int	total;

	total = 0;
	if (!(nptr[*i] >= '0' && nptr[*i] <= '9'))
		return (-1);
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		total = total * 10 + nptr[*i] - '0';
		(*i)++;
	}
	return (total);
}
