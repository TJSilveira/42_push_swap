#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	find_cheapest(t_stacks *l)
{
	t_s *a_c;
	t_s *b_c;
	int	moves_a;
	int	moves_b;

	cheapest_moves_reset(l);
	a_c = l->a;
	moves_a = 0;
	moves_b = 0;
	while (a_c != l->a || moves_a == 0)
	{
		b_c = l->b;
		printf("This is a candidate: %i\n", a_c->num);
		while (!((a_c->num <= b_c->num) && (a_c->num >= b_c->next->num)) && !(a_c->num >= b_c->num && b_c == l->max_b) && !(a_c->num <= b_c->num && b_c == l->min_b))
		{
			// printf("This is b candidate: %i\n", b_c->num);
			b_c = b_c->next;
			moves_b++;
			if (moves_b > l->len_b)
			{
				printf("It broke\n");
				break;
			}
		}
		moves_b++;
		/* maybe it is worth it to use negative numbers to represent rev rotation*/
		if (moves_b > l->len_b / 2)
			moves_b = l->len_b - moves_b;
		if ((moves_a + moves_b) < l->cheapest_moves)
		{
			l->cheapest_moves = (moves_a + moves_b);
			l->cheapest_node = a_c;
		}
		printf("This is the cheapest: %i and this are how many moves it takes: %i\n", l->cheapest_node->num, l->cheapest_moves);
		a_c = a_c->next;
		moves_a++;
	}
}