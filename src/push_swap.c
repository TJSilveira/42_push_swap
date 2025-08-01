/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:11:00 by tsilveir          #+#    #+#             */
/*   Updated: 2025/07/02 09:11:01 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*list;

	if (argc == 1)
		exit(0);
	list = init_stack(argc, argv);
	if (is_sorted(list->a) && list->b == NULL)
	{
		list_clear(list);
		return (0);
	}
	else if (list->len_a == 2)
		rotate(&list->a, "a", PRINT);
	else
	{
		order_stack_b(list, argc - 1);
		order_stack_a(list);
		final_order_corrector(list);
	}
	list_clear(list);
	return (0);
}

void	order_stack_b(t_stacks *list, int size)
{
	while ((list->len_a > 3) && (list->len_a >= size - 2))
	{
		push(&(list->a), &(list->b), "b", PRINT);
		list->len_a = stack_length(list->a);
	}
	while (1)
	{
		if (is_sorted(list->a) && list->b == NULL)
			exit(EXIT_SUCCESS);
		list->len_a = stack_length(list->a);
		list->len_b = stack_length(list->b);
		update_maxmin(list);
		if (list->len_a == 3)
		{
			sort_3_elem(list);
			break ;
		}
		find_cheapest(list, "a_to_b");
		executor(list, "a_to_b");
	}
}

void	order_stack_a(t_stacks *list)
{
	while (1)
	{
		if ((is_sorted(list->a) && list->b == NULL) || list->b == NULL)
			break ;
		list->len_a = stack_length(list->a);
		list->len_b = stack_length(list->b);
		update_maxmin(list);
		find_cheapest(list, "b_to_a");
		executor(list, "b_to_a");
	}
}
