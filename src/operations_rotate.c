/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:10:15 by tsilveir          #+#    #+#             */
/*   Updated: 2025/07/02 09:10:16 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* This function handles both swap a and swap b */
void	rotate(t_s **s, char *name, int option)
{
	t_s	*second_node;

	if ((*s) == NULL || (*s)->next == (*s))
	{
		print_move("r", name, option);
		return ;
	}
	second_node = (*s)->next;
	second_node->start = 1;
	(*s)->start = 0;
	(*s) = second_node;
	print_move("r", name, option);
}

void	rev_rotate(t_s **s, char *name, int option)
{
	t_s	*last_node;

	if ((*s) == NULL || (*s)->next == (*s))
	{
		print_move("rr", name, option);
		return ;
	}
	last_node = (*s)->next;
	while (last_node->next->start == 0)
		last_node = last_node->next;
	last_node->start = 1;
	(*s)->start = 0;
	(*s) = last_node;
	print_move("rr", name, option);
}
