#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_stacks	*list_loader(t_s *s_a, t_s *s_b)
{
	t_stacks	*list;

	list = malloc(sizeof(t_stacks));
	list->a = s_a;
	list->b = s_b;
	list->len_a = stack_length(list->a);
	list->len_b = stack_length(list->b);
	cheapest_moves_reset(list, "a_to_b");
	return (list);
}

void	cheapest_moves_reset(t_stacks *list, char *option)
{
	if (ft_strcmp("a_to_b", option) == 0)
		list->cheapest_node = list->a;
	else
		list->cheapest_node = list->b;
	list->a_moves = 9000;
	list->b_moves = -9000;
}

void	update_maxmin(t_stacks *list)
{
	t_s	*b_cur;

	if (!list)
		return ;
	if (list->b)
	{
		b_cur = list->b;
		list->min_b = b_cur;
		list->max_b = b_cur;
		b_cur = b_cur->next;
		while (b_cur != list->b)
		{
			if (b_cur->num < list->min_b->num)
				list->min_b = b_cur;
			if (b_cur->num > list->max_b->num)
				list->max_b = b_cur;
			b_cur = b_cur->next;
		}
	}
	update_maxmin_aux(list);
}

void	update_maxmin_aux(t_stacks *list)
{
	t_s	*a_cur;

	if (list->a)
	{
		a_cur = list->a;
		list->min_a = a_cur;
		list->max_a = a_cur;
		a_cur = a_cur->next;
		while (a_cur != list->a)
		{
			if (a_cur->num < list->min_a->num)
				list->min_a = a_cur;
			if (a_cur->num > list->max_a->num)
				list->max_a = a_cur;
			a_cur = a_cur->next;
		}
	}
}

t_s	*find_last_node(t_s *first)
{
	t_s	*last;

	last = first;
	while (last->next != first)
		last = last->next;
	return (last);
}
