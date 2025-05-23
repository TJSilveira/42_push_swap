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
	indexator(arr_a, argc - 1);
	s_a = stack_loader(arr_a, argc - 1);
	s_b = NULL;
	list = list_loader(s_a, s_b);
	free(arr_a);

	if (is_sorted(list->a) && list->b == NULL)
		return 0;
	if (list->len_a == 2)
	{
		printf("%s", swap(&list->a, "a\n"));
		return (0);
	}
	else
	{
		while ((list->len_a > 3) && (list->len_a >= argc - 3))
		{
			printf("%s\n", push(&(list->a), &(list->b), "b"));
			list->len_a = stack_length(list->a);
		}
		while (1)
		{
			if (is_sorted(list->a) && list->b == NULL)
				return 0;
			list->len_a = stack_length(list->a);
			list->len_b = stack_length(list->b);
			update_maxmin(list);
			if (list->len_a == 3)
			{
				sort_3_elem(list);
				break;
			}
			find_cheapest(list, "a_to_b", argc - 1);
			executor(list, "a_to_b");
		}
		while (1)
		{
			if ((is_sorted(list->a) && list->b == NULL) || list->b == NULL)
				break;
			list->len_a = stack_length(list->a);
			list->len_b = stack_length(list->b);
			update_maxmin(list);
			find_cheapest(list, "b_to_a", argc - 1);
			executor(list, "b_to_a");
		}
		final_order_corrector(list);
	}
	return 0;
}
