#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdlib.h>

typedef struct s_s
{
	int	num;
	int	start;
	struct s_s	*next;
}	t_s;

/* sorting_algos.c */
void	radix_sort(int **array, int size);
int		ft_10power(int exp);
int		find_max(int *array, int size);
void	prefix_sum_sort(int **array, int size, int *output, int exp_max);

/* utils1.c */
void	indexator(int *array, int size);
t_s		*stack_loader(int *array, int size);
t_s		*create_node(int num, int start);
void	print_stack(t_s *first_node);

/* operations_push.c */
char	*push(t_s **origin_s, t_s **dest_s, char *name);
void	push_origin(t_s **origin_s, t_s **temp_o);
void	push_dest(t_s **origin_s, t_s **dest_s, t_s **temp_o, t_s **temp_d);

/* operations_swap.c */
char	*swap(t_s **s, char *name);

/* operations_rotate.c*/
char	*rotate(t_s **s, char *name);
char	*rev_rotate(t_s **s, char *name);

#endif
