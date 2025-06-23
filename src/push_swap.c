#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacks	*list;

	list = init_stack(argc, argv);
	if (is_sorted(list->a) && list->b == NULL)
		return (0);
	if (list->len_a == 2)
	{
		printf("%s", swap(&list->a, "a\n"));
		return (0);
	}
	else
	{
		order_stack_b(list, argc - 1);
		order_stack_a(list);
		final_order_corrector(list);
	}
	return (0);
}

void	order_stack_b(t_stacks *list, int size)
{
	while ((list->len_a > 3) && (list->len_a >= size - 2))
	{
		printf("%s\n", push(&(list->a), &(list->b), "b"));
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
