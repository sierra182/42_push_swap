/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/18 17:42:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "setup.h"
#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"
#include "operations.h"
#include <stdio.h>

void	del_link(t_list *link, t_list **lst, t_list *lstsave)
{
	t_list	*lstnext;

	while (*lst)
	{
		if (*lst == link)
		{
			lstnext = (*lst)->next;
			free(*lst);
			*lst = lstnext;
			break ;
		}
		else if ((*lst)->next == link)
		{
			lstnext = (*lst)->next->next;
			free((*lst)->next);
			(*lst)->next = lstnext;
			*lst = lstsave;
			break ;
		}
		*lst = (*lst)->next;
	}	
}

void	print_lst(t_list *la, t_list *lb)
{	
	ft_printf("\n\033[%dm", 96);
	ft_printf(" ~~~~~~~~~~~~~~~~~~~~ ~~(,,°>\n");
	ft_printf("\033[0m");
	while (la || lb)
	{
		if (la)
		{
			ft_printf(" %d", *(int *) la->content);
			la = la->next;
		}
		ft_printf("\r\t\t\b\b\b|*|  ");
		if (lb)
		{
			ft_printf(" %d", *(int *) lb->content);
			lb = lb->next;			
		}
		ft_printf("\n");		
	}
	ft_printf("\n");	
}

t_list	*sort_list(t_list* lst)
{
	t_list *tmp;
	
	tmp = lst;
	while (tmp->next)
	{
		if (*(int *) tmp->content > *(int *) tmp->next->content)
		{
			sa(tmp);
			tmp = lst;
		}
		else		
			tmp = tmp->next;		
	}
	return (lst);
}

t_list	*alg_sort_list(t_list *lst)
{
	t_list *tmp;
	int		i;
	int		j;	
	int		len;
	
	len  = ft_lstsize(lst);
	i = 0;
	j = 0;
	tmp = lst;
	while (j++ < len - 1)
	{
		if (*(int *) tmp->content > *(int *) tmp->next->content)
		{
			j = 0;		
			sa(tmp);
			while (i && i--)			
				rra(&tmp);			
		}
		else
		{		
			ra(&tmp);			
			i++;				
		}
	}
	ra(&tmp);
	return (lst);
}

int	is_sort(t_list *la, t_list *lb)
{
	if (ft_lstsize(lb))
		return (0);
	while (la->next)
	{
		if (*(int *) la->content > *(int *) la->next->content)
			return (0);
		la = la->next;		
	}	
	return (1);
}
#define OP 11

typedef enum e_op
{
	NONE,
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
} t_op;

void	print_tab(t_op *sol_arr)
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
	fflush(stdout);
}

int	rec(t_list **a_head, t_list **b_head, int depth, int depth_max, t_op *sol_arr)
{	
	if (is_sort(*a_head, *b_head))
	{
		print_tab(sol_arr);
		ft_printf("\n depth: %d\n", depth);
		return (1);		
	}	
	else if (depth >= depth_max)
	{
		print_tab(sol_arr);
		//print_lst(*a_head, *b_head);
		return (0);	
	}
	depth++;
		
	sol_arr[depth - 1] = SA;
	if (sa(*a_head))
	{
		if (rec(a_head, b_head, depth, depth_max, sol_arr))		
			return (1);
		sa(*a_head);		
	}
		
	sol_arr[depth - 1] = PB;
	if (pb(a_head, b_head))
	{
		if (rec(a_head, b_head, depth, depth_max, sol_arr))
			return (1);
		pa(a_head, b_head);		
	}
	
	sol_arr[depth - 1] = SB;
	if (sb(*b_head))
	{
		if (rec(a_head, b_head, depth, depth_max, sol_arr))
			return (1);
		sb(*b_head);		
	}
		
	sol_arr[depth - 1] = RA;
	if (ra(a_head))
	{
		if (rec(a_head, b_head, depth, depth_max, sol_arr))
			return (1);
		rra(a_head);		
	}
		
	sol_arr[depth - 1] = RB;
	if (rb(b_head))
	{
		if (rec(a_head, b_head, depth, depth_max, sol_arr))
			return (1);
		rrb(b_head);		
	}
		
	sol_arr[depth - 1] = RRA;
	if (rra(a_head))
	{
		if (rec(a_head, b_head, depth, depth_max, sol_arr))
			return (1);
		ra(a_head);		
	}
		
	sol_arr[depth - 1] = RRB;
	if (rrb(b_head))
	{
		if (rec(a_head, b_head, depth, depth_max, sol_arr))
			return (1);
		rb(b_head);		
	}
		
	sol_arr[depth - 1] = PA;
	if (pa(a_head, b_head))
	{
		if (rec(a_head, b_head, depth, depth_max, sol_arr))
			return (1);
		pb(a_head, b_head);		
	}	
		
	sol_arr[depth - 1] = SS;
	ss(*a_head, *b_head);
	if (rec(a_head, b_head, depth, depth_max, sol_arr))
		return (1);
	ss(*a_head, *b_head);
		
	sol_arr[depth - 1] = RR;
	rr(a_head, b_head);	
	if (rec(a_head, b_head, depth, depth_max, sol_arr))
		return (1);
	rrr(a_head, b_head);			
		
	sol_arr[depth - 1] = RRR;
	rrr(a_head, b_head);
	if (rec(a_head, b_head, depth, depth_max, sol_arr))
		return (1);
	rr(a_head, b_head);
	
	sol_arr[depth - 1] = 0;
	return (0);
}


