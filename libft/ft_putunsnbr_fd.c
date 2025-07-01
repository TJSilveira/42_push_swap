/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:26:42 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:26:45 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

void	ft_putunsnbr_fd(unsigned int n, int fd)
{
	char	ch;

	if (n >= 10)
		ft_putunsnbr_fd(n / 10, fd);
	ch = n % 10 + '0';
	write(fd, &ch, 1);
}
