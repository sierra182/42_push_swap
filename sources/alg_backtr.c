/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_backtracking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:28:45 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 12:28:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_backtr.h"
void	print_tab(t_eop *); //
int		is_sort(t_list *, t_list *); //

void	init_op_arr(int (*op_arr[]) (t_list **, t_list **))
{
	op_arr[PA] = pa;
	op_arr[PB] = pb;	
	op_arr[SA] = sa;
	op_arr[SB] = sb;
	op_arr[SS] = ss;
	op_arr[RA] = ra;
	op_arr[RB] = rb;
	op_arr[RR] = rr;
	op_arr[RRA] = rra;
	op_arr[RRB] = rrb;
	op_arr[RRR] = rrr;	
}

void	init_rev_op_arr(int (*rev_op_arr[]) (t_list **, t_list **))
{
	rev_op_arr[PA] = pb;
	rev_op_arr[PB] = pa;	
	rev_op_arr[SA] = sa;
	rev_op_arr[SB] = sb;
	rev_op_arr[SS] = ss;
	rev_op_arr[RA] = rra;
	rev_op_arr[RB] = rrb;
	rev_op_arr[RR] = rrr;
	rev_op_arr[RRA] = ra;
	rev_op_arr[RRB] = rb;
	rev_op_arr[RRR] = rr;
}

int	rec(t_list **a_head, t_list **b_head, int depth, int depth_max, t_eop *sol_arr, int (*op_arr[]) (t_list **, t_list **), int (*rev_op_arr[]) (t_list **, t_list **))
{	
	t_eop op;
	
	if (is_sort(*a_head, *b_head))
	{
		print_tab(sol_arr);		
		return (1);		
	}	
	else if (depth >= depth_max)
		return (0);		
	depth++;
	op = NONE;
	while (++op <= RRR)
	{ 
		if (op_arr[op](a_head, b_head))
		{
			sol_arr[depth - 1] = op;
			if (rec(a_head, b_head, depth, depth_max, sol_arr, op_arr, rev_op_arr))		
				return (1);
			rev_op_arr[op](a_head, b_head);		
		}
	}	
	sol_arr[depth - 1] = 0;
	return (0);
}