// void	init_op_arr(void (*op_arr[OP]) (t_list **, t_list **))
// {
// 	op_arr[PA] = pa;
// 	op_arr[PB] = pb;	
// 	op_arr[SA] = sa;
// 	op_arr[SB] = sb;
// 	op_arr[SS] = ss;
// 	op_arr[RA] = ra;
// 	op_arr[RB] = rb;
// 	op_arr[RR] = rr;
// 	op_arr[RRA] = rra;
// 	op_arr[RRB] = rrb;
// 	op_arr[RRR] = rrr;	
// }

// int	apply_sol(int *sol_arr, void (*op_arr[OP]) (t_list **, t_list **), t_list **la, t_list **lb)
// {
// 	while (*sol_arr)	
// 		op_arr[*sol_arr++](la, lb);
// }	

int	main(int argc, char *argv[])
{
	int		*args_arr;
	t_list	*a_head;
	t_list	*b_head;

	a_head = NULL;
	b_head = NULL;
	if (argc <= 1)
		return (1);
	if (!setup(&argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&a_head, argc, args_arr);
	print_lst(a_head, b_head);
	// if (is_sort(a_head, ft_lstsize(a_head)))
	// 	ft_printf("\nOK\n");
	// else 
	// 	ft_printf("KO\n\n");
	// alg_sort_list(a_head);
	//	if (is_ascending(a_head))
	int	lstsize = ft_lstsize(a_head);
	ft_printf(" len: %d\n\n", lstsize);
	int	depth_max = 0;
	t_op sol_arr[OP]; 
	int	i = -1;
	while (++i < OP)
		sol_arr[i] = 0;
	print_tab(sol_arr);	
	while (!rec(&a_head, &b_head, 0, depth_max, sol_arr))	
		depth_max++;		
	//print_tab(sol_arr);			
	print_lst(a_head, b_head);
		//print_tab(sol_arr);
	//print_lst(a_head, b_head);
	// sa(a_head);
	// print_lst(a_head, b_head);
	
	// sb(b_head);
	// print_lst(a_head, b_head);
	
	// pb(&a_head, &b_head);
	// pb(&a_head, &b_head);
	
	// print_lst(a_head, b_head);
	
	// ss(a_head, b_head);
	// print_lst(a_head, b_head);

	// pa(&a_head, &b_head);
	// pa(&a_head, &b_head);
	
	// print_lst(a_head, b_head);

	// pb(&a_head, &b_head);
	// pb(&a_head, &b_head);
	// pb(&a_head, &b_head);
	
	// print_lst(a_head, b_head);	

	// ra(&a_head);
	// rb(&b_head);
	
	// print_lst(a_head, b_head);
	
	// rr(&a_head, &b_head);
	// print_lst(a_head, b_head);

	// rra(&a_head);
	// rrb(&b_head);
	
	// print_lst(a_head, b_head);
	
	// rrr(&a_head, &b_head);
	// print_lst(a_head, b_head);

	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);
}