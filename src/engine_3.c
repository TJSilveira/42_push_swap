/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:09:42 by tsilveir          #+#    #+#             */
/*   Updated: 2025/07/02 09:09:46 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	final_order_corrector(t_stacks *l)
{
	t_s	*find;

	find = l->a;
	l->a_moves = 0;
	l->b_moves = 0;
	l->len_a = stack_length(l->a);
	update_maxmin(l);
	while (find != l->min_a)
	{
		l->a_moves++;
		find = find->next;
	}
	if (l->a_moves > l->len_a / 2)
		l->a_moves = l->a_moves - l->len_a;
	while (1)
	{
		if (is_sorted(l->a))
			break ;
		executor(l, "Nothing");
	}
}
