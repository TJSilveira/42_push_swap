#include "../includes/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stacks	*list;

	if (argc == 1)
		exit (EXIT_SUCCESS);
	list = init_stack(argc, argv);
	execute_rules(list);
	print_stacks(list->a, list->b, argc - 1);
	if (is_sorted(list->a) && list->b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	list_clear(list);
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
		rotate(&l->a, "a", NOPRINT);
	else if (ft_strncmp("rb", rule, 2))
		rotate(&l->b, "b", NOPRINT);
	else if (ft_strncmp("rb", rule, 2))
	{
		rotate(&l->a, "r", NOPRINT);
		rotate(&l->b, "r", NOPRINT);
	}
	else if (ft_strncmp("sa", rule, 2))
		swap(&l->a, "a", NOPRINT);
	else if (ft_strncmp("sb", rule, 2))
		swap(&l->b, "b", NOPRINT);
	else if (ft_strncmp("rra", rule, 3))
		rev_rotate(&l->a, "a", NOPRINT);
	else if (ft_strncmp("rrb", rule, 3))
		rev_rotate(&l->b, "b", NOPRINT);
	else if (ft_strncmp("rrr", rule, 3))
	{
		rev_rotate(&l->a, "r", NOPRINT);
		rev_rotate(&l->b, "r", NOPRINT);
	}
	else
		error_handler(l, rule);
	free(rule);
}

void	error_handler(t_stacks *l, char *rule)
{
	ft_printf("Rule is invalid: %s\n", rule);
	list_clear(l);
	free(rule);
	exit(EXIT_FAILURE);
}
