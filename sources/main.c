/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/29 09:30:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "setup.h"
#include "ps_utils.h"
#include "alg_backtr.h"
#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"
#include "operations.h"
#include <stdio.h>

#include <stdio.h>

t_list	*get_max_item(t_list *lst)
{
	t_list	*max_item;
	
	max_item = lst;
	while (lst)
	{
		if (*(int *) lst->content > *(int *) max_item->content)
			max_item = lst;
		lst = lst->next;
	}
	return (max_item);
}

t_list	*get_min_item(t_list *lst)
{
	t_list	*min_item;
	
	min_item = lst;
	while (lst)
	{
		if (*(int *) lst->content < *(int *) min_item->content)
			min_item = lst;
		lst = lst->next;
	}
	return (min_item);
}

int	get_item_index(t_list *lst, t_list *item)
{
	int	i;

	i = 0;
	while (lst && ++i)
	{
		if (lst == item)
			return (--i);
		lst = lst->next;
	}
	return (--i);
}

t_list	*get_target(int value, t_list *lst)
{	
	t_list *target;
	
	target = get_min_item(lst);	
	if (value < *(int *) target->content)
		target = get_max_item(lst);
	else
	{		
		while (lst)
		{
			if (*(int *) lst->content > *(int *) target->content 
					&& *(int *) lst->content < value)
				target = lst;
			lst = lst->next;
		}	
	}
	return (target);
}

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

void	init_snop(t_snop *snop)
{
	snop->n_ra = 0;
	snop->n_rb = 0;
	snop->n_rr = 0;
	snop->n_rra = 0;
	snop->n_rrb = 0;
	snop->n_rrr = 0;
}

int	assign_up_up(t_scost *scost, t_snop *snop)
{		
	if (scost->up_need_a <= scost->down_need_a && 
			scost->up_need_b <= scost->down_need_b)
	{	
		if (scost->up_need_a >= scost->up_need_b)
		{		
			snop->n_ra = scost->up_need_a - scost->up_need_b;			
			snop->n_rr = scost->up_need_b;
			scost->cost = scost->up_need_a; 
		}
		else
		{
			snop->n_rb = scost->up_need_b - scost->up_need_a;			
			snop->n_rr = scost->up_need_a;
			scost->cost = scost->up_need_b; 
		}
		return (1);
	}
	return (0);
}

int	assign_down_down(t_scost *scost, t_snop *snop)
{		
	if (scost->down_need_a <= scost->up_need_a && 
		scost->down_need_b <= scost->up_need_b)
	{	
		if (scost->down_need_a >= scost->down_need_b)
		{
			snop->n_rra = scost->down_need_a - scost->down_need_b;			
			snop->n_rrr = scost->down_need_b;
			scost->cost = scost->down_need_a; 
		}
		else
		{
			snop->n_rrb = scost->down_need_b - scost->down_need_a;			
			snop->n_rrr = scost->down_need_a;
			scost->cost = scost->down_need_b; 
		}
		return (1);
	}
	return (0);
}	

void	assign_updown_downup(t_scost *scost, t_snop *snop)
{		
	if (scost->up_need_a <= scost->down_need_a
		&& scost->up_need_b >= scost->down_need_b)
	{	
		snop->n_ra = scost->up_need_a;
		snop->n_rrb = scost->down_need_b;
		scost->cost = scost->up_need_a + scost->down_need_b;
	}
	else if (scost->up_need_a >= scost->down_need_a
		&& scost->up_need_b <= scost->down_need_b)
	{	
		snop->n_rb = scost->up_need_b;
		snop->n_rra = scost->down_need_a;
		scost->cost = scost->up_need_b + scost->down_need_a; 
	}	
}

