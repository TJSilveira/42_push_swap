#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	is_int(char *num)
{
	long int	final_num;
	int			s;

	final_num = 0;
	s = 0;
	if (*(num++) == '-')
		s++;
	while (*num)
	{
		if (*num < '0' || *num > '9')
			return (0);
		final_num = final_num * 10 + *num - '0';
		if ((final_num > 2147483648 && s) || (final_num > INT_MAX && !s))
			return (0);
		num++;
	}
	return (1);
}

int	*data_loader(int argc, char *argv[])
{
	int *temp;

	temp = malloc(sizeof(int) * (argc - 1));
	while (--argc > 0)
	{
		if (!is_int(argv[argc]))
		{
			return (NULL);
			free(temp);
		}
		temp[argc - 1] = ft_atoi(argv[argc]);
	}
	return (temp);
}

int main(int argc, char *argv[])
{
	int	*arr_a;
	t_s	*s_a;
	t_s	*s_b;
	t_stacks *list;

	arr_a = data_loader(argc, argv);
	if (!arr_a)
	{
		ft_putstr_fd("Error importing the array\n", 2);
		return (1);
	}

	/* TODO: Bundle up all the setup under the list loader function*/
	printf("After the indexator\n");
	indexator(arr_a, argc - 1);
	s_a = stack_loader(arr_a, argc - 1);
	s_b = NULL;
	list = list_loader(s_a, s_b);
	free(arr_a);

	print_stacks(list->a, list->b, argc -1);
	/* tests for input creation, operations and display */
	printf("Is it sorted? %i\n", is_sorted(s_a));

	push(&(list->a), &(list->b), "a");
	printf("After pa\n");
	print_stacks(list->a, list->b, argc -1);
	
	push(&(list->a), &(list->b), "a");
	printf("After pa\n");
	print_stacks(list->a, list->b, argc -1);

	push(&(list->a), &(list->b), "a");
	printf("After pa\n");
	print_stacks(list->a, list->b, argc -1);

	push(&(list->a), &(list->b), "a");
	printf("After pa\n");
	print_stacks(list->a, list->b, argc -1);
	
	list->len_a = stack_length(list->a);
	list->len_b = stack_length(list->b);
	update_maxmin(list);
	find_cheapest(list, "a_to_b");
	printf("The cheapest is %i with %i moves\n", list->cheapest_node->num, ABS(list->a_moves)+ABS(list->b_moves));
	executor(list, "a_to_b");
	print_stacks(list->a, list->b, argc -1);

	list->len_a = stack_length(list->a);
	list->len_b = stack_length(list->b);
	update_maxmin(list);
	find_cheapest(list, "a_to_b");
	printf("The cheapest is %i with %i moves\n", list->cheapest_node->num, ABS(list->a_moves)+ABS(list->b_moves));
	executor(list, "a_to_b");
	print_stacks(list->a, list->b, argc -1);

	list->len_a = stack_length(list->a);
	list->len_b = stack_length(list->b);
	update_maxmin(list);
	find_cheapest(list, "a_to_b");
	printf("The cheapest is %i with %i moves\n", list->cheapest_node->num, ABS(list->a_moves)+ABS(list->b_moves));
	executor(list, "a_to_b");
	print_stacks(list->a, list->b, argc -1);

	printf("This should send from B to A\n");
	list->len_a = stack_length(list->a);
	list->len_b = stack_length(list->b);
	update_maxmin(list);
	find_cheapest(list, "b_to_a");
	printf("The cheapest is %i with %i moves\n", list->cheapest_node->num, ABS(list->a_moves)+ABS(list->b_moves));
	executor(list, "b_to_a");
	print_stacks(list->a, list->b, argc -1);

	return 0;
}
