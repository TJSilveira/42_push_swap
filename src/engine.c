#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	find_cheapest(t_stacks *l)
{
	t_s *a_c;
	t_s *b_c;
	t_s *b_prev;
	int	moves_a;
	int	moves_b;

	cheapest_moves_reset(l);
	a_c = l->a;
	moves_a = 0;
	moves_b = 0;
	while (a_c != l->a || moves_a == 0)
	{
		b_c = l->b;
		moves_b = 0;
		b_prev = find_last_node(b_c);
		while (!(a_c->num <= b_prev->num && a_c->num >= b_c->num) && !(a_c->num >= b_c->num && b_c == l->max_b) && !(a_c->num <= b_c->num && b_c == l->min_b))
		{
			b_c = b_c->next;
			b_prev = b_prev->next;
			moves_b++;
		}
		calculate_moves(l, a_c, moves_a, moves_b);
		a_c = a_c->next;
		moves_a++;
	}
}

void	calculate_moves(t_stacks *l, t_s *a_c, int moves_a, int moves_b)
{
	/* maybe it is worth it to use negative numbers to represent rev rotation*/
	if (moves_a > l->len_a / 2)
		moves_a = moves_a - l->len_a;
	if (moves_b > l->len_b / 2)
		moves_b = moves_b - l->len_b;
	printf("Number: %i; Moves A: %i; Moves B: %i;\n", a_c->num, moves_a, moves_b);
	if ((ABS(moves_a) + ABS(moves_b)) < l->cheapest_moves)
	{
		l->cheapest_moves = (ABS(moves_a) + ABS(moves_b));
		l->cheapest_node = a_c;
		l->a_moves = moves_a;
		l->b_moves = moves_b;
	}
}
