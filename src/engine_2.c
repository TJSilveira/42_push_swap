/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:09:33 by tsilveir          #+#    #+#             */
/*   Updated: 2025/07/02 09:09:34 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_move_finder(int moves_a, int moves_b)
{
	if (moves_a > 0 && moves_b > 0)
	{
		if (moves_a > moves_b)
			return (ft_abs(moves_a));
		else
			return (ft_abs(moves_b));
	}
	else if (moves_a < 0 && moves_b < 0)
	{
		if (moves_a < moves_b)
			return (ft_abs(moves_a));
		else
			return (ft_abs(moves_b));
	}
	else
		return ((ft_abs(moves_a) + ft_abs(moves_b)));
}

void	executor_combined_move(t_stacks *l)
{
	while ((l->a_moves > 0 && l->b_moves > 0)
		|| (l->a_moves < 0 && l->b_moves < 0))
	{
		if (0 < l->a_moves && 0 < l->b_moves)
		{
			rotate(&l->a, "r", PRINT);
			rotate(&l->b, "r", NOPRINT);
			(l->a_moves)--;
			(l->b_moves)--;
		}
		else if (0 > l->a_moves && 0 > l->b_moves)
		{
			rev_rotate(&l->a, "r", PRINT);
			rev_rotate(&l->b, "r", NOPRINT);
			(l->a_moves)++;
			(l->b_moves)++;
		}
	}
}

void	executor(t_stacks *l, char *option)
{
	executor_combined_move(l);
	while (l->a_moves || l->b_moves)
	{
		if (0 < l->a_moves && (l->a_moves)--)
			rotate(&l->a, "a", PRINT);
		else if (0 > l->a_moves && (l->a_moves)++)
			rev_rotate(&l->a, "a", PRINT);
		if (0 < l->b_moves && (l->b_moves)--)
			rotate(&l->b, "b", PRINT);
		else if (0 > l->b_moves && (l->b_moves)++)
			rev_rotate(&l->b, "b", PRINT);
	}
	if (ft_strncmp("a_to_b", option, 6) == 0)
		push(&(l->a), &(l->b), "b", PRINT);
	else if (ft_strncmp("b_to_a", option, 6) == 0)
		push(&(l->b), &(l->a), "a", PRINT);
}

void	find_cheapest_aux(t_stacks *l, char *op, t_s **stack, int in_loop)
{
	if (ft_strncmp(op, "a_to_b", 6) == 0 && in_loop == 0)
		(*stack) = l->a;
	else if (ft_strncmp(op, "b_to_a", 6) == 0 && in_loop == 0)
		(*stack) = l->b;
	else if (ft_strncmp(op, "a_to_b", 6) == 0 && in_loop == 1)
		(*stack) = l->b;
	else if (ft_strncmp(op, "b_to_a", 6) == 0 && in_loop == 1)
		(*stack) = l->a;
	else
	{
		ft_putstr_fd("Invalid options", 2);
		exit(EXIT_FAILURE);
	}
}

void	sort_3_elem(t_stacks *l)
{
	if (l->a == l->max_a)
		rotate(&l->a, "a", PRINT);
	else if (l->a->next == l->max_a)
		rev_rotate(&l->a, "a", PRINT);
	if (l->a != l->min_a)
		swap(&l->a, "a", PRINT);
}
