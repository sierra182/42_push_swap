/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_turk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:01:52 by svidot            #+#    #+#             */
/*   Updated: 2023/11/30 12:09:02 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	init_snop(t_snop *snop)
{
	snop->n_ra = 0;
	snop->n_rb = 0;
	snop->n_rr = 0;
	snop->n_rra = 0;
	snop->n_rrb = 0;
	snop->n_rrr = 0;
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

