#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	find_cheapest(t_stacks *l, char *option)
{
	t_s *o_c;
	t_s *d_c;
	t_s *d_prev;
	int	moves_a;
	int	moves_b;

	cheapest_moves_reset(l);
	find_cheapest_aux(l, option, &o_c, &d_c, 0);
	moves_a = 0;
	while (o_c != l->a || moves_a == 0)
	{
		find_cheapest_aux(l, option, &o_c, &d_c, 1);
		moves_b = 0;
		d_prev = find_last_node(d_c);
		while (!(o_c->num <= d_prev->num && o_c->num >= d_c->num) && !(o_c->num >= d_c->num && d_c == l->max_b) && !(o_c->num <= d_prev->num && d_prev == l->min_b))
		{
			d_c = d_c->next;
			d_prev = d_prev->next;
			moves_b++;
		}
		calculate_moves(l, o_c, moves_a, moves_b);
		o_c = o_c->next;
		moves_a++;
	}
}

/* The function can be further optimized by choosing moves according to the way
   the rotation must be made. If both A and B Stack must move in the same direction,
   you can save a move by using the rr and rrr versions of the commands.*/
void	calculate_moves(t_stacks *l, t_s *a_c, int moves_a, int moves_b)
{
	if (moves_a > l->len_a / 2)
		moves_a = moves_a - l->len_a;
	if (moves_b > l->len_b / 2)
		moves_b = moves_b - l->len_b;
	// printf("Number: %i; Moves A: %i; Moves B: %i;\n", a_c->num, moves_a, moves_b);
	if ((ABS(moves_a) + ABS(moves_b)) < (ABS(l->a_moves) + ABS(l->b_moves)))
	{
		l->cheapest_node = a_c;
		l->a_moves = moves_a;
		l->b_moves = moves_b;
	}
}

void	executor(t_stacks *l)
{
	while (l->a_moves || l->b_moves)
	{
		if (0 < l->a_moves)
		{
			printf("%s\n", rotate(&l->a,"a"));
			(l->a_moves)--;
		}
		else if (0 > l->a_moves)
		{
			printf("%s\n", rev_rotate(&l->a,"a"));
			(l->a_moves)++;
		}
		if (0 < l->b_moves)
		{
			printf("%s\n", rotate(&l->b,"b"));
			l->b_moves--;
		}
		else if (0 > l->b_moves)
		{
			printf("%s\n", rev_rotate(&l->b,"b"));
			(l->b_moves)++;
		}
	}
	printf("%s\n", push(&(l->a), &(l->b), "a"));
}

void	find_cheapest_aux(t_stacks *l, char *option, t_s **o_c, t_s **d_c, int inside_loop)
{
	if (ft_strcmp(option, "a_to_b") && inside_loop == 0)
		(*o_c) = l->a;
	else if (ft_strcmp(option, "b_to_a") && inside_loop == 0)
		(*o_c) = l->b;
	else if (ft_strcmp(option, "a_to_b") && inside_loop == 1)
		(*d_c) = l->b;
	else if (ft_strcmp(option, "b_to_a") && inside_loop == 1)
		(*d_c) = l->a;
	else
	{
		ft_putstr_fd("Invalid options", 2);
		exit(EXIT_FAILURE);
	}
}