void	calcul_best(int ind_item_a, int *lstsize, int ind_item_b, int *best_sol)
{	
	t_scost scost;
	t_snop 	snop;
		
	init_snop(&snop);	
	scost.up_need_a = ind_item_a;
	scost.down_need_a = lstsize[0] - ind_item_a;
	scost.up_need_b = ind_item_b;
	scost.down_need_b = lstsize[1] - ind_item_b;	
	if (assign_up_up(&scost, &snop))
		;	
	else if (assign_down_down(&scost, &snop))
		;
	else
		assign_updown_downup(&scost, &snop);
	if (scost.cost < best_sol[0] || best_sol[0] == -1)
	{		
		best_sol[RR] = snop.n_rr;
		best_sol[RRR] = snop.n_rrr;
		best_sol[RB] = snop.n_rb;
		best_sol[RRB] = snop.n_rrb;
		best_sol[RA] = snop.n_ra;
		best_sol[RRA] = snop.n_rra;
		best_sol[0] = scost.cost;
	}		
}

void	rewind_lst(t_list **la, t_list **lb, int lstsize)
{
	int		target_ind;

	target_ind = get_item_index(*lb, get_max_item(*lb));
	if (target_ind > 0 && lstsize - target_ind >= target_ind)
		while (target_ind--)
			rb(la, lb, 1);
	else if (target_ind)
		while (lstsize-- - target_ind)
			rrb(la, lb, 1);
}

void	apply_sol(t_list **la, t_list **lb, int *sol)
{
	t_eop	op;
	int 	(*op_arr[OP]) (t_list **, t_list **, int); //static ?!!!!!!!!!!!!!!!!! optim proco
	
	op = 0;
	init_op_arr(op_arr);
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

void	init_best_sol(int *sol)
{
	int i;
	
	i = 0;
	while (i < OP)	
		sol[i++] = 0;		
	sol[0] = -1;	
}

void	alg_turk(t_list	**la, t_list *la_sav, t_list *lb, int ind_la)
{	
	int		best_sol[OP];
	int		lstsize[2];
	
	init_best_sol(best_sol);	
	pb(la, &lb, 1);
	while (*la)
	{
		ind_la = 0;
		lstsize[0] = ft_lstsize(*la);
		lstsize[1] = ft_lstsize(lb);
		la_sav = *la;
		while (*la)
		{
			calcul_best(ind_la++, lstsize, get_item_index(lb,
					get_target(*(int *) (*la)->content, lb)), best_sol);
			*la = (*la)->next;
		}
		*la = la_sav;
		apply_sol(la, &lb, best_sol);
		pb(la, &lb, 1);
	}
	rewind_lst(la, &lb, lstsize[1] + 1);
	while (pa(la, &lb, 1))
		;
}

void	alg_forwarding(t_list **la, t_list **lb, int argc, int flag)
{
	if (argc - 1 <= 6)
	{
		if (flag)
			ft_printf("\nwelcome to backtracking\n");
		launch_backtr(la, lb, flag);
	}
	else
	{
		alg_turk(la, *la, *lb, 0);
		if (flag)
			ft_printf("\n    .- ¨\n    }    \n   °\n °*       .!*¨****°\n**       **°    *)\n+: +:+         +°\n \
		+#  -+.+       +|'\n+=1=+=1=1=-   +-\n     #+#    °°<...-.\n     °#+   °%%%%%%%%%%°%%%%$  <~°~~-~~°-°-\n");
	}
	if (flag)
		print_lst(*la, *lb);
}

void	del_arg(char *argv[])
{	
	while (*++argv)	
		*argv = *(argv + 1);	
}

int	main(int argc, char *argv[])
{ 
	int		*args_arr;
	int 	range;
	int		flag;
	t_list	*la;
	t_list	*lb;
	
	la = NULL;
	lb = NULL;
	flag = 0;
	if (argc <= 1)
		return (1);
	if (argv[1][0] == '-' && argv[1][1] == 'v' && ++flag)
		del_arg(argv);
	if (!setup(&argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&la, argc, args_arr);
	if (!is_sort(la, lb))
		alg_forwarding(&la, &lb, argc, flag);	
	free(args_arr);
	ft_lstclear(&la, NULL);
	ft_lstclear(&lb, NULL);
	return (0);
}
