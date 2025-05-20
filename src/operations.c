#include "../includes/libft.h"
#include "../includes/push_swap.h"

char	*push(t_s **origin_s, t_s **dest_s, char *name)
{
	t_s	*temp_o;
	t_s	*temp_d;

	if (*origin_s == NULL)
		return (ft_strjoin("p",name));
	else if ((*origin_s)->next == (*origin_s))
		temp_o = NULL;
	else
	{
		temp_o = (*origin_s)->next;
		temp_o->start = 1; 
		while (temp_o->next != (*origin_s))
			temp_o = temp_o->next;
		temp_o->next = temp_o->next->next;
		temp_o = temp_o->next;
	}
	if ((*dest_s) == NULL)
	{
		(*dest_s) = (*origin_s);
		(*dest_s)->next = (*dest_s);
		(*origin_s) = temp_o;
	}
	else if ((*dest_s)->next == (*dest_s))
	{
		temp_d = *dest_s;
		temp_d->next = (*origin_s);
		(*origin_s)->next = temp_d;
		temp_d->start = 0;
		(*dest_s) = (*origin_s);
		(*origin_s) = temp_o;
	}
	else
	{
		temp_d = *dest_s;
		while (temp_d->next != (*dest_s))
			temp_d = temp_d->next;
		temp_d->next = (*origin_s);
		(*origin_s)->next = (*dest_s);
		(*dest_s)->start = 0;
		(*dest_s) = (*origin_s);
		(*origin_s) = temp_o;
	}
	printf("Addresses: %p, %p\n", (*origin_s), (*dest_s));
	return (ft_strjoin("p",name));
}