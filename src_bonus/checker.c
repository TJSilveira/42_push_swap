#include "../includes/libft.h"
#include "../includes/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stacks *list;
	
	if (argc == 1)
		exit (EXIT_SUCCESS);
	list = init_stack(argc, argv);
	execute_rules(list);
	if (is_sorted(list->a) && list->b == NULL)
		printf("OK\n");
	else
		printf("KO\n");
	release_stacks(list);
	return (0);
}

void	execute_rules(t_stacks *l)
{
	char *rule;

	rule = get_next_line(0);
	while (rule)
	{
		operation_redirect(l, rule);
		rule = get_next_line(0);
	}
}

void	operation_redirect(t_stacks *l,char *rule)
{
	int len = ft_strlen(rule);
	if (len > 0 && rule[len - 1] == '\n')
		rule[len - 1] = '\0';
	if (ft_strcmp("ra",rule) == 0)
		rotate(&l->a, "a");
	else if (ft_strcmp("rb",rule) == 0)
		rotate(&l->b, "b");
	else if (ft_strcmp("rr",rule) == 0)
	{
		rotate(&l->a, "r");
		rotate(&l->b, "r");
	}
	else if (ft_strcmp("sa",rule) == 0)
		swap(&l->a, "a");
	else if (ft_strcmp("sb",rule) == 0)
		swap(&l->b, "b");
	else if (ft_strcmp("rra",rule) == 0)
		rev_rotate(&l->a, "a");
	else if (ft_strcmp("rrb",rule) == 0)
		rev_rotate(&l->b, "b");
	else if (ft_strcmp("rrr",rule) == 0)
	{
		rev_rotate(&l->a, "r");
		rev_rotate(&l->b, "r");
	}
	else if(ft_strcmp("pa",rule) == 0)
		push(&l->b,&l->a,"b_to_a");
	else if(ft_strcmp("pb",rule) == 0)
		push(&l->a,&l->b,"a_to_b");
	else
		error_handler(l, rule);
	free(rule);
}

void	error_handler(t_stacks *l, char *rule)
{
	printf("Rule is invalid: %s\n", rule);
	release_stacks(l);
	exit(EXIT_FAILURE);
}

void	release_stacks(t_stacks *l)
{
	t_s	*next;
	t_s	*start;
	t_s	*current;

	if (l->a)
	{
		start = l->a;
		current = l->a;
		while (current && current->next != start)
		{
			next = current->next;
			free(current);
			current = next;
		}
		if (current)
			free(current);
	}
	if (l->b)
	{
		start = l->b;
		current = l->b;
		while (current && current->next != start)
		{
			next = current->next;
			free(current);
			current = next;
		}
		if (current)
			free(current);
	}
	free(l);
}