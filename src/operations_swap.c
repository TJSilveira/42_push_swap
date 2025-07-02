/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:10:33 by tsilveir          #+#    #+#             */
/*   Updated: 2025/07/02 09:10:34 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function handles both swap a and swap b */
void	swap(t_s **s, char *name, int option)
{
	t_s	*last_node;
	t_s	*first_node;
	t_s	*second_node;

	if ((*s) == NULL || (*s)->next == (*s))
	{
		print_move("s", name, option);
		return ;
	}
	last_node = (*s)->next;
	while (last_node->next->start == 0)
		last_node = last_node->next;
	first_node = (*s);
	second_node = first_node->next;
	first_node->start = 0;
	second_node->start = 1;
	first_node->next = second_node->next;
	second_node->next = first_node;
	(*s) = second_node;
	last_node->next = second_node;
	print_move("s", name, option);
}
