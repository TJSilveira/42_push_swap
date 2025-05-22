#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	find_cheapest(t_stacks *l, char *option)
{
	t_s *o_c;

	cheapest_moves_reset(l);
	find_cheapest_aux(l, option, &o_c, 0);
	if (ft_strcmp(option, "a_to_b") == 0)
		find_cheapest_loop_a_to_b(l, option, &o_c);
	else if (ft_strcmp(option, "b_to_a") == 0)
		find_cheapest_loop_b_to_a(l, option, &o_c);
}

void	find_cheapest_loop_a_to_b(t_stacks *l, char *option, t_s **o_c)
{
	t_s *d_c;
	t_s *d_prev;
	int	moves_o;
	int	moves_d;

	moves_o = 0;
	while ((*o_c) != l->a || moves_o == 0)
	{
		find_cheapest_aux(l, option, &d_c, 1);
		moves_d = 0;
		d_prev = find_last_node(d_c);
		while (!((*o_c)->num <= d_prev->num && (*o_c)->num >= d_c->num) && !((*o_c)->num >= d_c->num && d_c == l->max_b) && !((*o_c)->num <= d_prev->num && d_prev == l->min_b))
		{
			d_c = d_c->next;
			d_prev = d_prev->next;
			moves_d++;
		}
		if (ft_strcmp("a_to_b", option) == 0)
			calculate_moves(l, (*o_c), moves_o, moves_d);
		else
			calculate_moves(l, (*o_c), moves_d, moves_o);
		(*o_c) = (*o_c)->next;
		moves_o++;
	}
}

void	find_cheapest_loop_b_to_a(t_stacks *l, char *option, t_s **o_c)
{
	t_s *d_c;
	t_s *d_prev;
	int	moves_o;
	int	moves_d;

	moves_o = 0;
	while ((*o_c) != l->b || moves_o == 0)
	{
		find_cheapest_aux(l, option, &d_c, 1);
		moves_d = 0;
		d_prev = find_last_node(d_c);
		while (!((*o_c)->num <= d_prev->num && (*o_c)->num >= d_c->num) && !((*o_c)->num >= d_c->num && d_c == l->max_a) && !((*o_c)->num <= d_prev->num && d_prev == l->min_a))
		{
			d_c = d_c->next;
			d_prev = d_prev->next;
			moves_d++;
		}
		if (ft_strcmp("a_to_b", option) == 0)
			calculate_moves(l, (*o_c), moves_o, moves_d);
		else
			calculate_moves(l, (*o_c), moves_d, moves_o);
		(*o_c) = (*o_c)->next;
		moves_o++;
	}
}

/* The function can be further optimized by choosing moves according to the way
   the rotation must be made. If both A and B Stack must move in the same direction,
   you can save a move by using the rr and rrr versions of the commands.*/
void	calculate_moves(t_stacks *l, t_s *o_c, int moves_a, int moves_b)
{
	if (moves_a > l->len_a / 2)
		moves_a = moves_a - l->len_a;
	if (moves_b > l->len_b / 2)
		moves_b = moves_b - l->len_b;
	// printf("Number: %i; Moves A: %i; Moves B: %i;\n", o_c->num, moves_a, moves_b);
	if ((ABS(moves_a) + ABS(moves_b)) < (ABS(l->a_moves) + ABS(l->b_moves)))
	{
		l->cheapest_node = o_c;
		l->a_moves = moves_a;
		l->b_moves = moves_b;
	}
}

void	executor(t_stacks *l, char *option)
{
	while (l->a_moves || l->b_moves)
	{
		if (0 < l->a_moves && (l->a_moves)--)
			printf("%s\n", rotate(&l->a,"a"));
		else if (0 > l->a_moves && (l->a_moves)++)
			printf("%s\n", rev_rotate(&l->a,"a"));
		if (0 < l->b_moves && (l->b_moves)--)
			printf("%s\n", rotate(&l->b,"b"));
		else if (0 > l->b_moves && (l->b_moves)++)
			printf("%s\n", rev_rotate(&l->b,"b"));
	}
	if (ft_strcmp("a_to_b", option) == 0)
		printf("%s\n", push(&(l->a), &(l->b), "a"));
	else if (ft_strcmp("b_to_a", option) == 0)
		printf("%s\n", push(&(l->b), &(l->a), "b"));
}

void	find_cheapest_aux(t_stacks *l, char *option, t_s **stack, int inside_loop)
{
	if (ft_strcmp(option, "a_to_b") == 0 && inside_loop == 0)
		(*stack) = l->a;
	else if (ft_strcmp(option, "b_to_a") == 0 && inside_loop == 0)
		(*stack) = l->b;
	else if (ft_strcmp(option, "a_to_b") == 0 && inside_loop == 1)
		(*stack) = l->b;
	else if (ft_strcmp(option, "b_to_a") == 0 && inside_loop == 1)
		(*stack) = l->a;
	else
	{
		ft_putstr_fd("Invalid options", 2);
		exit(EXIT_FAILURE);
	}
}
/*
void	sort_3_elem (t_stacks *l)
{

}*/