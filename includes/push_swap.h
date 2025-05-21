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
	int	len_a;
	int	len_b;
	t_s	*cheapest_node;
	int	cheapest_moves;
	int	a_moves;
	int	b_moves;
}	t_stacks;

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
void	cheapest_moves_reset(t_stacks *list);
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
void	find_cheapest(t_stacks *l);
void	calculate_moves(t_stacks *l, t_s *a_c, int moves_a, int moves_b);

#endif
