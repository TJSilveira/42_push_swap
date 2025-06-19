#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>

typedef struct s_s
{
	int	num;
	int	start;
	int	min;
	int	max;
	struct s_s	*next;
}	t_s;

typedef struct s_stacks
{
	t_s	*a;
	t_s	*b;
	t_s	*min_b;
	t_s	*max_b;
	t_s	*min_a;
	t_s	*max_a;
	int	len_a;
	int	len_b;
	t_s	*cheapest_node;
	int	a_moves;
	int	b_moves;
}	t_stacks;

/* push_swap.c*/
void	order_stack_b(t_stacks *list, int size);
void	order_stack_a(t_stacks *list);

/* sorting_algos.c */
void	radix_sort(int **array, int size);
int		ft_10power(int exp);
int		find_max(int *array, int size);
void	prefix_sum_sort(int **array, int size, int *output, int exp_max);

/* utils1.c */
void	indexator(int *array, int size);
t_s		*stack_loader(int *array, int size);
t_s		*create_node(int num, int start);
int		is_sorted(t_s *s);
int		stack_length(t_s *s_a);

/* utils2.c */
t_stacks	*list_loader(t_s *s_a, t_s *s_b);
void	cheapest_moves_reset(t_stacks *list, char *option);
void	update_maxmin(t_stacks *list);
t_s		*find_last_node(t_s *first);

/* operations_push.c */
char	*push(t_s **origin_s, t_s **dest_s, char *name);
void	push_origin(t_s **origin_s, t_s **to_push);
void	push_dest(t_s **to_push, t_s **dest_s);

/* operations_swap.c */
char	*swap(t_s **s, char *name);

/* operations_rotate.c*/
char	*rotate(t_s **s, char *name);
char	*rev_rotate(t_s **s, char *name);

/* print_stacks.c*/
void	print_stacks(t_s *s_a, t_s *s_b, int size);

/* engine.c */
void	find_cheapest(t_stacks *l, char *option);
void	calculate_moves(t_stacks *l, t_s *o_c, int moves_a, int moves_b);
void	executor(t_stacks *l, char *option);
void	find_cheapest_aux(t_stacks *l, char *option, t_s **stack, int inside_loop);
void	find_cheapest_loop_a_to_b(t_stacks *l, char *option, t_s **o_c);
void	find_cheapest_loop_b_to_a(t_stacks *l, char *option, t_s **o_c);
void	sort_3_elem(t_stacks *l);
void	final_order_corrector(t_stacks *l);
int		min_move_finder(int moves_a, int moves_b);

/* init_stack.c */
t_stacks	*init_stack(int argc, char *argv[]);
int	is_int(char *num);
int	*data_loader(int argc, char *argv[]);

#endif
