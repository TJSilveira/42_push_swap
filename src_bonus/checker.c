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
	if (ft_strncmp("pb", rule, 2) == 0)
		push(&l->a, &l->b, "b", NOPRINT);
	else if (ft_strncmp("pa", rule, 2) == 0)
		push(&l->b, &l->a, "a", NOPRINT);
	else if (ft_strncmp("sa", rule, 2) == 0)
		swap(&l->a, "a", NOPRINT);
	else if (ft_strncmp("sb", rule, 2) == 0)
		swap(&l->b, "b", NOPRINT);
	else if (ft_strncmp("rra", rule, 3) == 0)
		rev_rotate(&l->a, "a", NOPRINT);
	else if (ft_strncmp("rrb", rule, 3) == 0)
		rev_rotate(&l->b, "b", NOPRINT);
	else if (ft_strncmp("rrr", rule, 3) == 0)
		combine_rotate(l, rule);
	else if (ft_strncmp("ra", rule, 2) == 0)
		rotate(&l->a, "a", NOPRINT);
	else if (ft_strncmp("rb", rule, 2) == 0)
		rotate(&l->b, "b", NOPRINT);
	else if (ft_strncmp("rr", rule, 2) == 0)
		combine_rotate(l, rule);
	else
		error_handler(l, rule);
	free(rule);
}

void	error_handler(t_stacks *l, char *rule)
{
	ft_printf("Rule is invalid: %s\n", rule);
	list_clear(l);
	free(rule);
	get_next_line(-1);
	exit(EXIT_FAILURE);
}

void	combine_rotate(t_stacks *l, char *rule)
{
	if (ft_strncmp("rrr", rule, 3) == 0)
	{
		rev_rotate(&l->a, "a", NOPRINT);
		rev_rotate(&l->b, "b", NOPRINT);
	}
	else if (ft_strncmp("rr", rule, 2) == 0)
	{
		rotate(&l->a, "a", NOPRINT);
		rotate(&l->b, "b", NOPRINT);
	}
}
