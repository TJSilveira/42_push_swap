/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:21:59 by tsilveir          #+#    #+#             */
/*   Updated: 2025/06/19 17:22:01 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_print_func(t_format *spec)
{
	if (spec->specifier == 'c')
		return (&ft_print_c);
	else if (spec->specifier == 's')
		return (&ft_print_s);
	else if (spec->specifier == 'p')
		return (&ft_print_p);
	else if (spec->specifier == 'd' || spec->specifier == 'i')
		return (&ft_print_int);
	else if (spec->specifier == 'u')
		return (&ft_print_u);
	else if (spec->specifier == 'x')
		return (&ft_print_x);
	else if (spec->specifier == 'X')
		return (&ft_print_bigx);
	return (NULL);
}

int	add_flg_aux_1(const char *str, int *i, t_format *format)
{
	if (str[*i] == '#' && format->hash == 0)
	{
		format->hash = 1;
		(*i)++;
		return (1);
	}
	else if (str[*i] == ' ' && format->space == 0)
	{
		format->space = 1;
		(*i)++;
		return (1);
	}
	else if (str[*i] == '+' && format->sign == 0)
	{
		format->sign = 1;
		(*i)++;
		return (1);
	}
	else if (str[*i] == '0' && format->precision_set == 0)
	{
		format->zero_pad = 1;
		(*i)++;
		return (1);
	}
	return (0);
}

int	add_flg_aux_2(const char *str, int *i, t_format *format, va_list *ap)
{
	if (str[*i] == '-')
	{
		format->left_just = 1;
		(*i)++;
		return (1);
	}
	if (ft_isdigit(str[*i]) && format->precision_set == 0)
	{
		format->width = ft_atoi_simple(str, i);
		return (1);
	}
	else if (str[*i] == '*' && format->precision_set == 0)
	{
		format->width = va_arg(*ap, int);
		(*i)++;
		return (1);
	}
	else if (str[*i] == '.')
	{
		format->precision_set = 1;
		(*i)++;
		return (1);
	}
	return (0);
}

int	add_flg(const char *str, int *i, t_format *format, va_list *ap)
{
	while (str[*i] != 0)
	{
		if (add_flg_aux_1(str, i, format))
			continue ;
		else if (add_flg_aux_2(str, i, format, ap))
			continue ;
		else if (ft_isdigit(str[*i]) && format->precision_set == 1)
			format->precision = ft_atoi_simple(str, i);
		else if (str[*i] == '*' && format->precision_set == 1)
		{
			format->precision = va_arg(*ap, int);
			(*i)++;
		}
		else if (ft_is_incset(str[*i], "cspdiuxX"))
		{
			format->specifier = str[*i];
			return (1);
		}
		else
			return (0);
	}
	return (0);
}
