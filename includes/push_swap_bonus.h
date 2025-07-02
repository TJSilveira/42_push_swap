/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 09:09:01 by tsilveir          #+#    #+#             */
/*   Updated: 2025/07/02 09:09:04 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include "../libft/libft.h"
# include "push_swap.h"

/* checker.c */
void	execute_rules(t_stacks *l);
void	operation_redirect(t_stacks *l, char *rule);
void	error_handler(t_stacks *l, char *rule);
void	combine_rotate(t_stacks *l, char *rule);

#endif
