#include "../includes/push_swap.h"

/* This function handles both swap a and swap b */
char	*rotate(t_s **s, char *name)
{
	t_s	*second_node;

	if ((*s) == NULL || (*s)->next == (*s))
		return (ft_strjoin("r", name));
	second_node = (*s)->next;
	second_node->start = 1;
	(*s)->start = 0;
	(*s) = second_node;
	return (ft_strjoin("r", name));
}

char	*rev_rotate(t_s **s, char *name)
{
	t_s	*last_node;

	if ((*s) == NULL || (*s)->next == (*s))
		return (ft_strjoin("s", name));
	last_node = (*s)->next;
	while (last_node->next->start == 0)
		last_node = last_node->next;
	last_node->start = 1;
	(*s)->start = 0;
	(*s) = last_node;
	return (ft_strjoin("rr", name));
}
