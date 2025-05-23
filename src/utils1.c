#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_s	*stack_loader(int *array, int size)
{
	int	i;
	t_s	*current_node;
	t_s	*first_node;

	i = 0;
	if (size == 1)
		return (create_node(array[0], 1));
	if (i == 0)
		first_node = create_node(array[i], 1);
	current_node = first_node;
	while (++i < size - 1)
	{
		current_node->next = create_node(array[i], 0);
		current_node = current_node->next;
	}
	if (i == size - 1)
	{
		current_node->next = create_node(array[i], 0);
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

int	is_sorted(t_s *s)
{
	t_s	*start;

	if (s->next == s || s == NULL)
		return (1);
	start = s;
	while (s->next != start)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	return (1);
}

int	stack_length(t_s *s_a)
{
	int	counter;
	t_s	*current;

	counter = 0;
	if (!s_a)
		return (counter);
	current = s_a;
	while (current != s_a || counter == 0)
	{
		counter++;
		current = current->next;
	}
	return (counter);
}
