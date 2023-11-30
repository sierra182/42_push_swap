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

void	init_best_sol(int *sol)
{
	int i;
	
	i = 0;
	while (i < OP)	
		sol[i++] = 0;		
	sol[0] = -1;	
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

t_list	*get_target(int value, t_list *lst)
{	
	t_list *target;
	
	target = get_max_item(lst);	
	if (value > *(int *) target->content)
	 	target = get_min_item(lst);
	else
	{		
		while (lst)
		{
			if (*(int *) lst->content < *(int *) target->content 
					&& *(int *) lst->content > value)
				target = lst;
			lst = lst->next;
		}	
	}
	return (target);
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
			calcul_best(get_item_index(*la, get_target(*(int *) (*lb)->content, *la)), lstsize, ind_lb++, best_sol); 
			*lb = (*lb)->next;
		}
		*lb = lb_sav;
		apply_sol(la, lb, best_sol); 
		pa(la, lb, 1);
	}
	rewind_lst(la, lb, lstsize[0] + 1);   	
}

t_list	*get_middle(t_list *lst)
{
	int	len;
	int	middle;
	t_list	*tmp;
	
	tmp = lst;
	middle = 0;
	while ( tmp && tmp != ft_lstlast(lst)) 
	{
		middle++;
		tmp = tmp->next;
	}
	middle /= 2;
	while (middle--)
		lst = lst->next;			
	return (lst);
}

void	pre_sort(t_list **la, t_list **lb, int argc, int *args_arr)
{
	int	median;
	
	sort_list(*la);
	median = *(int *) get_middle(*la)->content;
	ft_lstclear(la, NULL);
	init_list(la, argc, args_arr);
	sort_by_pivot(la, lb, median);	
}

void	sort_by_pivot(t_list **la, t_list **lb, int pivot)
{	
	pb(la, lb, 1);
	while (*la)
	{		
		pb(la, lb, 1);
		if (*(int *) (*lb)->content <= pivot)
			rb(la, lb, 1);		
	}
}