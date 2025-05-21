#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_stacks	*list_loader(t_s *s_a, t_s *s_b)
{
	t_stacks *list;
	
	list = malloc(sizeof(t_stacks));
	list->a = s_a;
	list->b = s_b;
	list->len_a = stack_length(list->a);
	list->len_b = stack_length(list->b);
	list->cheapest_moves = 9000;
	return (list);
}

void	cheapest_moves_reset(t_stacks *list)
{
	list->cheapest_moves = 9000;
	list->a_moves = 9000;
	list->b_moves = 9000;
}

void	update_maxmin(t_stacks *list)
{
	t_s *b_cur;

	if (!list || !list->a || !list->b)
		return ;
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

t_s	*find_last_node(t_s *first)
{
    t_s *last;

	last = first;
    while (last->next != first)
        last = last->next;
    return last;
}