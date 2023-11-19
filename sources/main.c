/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/19 19:08:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "setup.h"
#include "alg_backtr.h"
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
void	print_tab_perso(t_eop *sol_arr)
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

void	print_tab(t_eop *sol_arr)
{		
	while(*sol_arr)
	{	
		if (*sol_arr == PA)
			ft_printf("pa\n");
		else if (*sol_arr == PB)
			ft_printf("pb\n");
		else if (*sol_arr == SA)
			ft_printf("sa\n");
		else if (*sol_arr == SB)
			ft_printf("sb\n");
		else if (*sol_arr == SS)
			ft_printf("ss\n");
		else if (*sol_arr == RA)
			ft_printf("ra\n");
		else if (*sol_arr == RB)
			ft_printf("rb\n");		
		else if (*sol_arr == RR)
			ft_printf("rr\n");
		else if (*sol_arr == RRA)
			ft_printf("rra\n");
		else if (*sol_arr == RRB)
			ft_printf("rrb\n");
		else if (*sol_arr == RRR)
			ft_printf("rrr\n");
		sol_arr++;
	}		
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
int	apply_sol(t_eop *sol_arr, int (*op_arr[]) (t_list **, t_list **), t_list **la, t_list **lb)
{
	while (*sol_arr)	
		op_arr[*sol_arr++](la, lb);
}	

// t_list	*sort_list(t_list* lst)
// {
// 	t_list *tmp;
	
// 	tmp = lst;
// 	while (tmp->next)
// 	{
// 		if (*(int *) tmp->content > *(int *) tmp->next->content)
// 		{
// 			sa(tmp);
// 			tmp = lst;
// 		}
// 		else		
// 			tmp = tmp->next;		
// 	}
// 	return (lst);
// }

// t_list	*alg_sort_list(t_list *lst)
// {
// 	t_list *tmp;
// 	int		i;
// 	int		j;	
// 	int		len;
	
// 	len  = ft_lstsize(lst);
// 	i = 0;
// 	j = 0;
// 	tmp = lst;
// 	while (j++ < len - 1)
// 	{
// 		if (*(int *) tmp->content > *(int *) tmp->next->content)
// 		{
// 			j = 0;		
// 			sa(tmp);
// 			while (i && i--)			
// 				rra(&tmp);			
// 		}
// 		else
// 		{		
// 			ra(&tmp);			
// 			i++;				
// 		}
// 	}
// 	ra(&tmp);
// 	return (lst);
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

	//int	lstsize = ft_lstsize(a_head);	
	//ft_printf(" len: %d\n\n", lstsize);
	
	int	depth_max = 0;
	t_eop sol_arr[42]; 
	int	i = -1;
	while (++i < 42)
		sol_arr[i] = 0;
	int (*op_arr[OP]) (t_list **, t_list **);
	int (*rev_op_arr[OP]) (t_list **, t_list **);
	init_op_arr(op_arr);
	init_rev_op_arr(rev_op_arr);
	//print_tab(sol_arr);
	while (!rec(&a_head, &b_head, 0, depth_max, sol_arr, op_arr, rev_op_arr))
		depth_max++;	

	//print_tab(sol_arr);			
	// print_lst(a_head, b_head);
	// ft_lstclear(&a_head, NULL);
	// init_list(&a_head, argc, args_arr);
	// print_lst(a_head, b_head);
	// apply_sol(sol_arr, op_arr, &a_head, &b_head);
	// print_lst(a_head, b_head);
	// if (is_sort(a_head, b_head))
	// 	ft_printf("\nOK\n");
	// else 
	// 	ft_printf("KO\n\n");

	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);
}