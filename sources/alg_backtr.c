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
#include "ft_printf.h"
#include "setup.h"
#include "ps_utils.h"

int		is_sort(t_list *, t_list *); //

void	init_rev_op_arr_simpl(int (*rev_op_arr[]) (t_list **, t_list **, int))
{		
	rev_op_arr[SB_SIMPL] = sb;
	rev_op_arr[RB_SIMPL] = rrb;
	rev_op_arr[RRB_SIMPL] = rb;	
}

void	init_rev_op_arr(int (*rev_op_arr[]) (t_list **, t_list **, int))
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

void	print_tab_style(t_eop *sol_arr)
{
	ft_printf("\033[%dm", 95);
	ft_printf("\033[2K\r ");
	while(*sol_arr)
	{	
		if (*sol_arr == PA)
			ft_printf("pa ");
		else if (*sol_arr == PB)
			ft_printf("pb ");
		else if (*sol_arr == SA)
			ft_printf("sa ");
		else if (*sol_arr == SB)
			ft_printf("sb ");
		else if (*sol_arr == SS)
			ft_printf("ss ");
		else if (*sol_arr == RA)
			ft_printf("ra ");
		else if (*sol_arr == RB)
			ft_printf("rb ");		
		else if (*sol_arr == RR)
			ft_printf("rr ");
		else if (*sol_arr == RRA)
			ft_printf("rra ");
		else if (*sol_arr == RRB)
			ft_printf("rrb ");
		else if (*sol_arr == RRR)
			ft_printf("rrr ");
		sol_arr++;
	}	
	ft_printf("\033[0m");	
}

int	rec(t_list **a_head, t_list **b_head, int depth, int depth_max, t_eop *sol_arr, int (*op_arr[]) (t_list **, t_list **, int), int (*rev_op_arr[]) (t_list **, t_list **, int))
{	
	t_eop op;
		
	if (is_sort(*a_head, *b_head))	
		return (1);			
	else if (depth >= depth_max)						
		return (0);			
	depth++;
	op = NONE;
	while (++op <= RRR)
	{ 
		if (op_arr[op](a_head, b_head, 0))
		{
			sol_arr[depth - 1] = op;
			if (rec(a_head, b_head, depth, depth_max, sol_arr, op_arr, rev_op_arr))		
				return (1);
			rev_op_arr[op](a_head, b_head, 0);		
		}
	}	
	sol_arr[depth - 1] = 0;
	return (0);
}

void	launch_backtr(t_list **la, t_list **lb)
{
	char	*op_char_arr[OP];
	t_eop 	sol_arr[MX_DEPTH];
	int		depth_max;
	
	depth_max = 0;	
	int	i = -1;
	while (++i < MX_DEPTH)
		sol_arr[i] = 0;
	int (*op_arr[OP]) (t_list **, t_list **, int);
	int (*rev_op_arr[OP]) (t_list **, t_list **, int);
	init_op_arr(op_arr);
	init_rev_op_arr(rev_op_arr);	
	while (!rec(la, lb, 0, depth_max, sol_arr, op_arr, rev_op_arr))
		depth_max++;			
	init_op_char_arr(op_char_arr);
	print_tab(sol_arr, op_char_arr);	
}

int	rec_simpl(t_list **lst, int depth, int depth_max, t_eop_simpl *sol_arr, int (*op_arr[]) (t_list **, t_list **, int), int (*rev_op_arr[]) (t_list **, t_list **, int))
{	
	t_eop_simpl op;
	
	if (is_sort_simpl(*lst))
		return (1);					
	else if (depth >= depth_max)						
		return (0);		
	depth++;
	op = NONE_SIMPL;
	while (++op <= RRB_SIMPL)
	{

		if (op_arr[op](lst, lst, 0))
		{			
			sol_arr[depth - 1] = op;
			if (rec_simpl(lst, depth, depth_max, sol_arr, op_arr, rev_op_arr))		
				return (1);
			rev_op_arr[op](lst, lst, 0);		
		}	
	}	
	sol_arr[depth - 1] = 0;
	return (0);
}

void	launch_backtr_simpl(t_list **lst)
{
	char		*op_char_arr[OP];
	t_eop_simpl	sol_arr[MX_DEPTH];
	int			depth_max;

	depth_max = 0;	
	int	i = -1;
	while (++i < MX_DEPTH)
		sol_arr[i] = 0;
	int (*op_arr[OP]) (t_list **, t_list **, int);
	int (*rev_op_arr[OP]) (t_list **, t_list **, int);
	init_op_arr_simpl(op_arr);
	init_rev_op_arr_simpl(rev_op_arr);	
	while (!rec_simpl(lst, 0, depth_max, sol_arr, op_arr, rev_op_arr))
		depth_max++;	
	init_op_char_arr_simpl(op_char_arr);
	print_tab_simpl(sol_arr, op_char_arr);	
}