#include "../includes/push_swap.h"

void	find_cheapest(t_stacks *l, char *option)
{
	t_s	*o_c;

	cheapest_moves_reset(l, option);
	find_cheapest_aux(l, option, &o_c, 0);
	if (ft_strncmp(option, "a_to_b", 6) == 0)
		find_cheapest_loop_a_to_b(l, option, &o_c);
	else if (ft_strncmp(option, "b_to_a", 6) == 0)
		find_cheapest_loop_b_to_a(l, option, &o_c);
}

void	find_cheapest_aux2(t_s **d_c, t_s **d_prev, int *moves_d)
{
	(*d_c) = (*d_c)->next;
	(*d_prev) = (*d_prev)->next;
	(*moves_d)++;
}

void	find_cheapest_loop_a_to_b(t_stacks *l, char *option, t_s **o_c)
{
	t_s	*d_c;
	t_s	*d_prev;
	int	moves_o;
	int	moves_d;

	moves_o = 0;
	while ((*o_c) != l->a || moves_o == 0)
	{
		find_cheapest_aux(l, option, &d_c, 1);
		moves_d = 0;
		d_prev = find_last_node(d_c);
		while (!((*o_c)->num <= d_prev->num && (*o_c)->num >= d_c->num)
			&& !((*o_c)->num >= d_c->num && d_c == l->max_b)
			&& !((*o_c)->num <= d_prev->num && d_prev == l->min_b))
			find_cheapest_aux2(&d_c, &d_prev, &moves_d);
		if (ft_strncmp("a_to_b", option, 6) == 0)
			calculate_moves(l, (*o_c), moves_o, moves_d);
		else
			calculate_moves(l, (*o_c), moves_d, moves_o);
		(*o_c) = (*o_c)->next;
		moves_o++;
	}
}

void	find_cheapest_loop_b_to_a(t_stacks *l, char *option, t_s **o_c)
{
	t_s	*d_c;
	t_s	*d_prev;
	int	moves_o;
	int	moves_d;

	moves_o = 0;
	while ((*o_c) != l->b || moves_o == 0)
	{
		find_cheapest_aux(l, option, &d_c, 1);
		moves_d = 0;
		d_prev = find_last_node(d_c);
		while (!((*o_c)->num >= d_prev->num && (*o_c)->num <= d_c->num)
			&& !((*o_c)->num <= d_c->num && d_c == l->min_a)
			&& !((*o_c)->num >= d_prev->num && d_prev == l->max_a))
			find_cheapest_aux2(&d_c, &d_prev, &moves_d);
		if (ft_strncmp("a_to_b", option, 6) == 0)
			calculate_moves(l, (*o_c), moves_o, moves_d);
		else
			calculate_moves(l, (*o_c), moves_d, moves_o);
		(*o_c) = (*o_c)->next;
		moves_o++;
	}
}

/* The function can be further optimized by choosing moves according to the way
   the rotation must be made. If both A and B Stack must move in the same 
   direction, you can save a move by using the rr and rrr versions of
   the commands.*/
void	calculate_moves(t_stacks *l, t_s *o_c, int moves_a, int moves_b)
{
	if (moves_a > l->len_a / 2)
		moves_a = moves_a - l->len_a;
	if (moves_b > l->len_b / 2)
		moves_b = moves_b - l->len_b;
	if (min_move_finder(moves_a, moves_b)
		< min_move_finder(l->a_moves, l->b_moves))
	{
		l->cheapest_node = o_c;
		l->a_moves = moves_a;
		l->b_moves = moves_b;
	}
}
