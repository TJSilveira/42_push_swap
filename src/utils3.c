#include "../includes/push_swap.h"

void	malloc_init(int **array, int size)
{
	*array = malloc(sizeof(int) * size);
	if (!(*array))
		exit(1);
}

void	check_repeated(int *array, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				ft_putstr_fd("Error\n", 2);
				free(array);
				exit(1);
			}
			j++;
		}
	}
}

void	print_move(char *action, char *name, int option)
{
	if (option == PRINT)
		ft_printf("%s%c\n", action, *name);
}

void	list_clear(t_stacks *list)
{
	t_s	*last;

	last = find_last_node(list->a);
	stack_clear(list->a, last);
	last = find_last_node(list->b);
	stack_clear(list->b, last);
	free(list);
}

void	stack_clear(t_s *stack, t_s *last)
{
	t_s	*temp;

	if (!stack)
		stack = NULL;
	else if (stack == last)
		free(stack);
	else
	{
		while (stack != last)
		{
			if (stack->next == NULL)
			{
				temp = stack;
				free(temp);
				temp = NULL;
				break ;
			}
			temp = stack;
			stack = stack->next;
			free(temp);
			temp = NULL;
		}
		free(stack);
	}
}
