#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	indexator(int *array, int size)
{
	int	order;
	int	i;
	int	j;
	int	*output;

	i = size;
	j = 0;
	output = malloc(sizeof(int) * size);
	if (!output)
		exit(1);
	while (--i >= 0)
	{
		j = size - 1;
		order = 0;
		while (j >= 0)
		{
			if (array[i] > array[j] /*|| ((array[i] == array[j]) && (i > j))*/)
				order++;
			j--;
		}
		output[i] = order;
	}
	i = -1;
	while (++i < size)
		array[i] = output[i];
	free(output);
}

t_s	*stack_loader(int *array, int size)
{
	int	i;
	t_s *current_node;
	t_s *first_node;

	i = 0;
	if (size == 1)
		return (create_node(array[0], 1));
	if (i == 0)
		first_node = create_node(array[i], 1);
	current_node = first_node;
	while (++i < size - 1)
	{
		current_node->next = create_node(array[i],0);
		current_node = current_node->next;
	}
	if (i == size - 1)
	{
		current_node->next = create_node(array[i],0);
		current_node->next->next = first_node;
	}
	return (first_node);
}

t_s	*create_node(int num, int start)
{
	t_s	*node;

	node = malloc(sizeof(t_s));
	if (!node)
		exit (1);
	node->num = num;
	node->start = start;
	node->next = node;
	return (node);
}

void	print_stack(t_s *first_node)
{
	ft_putstr_fd("This is the current stack:\n", 1);
	if (first_node == NULL)
	{
		ft_putstr_fd("Empty Stack\n", 1);
		return ;
	}
	ft_putnbr_fd(first_node->num, 1);
	ft_putstr_fd("\n", 1);
	if (first_node->next == first_node)
		return ;
	first_node = first_node->next;
	while (first_node->start == 0)
	{
		ft_putnbr_fd(first_node->num, 1);
		ft_putstr_fd("\n", 1);
		first_node = first_node->next;
	}
}

int	is_sorted(t_s *s)
{
	if (s->next == s || s == NULL)
		return (1);
	s = s->next;
	while (s->next->start == 0)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	return (1);
}