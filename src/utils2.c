#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_stacks	*list_loader(t_s *s_a, t_s *s_b)
{
	t_stacks *list;
	
	list = malloc(sizeof(t_stacks));
	list->a = s_a;
	list->b = s_b;
	return (list);
}