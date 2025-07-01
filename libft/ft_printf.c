/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:26:21 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:26:23 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_spec_zero(t_format	*spec)
{
	spec->left_just = 0;
	spec->precision = 0;
	spec->precision_set = 0;
	spec->specifier = 0;
	spec->width = 0;
	spec->zero_pad = 0;
	spec->hash = 0;
	spec->sign = 0;
	spec->space = 0;
}

static void	init_var(int *len, int *i, t_format *t)
{
	*len = 0;
	*i = 0;
	set_spec_zero(t);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	int			i;
	t_format	t;

	va_start(ap, format);
	init_var(&len, &i, &t);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (add_flg(format, &i, &t, &ap))
				len += ((int (*)(void *, t_format *))ft_print_func(&t))
					(va_arg(ap, void *), &t);
			else
				len += write(1, &format[i], 1);
		}
		else
			len += write(1, &format[i], 1);
		i++;
		set_spec_zero(&t);
	}
	va_end(ap);
	return (len);
}
