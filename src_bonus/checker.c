/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:11:48 by tsilveir          #+#    #+#             */
/*   Updated: 2025/07/02 09:11:49 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stacks	*list;

	if (argc == 1)
		exit (EXIT_SUCCESS);
	list = init_stack(argc, argv);
	execute_rules(list);
	if (list->b == NULL && is_sorted(list->a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	list_clear(list);
	get_next_line(-1);
	return (0);
}

void	execute_rules(t_stacks *l)
{
	char	*rule;

	rule = get_next_line(0);
	while (rule)
	{
		operation_redirect(l, rule);
		rule = get_next_line(0);
	}
}

void	operation_redirect(t_stacks *l, char *rule)
{
	if (ft_strncmp("pb\n", rule, 3) == 0)
		push(&l->a, &l->b, "b", NOPRINT);
	else if (ft_strncmp("pa\n", rule, 3) == 0)
		push(&l->b, &l->a, "a", NOPRINT);
	else if (ft_strncmp("sa\n", rule, 3) == 0)
		swap(&l->a, "a", NOPRINT);
	else if (ft_strncmp("sb\n", rule, 3) == 0)
		swap(&l->b, "b", NOPRINT);
	else if (ft_strncmp("rra\n", rule, 4) == 0)
		rev_rotate(&l->a, "a", NOPRINT);
	else if (ft_strncmp("rrb\n", rule, 4) == 0)
		rev_rotate(&l->b, "b", NOPRINT);
	else if (ft_strncmp("rrr\n", rule, 4) == 0)
		combine_rotate(l, rule);
	else if (ft_strncmp("ra\n", rule, 3) == 0)
		rotate(&l->a, "a", NOPRINT);
	else if (ft_strncmp("rb\n", rule, 3) == 0)
		rotate(&l->b, "b", NOPRINT);
	else if (ft_strncmp("rr\n", rule, 3) == 0)
		combine_rotate(l, rule);
	else
		error_handler(l, rule);
	free(rule);
}

void	error_handler(t_stacks *l, char *rule)
{
	ft_printf("Error\n");
	list_clear(l);
	free(rule);
	get_next_line(-1);
	exit(EXIT_FAILURE);
}

void	combine_rotate(t_stacks *l, char *rule)
{
	if (ft_strncmp("rrr\n", rule, 4) == 0)
	{
		rev_rotate(&l->a, "a", NOPRINT);
		rev_rotate(&l->b, "b", NOPRINT);
	}
	else if (ft_strncmp("rr\n", rule, 3) == 0)
	{
		rotate(&l->a, "a", NOPRINT);
		rotate(&l->b, "b", NOPRINT);
	}
}
