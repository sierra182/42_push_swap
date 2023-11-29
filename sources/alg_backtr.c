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
	static char	*op_char_arr[OP];
	
	if (!op_char_arr[PA])
	{ 
		op_char_arr[PA] = "pa ";
		op_char_arr[PB] = "pb ";
		op_char_arr[SA] = "sa ";
		op_char_arr[SB] = "sb ";
		op_char_arr[SS] = "ss ";
		op_char_arr[RA] = "ra ";
		op_char_arr[RB] = "rb ";
		op_char_arr[RR] = "rr ";
		op_char_arr[RRA] = "rra ";
		op_char_arr[RRB] = "rrb ";
		op_char_arr[RRR] = "rrr ";
	}
	ft_printf("\033[%dm", 95);
	ft_printf("\033[2K\r ");
	print_tab(sol_arr, op_char_arr);	
	ft_printf("\033[0m");	
}

typedef struct s_listpack
{
	t_list	**la;
	t_list	**lb;
} t_slistpack;

typedef struct s_depth
{
	int	depth;
	int	depth_max;
} t_sdepth;

typedef struct s_backtr_utils
{
	t_eop	sol_arr[MX_DEPTH];
	int 	(*op_arr[OP]) (t_list **, t_list **, int);
	int 	(*rev_op_arr[OP]) (t_list **, t_list **, int);
} t_sbacktr_utils;

int	rec(t_slistpack *listpack, t_sdepth depth, t_sbacktr_utils *backtr_utils, int flag)
{	
	t_eop op;
	
	if (is_sort(*listpack->la, *listpack->lb))	
		return (1);			
	else if (depth.depth >= depth.depth_max)
	{
		if (flag) 						
			print_tab_style(backtr_utils->sol_arr);
		return (0);			
	}
	depth.depth++;
	op = NONE;
	while (++op <= RRR)
	{
		if (backtr_utils->op_arr[op](listpack->la, listpack->lb, 0))
		{
			backtr_utils->sol_arr[depth.depth - 1] = op;
			if (rec(listpack, depth, backtr_utils, flag))
				return (1);
			backtr_utils->rev_op_arr[op](listpack->la, listpack->lb, 0);	
		}
	}	
	backtr_utils->sol_arr[depth.depth - 1] = 0;
	return (0);
}

void	launch_backtr(t_list **la, t_list **lb, int flag)
{
	char			*op_char_arr[OP];
	t_sbacktr_utils backtr_utils;
	t_slistpack		listpack;
	t_sdepth		depth;
	int				i;
	
	i = -1;
	while (++i < MX_DEPTH)
		backtr_utils.sol_arr[i] = 0;
	depth.depth_max = 0;	
	depth.depth = 0;
	listpack.la = la;
	listpack.lb = lb;
	init_op_arr(backtr_utils.op_arr);
	init_rev_op_arr(backtr_utils.rev_op_arr);
	while (!rec(&listpack, depth, &backtr_utils, flag))
		depth.depth_max++;			
	init_op_char_arr(op_char_arr);
	if (flag)
	{
		print_tab_style(backtr_utils.sol_arr);
		ft_printf("\n");
	}
	else
		print_tab(backtr_utils.sol_arr, op_char_arr);
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