#include "../includes/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stacks	*list;

	if (argc == 1)
		exit (EXIT_SUCCESS);
	list = init_stack(argc, argv);
	execute_rules(list);
	if (is_sorted(list->a) && list->b == NULL)
		printf("OK");
	else
		printf("KO");
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
		printf("%s", rotate(&l->a, "a"));
	else if (ft_strncmp("rb", rule, 2))
		printf("%s", rotate(&l->b, "b"));
	else if (ft_strncmp("rb", rule, 2))
	{
		printf("%s", rotate(&l->a, "r"));
		rotate(&l->b, "r");
	}
	else if (ft_strncmp("sa", rule, 2))
		printf("%s", swap(&l->a, "a"));
	else if (ft_strncmp("sb", rule, 2))
		printf("%s", swap(&l->b, "b"));
	else if (ft_strncmp("rra", rule, 3))
		printf("%s", rev_rotate(&l->a, "a"));
	else if (ft_strncmp("rrb", rule, 3))
		printf("%s", rev_rotate(&l->b, "b"));
	else if (ft_strncmp("rrr", rule, 3))
	{
		printf("%s", rev_rotate(&l->a, "r"));
		rev_rotate(&l->b, "r");
	}
	else
		error_handler(l, rule);
	free(rule);
}

void	error_handler(t_stacks *l, char *rule)
{
	printf("Rule is invalid: %s", rule);
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
