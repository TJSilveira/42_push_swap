#include "../includes/libft.h"
#include "../includes/push_swap.h"

/* This function handles both push a and push b */
char	*push(t_s **origin_s, t_s **dest_s, char *name)
{
	t_s	*to_push;

	if (*origin_s == NULL)
		return (ft_strjoin("p", name));
	to_push = NULL;
	push_origin(origin_s, &to_push);
	push_dest(&to_push, dest_s);
	return (ft_strjoin("p", name));
}

/* This function removes the pushed element from origin stack*/
void	push_origin(t_s **origin_s, t_s **to_push)
{
	t_s	*last;

	if ((*origin_s)->next == (*origin_s))
	{
		(*to_push) = (*origin_s);
		(*origin_s) = NULL;
	}
	else
	{
		(*to_push) = (*origin_s);
		(*origin_s) = (*origin_s)->next;
		(*origin_s)->start = 1;
		last = (*origin_s);
		while (last->next != (*to_push))
			last = last->next;
		last->next = (*origin_s);
	}
}

/* This function adds the pushed element from destination stack*/
void	push_dest(t_s **to_push, t_s **dest_s)
{
	t_s	*last;

	if ((*dest_s) == NULL)
	{
		(*dest_s) = (*to_push);
		(*dest_s)->next = (*dest_s);
		(*dest_s)->start = 1;
	}
	else
	{
		last = *dest_s;
		while (last->next != (*dest_s))
			last = last->next;
		last->next = (*to_push);
		(*to_push)->next = (*dest_s);
		(*dest_s)->start = 0;
		(*dest_s) = (*to_push);
		(*to_push)->start = 1;
	}
}
