#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	find_cheapest(t_stacks *l, char *option, int size)
{
	t_s	*o_c;

	cheapest_moves_reset(l, option);
	find_cheapest_aux(l, option, &o_c, 0);
	if (ft_strcmp(option, "a_to_b") == 0)
		find_ch_loop_a_to_b(l, option, &o_c, size);
	else if (ft_strcmp(option, "b_to_a") == 0)
		find_ch_loop_b_to_a(l, option, &o_c);
}

void	find_ch_loop_a_to_b(t_stacks *l, char *option, t_s **o_c, int size)
{
	t_s	*d_c;
	t_s	*d_prev;
	int	moves[2];

	moves[0] = 0;
	while ((*o_c) != l->a || moves[0] == 0)
	{
		find_cheapest_aux(l, option, &d_c, 1);
		moves[1] = 0;
		d_prev = find_last_node(d_c);
		while (!((*o_c)->num <= d_prev->num && (*o_c)->num >= d_c->num) && \
			!((*o_c)->num >= d_c->num && d_c == l->max_b) && \
			!((*o_c)->num <= d_prev->num && d_prev == l->min_b))
		{
			d_c = d_c->next;
			d_prev = d_prev->next;
			moves[1]++;
		}
		if (ft_strcmp("a_to_b", option) == 0)
			calculate_moves(l, (*o_c), moves, size);
		else
			calculate_moves(l, (*o_c), moves, size);
		(*o_c) = (*o_c)->next;
		moves[0]++;
	}
}

void	find_ch_loop_b_to_a(t_stacks *l, char *option, t_s **o_c)
{
	t_s *d_c;
	t_s *d_prev;
	int	moves[2];

	moves[0] = 0;
	while ((*o_c) != l->b || moves[0] == 0)
	{
		find_cheapest_aux(l, option, &d_c, 1);
		moves[1] = 0;
		d_prev = find_last_node(d_c);
		while (!((*o_c)->num >= d_prev->num && (*o_c)->num <= d_c->num) && 
			!((*o_c)->num <= d_c->num && d_c == l->min_a) && \
			!((*o_c)->num >= d_prev->num && d_prev == l->max_a))
		{
			d_c = d_c->next;
			d_prev = d_prev->next;
			moves[1]++;
		}
		if (ft_strcmp("a_to_b", option) == 0)
			calculate_moves(l, (*o_c), moves, 0);
		else
			calculate_moves(l, (*o_c), moves, 0);
		(*o_c) = (*o_c)->next;
		moves[0]++;
	}
}

/* The function can be further optimized by choosing moves according to 
	the way the rotation must be made. If both A and B Stack must move in
	the same direction, you can save a move by using the rr and rrr
	versions of the commands.*/
void	calculate_moves(t_stacks *l, t_s *o_c, int moves[2], int s)
{
	int	p1;
	int	p2;

	if (o_c->num > (1 * s) && s)
		p1 = 0;
	else
		p1 = 0;
	if (!l->cheapest_node && l->cheapest_node->num > (1 * s) && s)
		p2 = 0;
	else
		p2 = 0;
	if (moves[0] > l->len_a / 2)
		moves[0] = moves[0] - l->len_a;
	if (moves[1] > l->len_b / 2)
		moves[1] = moves[1] - l->len_b;
	printf("Number: %i; Moves A: %i; Moves B: %i;\n", o_c->num, moves[0], moves[1]);
	if (min_move_finder(moves[0], moves[1]) + p1 \
	< min_move_finder(l->a_moves, l->b_moves) + p2)
	{
		l->cheapest_node = o_c;
		l->a_moves = moves[0];
		l->b_moves = moves[1];
	}
}

int	min_move_finder(int moves_a, int moves_b)
{
	if (moves_a > 0 && moves_b > 0)
	{
		if (moves_a > moves_b)
			return (ABS(moves_a));
		else
			return (ABS(moves_b));
	}
	else if (moves_a < 0 && moves_b < 0)
	{
		if (moves_a < moves_b)
			return (ABS(moves_a));
		else
			return (ABS(moves_b));
	}
	else
		return ((ABS(moves_a) + ABS(moves_b)));	
}

void	executor(t_stacks *l, char *option)
{
	while ((l->a_moves > 0 && l->b_moves > 0) || (l->a_moves < 0 && l->b_moves < 0))
	{
		if (0 < l->a_moves && 0 < l->b_moves)
		{
			printf("%s\n", rotate(&l->a,"r"));
			rotate(&l->b,"r");
			(l->a_moves)--;
			(l->b_moves)--;
		}
		else if (0 > l->a_moves && 0 > l->b_moves)
		{
			printf("%s\n", rev_rotate(&l->a,"r"));
			rev_rotate(&l->b,"r");
			(l->a_moves)++;
			(l->b_moves)++;
		}
	}
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
		printf("%s\n", push(&(l->a), &(l->b), "b"));
	else if (ft_strcmp("b_to_a", option) == 0)
		printf("%s\n", push(&(l->b), &(l->a), "a"));
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

void	sort_3_elem(t_stacks *l)
{
	if (l->a == l->max_a)
		printf("%s", rotate(&l->a, "a\n"));
	else if (l->a->next == l->max_a)
		printf("%s", rev_rotate(&l->a, "a\n"));
	if (l->a != l->min_a)
		printf("%s", swap(&l->a, "a\n"));	 
}

void	final_order_corrector(t_stacks *l)
{
	t_s	*find;

	find = l->a;
	l->a_moves = 0;
	l->b_moves = 0;
	l->len_a = stack_length(l->a);
	update_maxmin(l);
	while (find != l->min_a)
	{
		l->a_moves++;
		find = find->next;
	}
	if (l->a_moves > l->len_a / 2)
		l->a_moves = l->a_moves - l->len_a;
	while (1)
	{
		if (is_sorted(l->a))
			break;
		executor(l, "Nothing");
	}
}