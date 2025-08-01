/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:11:22 by tsilveir          #+#    #+#             */
/*   Updated: 2025/07/02 09:11:23 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stacks	*list_loader(t_s *s_a, t_s *s_b)
{
	t_stacks	*list;

	list = malloc(sizeof(t_stacks));
	list->a = s_a;
	list->b = s_b;
	list->len_a = stack_length(list->a);
	list->len_b = stack_length(list->b);
	cheapest_moves_reset(list, "a_to_b");
	return (list);
}

void	cheapest_moves_reset(t_stacks *list, char *option)
{
	if (ft_strncmp("a_to_b", option, 6) == 0)
		list->cheapest_node = list->a;
	else
		list->cheapest_node = list->b;
	list->a_moves = 9000;
	list->b_moves = -9000;
}

void	update_maxmin_b(t_stacks *list)
{
	t_s	*a_cur;

	if (list->a)
	{
		a_cur = list->a;
		list->min_a = a_cur;
		list->max_a = a_cur;
		a_cur = a_cur->next;
		while (a_cur != list->a)
		{
			if (a_cur->num < list->min_a->num)
				list->min_a = a_cur;
			if (a_cur->num > list->max_a->num)
				list->max_a = a_cur;
			a_cur = a_cur->next;
		}
	}
}

void	update_maxmin(t_stacks *list)
{
	t_s	*b_cur;

	if (!list)
		return ;
	if (list->b)
	{
		b_cur = list->b;
		list->min_b = b_cur;
		list->max_b = b_cur;
		b_cur = b_cur->next;
		while (b_cur != list->b)
		{
			if (b_cur->num < list->min_b->num)
				list->min_b = b_cur;
			if (b_cur->num > list->max_b->num)
				list->max_b = b_cur;
			b_cur = b_cur->next;
		}
	}
	update_maxmin_b(list);
}

t_s	*find_last_node(t_s *first)
{
	t_s	*last;

	if (first == NULL)
		return (NULL);
	last = first;
	while (last->next != first)
		last = last->next;
	return (last);
}
