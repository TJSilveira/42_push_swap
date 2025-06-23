#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include "push_swap.h"

/* checker.c */
void	execute_rules(t_stacks *l);
void	operation_redirect(t_stacks *l, char *rule);
void	error_handler(t_stacks *l, char *rule);
void	release_stacks(t_stacks *l);

#endif
