/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_turk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:39:59 by marvin            #+#    #+#             */
/*   Updated: 2023/11/30 14:39:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALG_TURK_UTILS_H
# define ALG_TURK_UTILS_H

#include "libft.h"
typedef struct s_cost_utils
{
	int	up_need_a;
	int	down_need_a;
	int	up_need_b; 
	int	down_need_b;
	int	cost;
} t_scost;
	
typedef struct s_n_op
{
	int	n_ra;
	int	n_rb;
	int n_rr;
	int n_rra;
	int n_rrb;
	int n_rrr;
} t_snop;

int		get_item_index(t_list *lst, t_list *item);
void	rewind_lst(t_list **la, t_list **lb, int lstsize);
void	calcul_best(int ind_item_a, int *lstsize, int ind_item_b, int *best_sol);
t_list	*get_target(int value, t_list *lst);

#endif