#include "../includes/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stacks	*list;

	if (argc == 1)
		exit (EXIT_SUCCESS);
	list = init_stack(argc, argv);
	execute_rules(list);
	if (is_sorted(list->a) && list->b == NULL)
		ft_printf("OK");
	else
		ft_printf("KO");
	release_stacks(list);
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
	if (ft_strncmp("ra", rule, 2))
		rotate(&l->a, "a", PRINT);
	else if (ft_strncmp("rb", rule, 2))
		rotate(&l->b, "b", PRINT);
	else if (ft_strncmp("rb", rule, 2))
	{
		rotate(&l->a, "r", PRINT);
		rotate(&l->b, "r", NOPRINT);
	}
	else if (ft_strncmp("sa", rule, 2))
		swap(&l->a, "a", PRINT);
	else if (ft_strncmp("sb", rule, 2))
		swap(&l->b, "b", PRINT);
	else if (ft_strncmp("rra", rule, 3))
		rev_rotate(&l->a, "a", PRINT);
	else if (ft_strncmp("rrb", rule, 3))
		rev_rotate(&l->b, "b", PRINT);
	else if (ft_strncmp("rrr", rule, 3))
	{
		rev_rotate(&l->a, "r", PRINT);
		rev_rotate(&l->b, "r", NOPRINT);
	}
	else
		error_handler(l, rule);
	free(rule);
}

void	error_handler(t_stacks *l, char *rule)
{
	ft_printf("Rule is invalid: %s\n", rule);
	release_stacks(l);
	free(rule);
	exit(EXIT_FAILURE);
}

void	release_stacks(t_stacks *l)
{
	t_s	*temp;
	t_s	*last;

	last = find_last_node(l->a);
	last->next = NULL;
	while (l->a)
	{
		temp = l->a;
		l->a = l->a->next;
		free(temp);
		temp = NULL;
	}
	last = find_last_node(l->a);
	last->next = NULL;
	while (l->b)
	{
		temp = l->b;
		l->b = l->b->next;
		free(temp);
		temp = NULL;
	}
	free(l);
}
