/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_turk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:46:37 by marvin            #+#    #+#             */
/*   Updated: 2023/11/29 16:46:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_turk_utils.h"
#include "operations.h"
#include "setup.h"

static void	apply_sol(t_list **la, t_list **lb, int *sol)
{
	t_eop		op;
	static int	(*op_arr[OP])(t_list **, t_list **, int);

	if (!op_arr[PA])
		init_op_arr(op_arr);
	op = 0;
	while (++op <= RRR)
	{
		while (sol[op])
		{
			op_arr[op](la, lb, 1);
			sol[op]--;
		}
	}
	sol[0] = -1;
}

static void	init_best_sol(int *sol)
{
	int	i;

	i = 0;
	while (i < OP)
		sol[i++] = 0;
	sol[0] = -1;
}

void	alg_turk(t_list	**la, t_list *lb_sav, t_list **lb, int ind_lb)
{
	int		best_sol[OP];
	int		lstsize[2];

	init_best_sol(best_sol);
	pa(la, lb, 1);
	while (*lb)
	{
		ind_lb = 0;
		lstsize[0] = ft_lstsize(*la);
		lstsize[1] = ft_lstsize(*lb);
		lb_sav = *lb;
		while (*lb)
		{
			calcul_best(get_item_index(*la, get_target(*(int *)
						(*lb)->content, *la)), lstsize, ind_lb++, best_sol);
			*lb = (*lb)->next;
		}
		*lb = lb_sav;
		apply_sol(la, lb, best_sol);
		pa(la, lb, 1);
	}
	rewind_lst(la, lb, lstsize[0] + 1);
}
