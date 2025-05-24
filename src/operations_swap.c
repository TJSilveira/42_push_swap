#include "../includes/libft.h"
#include "../includes/push_swap.h"

/* This function handles both swap a and swap b */
char	*swap(t_s **s, char *name)
{
	t_s *last_node;
	t_s *first_node;
	t_s *second_node;

	if ((*s) == NULL || (*s)->next == (*s))
		return (ft_strjoin("s",name));
	last_node = (*s)->next;
	while (last_node->next->start == 0)
		last_node = last_node->next;
	first_node = (*s);
	second_node = first_node->next;
	first_node->start = 0;
	second_node->start = 1;
	first_node->next = second_node->next;
	second_node->next = first_node;
	(*s) = second_node;
	last_node->next = second_node;
	return (ft_strjoin("s",name));
}