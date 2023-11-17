/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/17 09:10:54 by marvin           ###   ########.fr       */
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
	ft_printf("~~~~~~~~~~~~~~~~~~~~ ~~(,,°>\n");
	ft_printf("\033[0m");
	while (la || lb)
	{
		if (la)
		{
			ft_printf("%d", *(int *) la->content);
			la = la->next;
		}
		ft_printf("\r\t\t\b\b\b\b|*|  ");
		if (lb)
		{
			ft_printf("%d", *(int *) lb->content);
			lb = lb->next;			
		}
		ft_printf("\n");		
	}
	ft_printf("\n");	
}

void	init_list(t_list **lst, int argc, char *argv[], int *args_arr)
{
	int		*args_arr_save;
	t_list	*new;

	args_arr_save = args_arr;
	while (*++argv)
	{			
		new = ft_lstnew((void *) args_arr++);
		if (!new)
		{
			free(args_arr_save);
			ft_lstclear(lst, NULL);
			exit(1);
		}
		ft_lstadd_back(lst, new);
	}		
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

int	is_sort(t_list *lst, int a_size)
{
	if (ft_lstsize(lst) != a_size)
		return (0);
	while (lst->next)
	{
		if (*(int *) lst->content > *(int *) lst->next->content)
			return (0);
		lst = lst->next;		
	}	
	return (1);
}

enum e_op
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
};

void	print_tab(int *arr)
{
	fflush(stdout);
	printf("\033[2K\r");	   
	while(*arr)
	{	
		if (*arr == PA)
			ft_printf("pa ");
		else if (*arr == PB)
			ft_printf("pb ");
		else if (*arr == SA)
			ft_printf("sa ");
		else if (*arr == SB)
			ft_printf("sb ");
		else if (*arr == SS)
			ft_printf("ss ");
		else if (*arr == RA)
			ft_printf("ra ");
		else if (*arr == RB)
			ft_printf("rb ");		
		else if (*arr == RR)
			ft_printf("rr ");
		else if (*arr == RRA)
			ft_printf("rra ");
		else if (*arr == RRB)
			ft_printf("rrb ");
		else if (*arr == RRR)
			ft_printf("rrr ");
		arr++;
	}
}

int	rec(t_list **a_head, t_list **b_head, int depth, int depth_max, int a_size, int *op_arr)
{
	if (is_sort(*a_head, a_size))
	{
		ft_printf("depth: %d\n", depth);
		return (1);		
	}	
	else if (depth >= depth_max)
	{
		print_tab(op_arr);		
		return (0);	
	}
	depth++;
		
	op_arr[depth - 1] = SA;
	sa(*a_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))		
		return (1);
	sa(*a_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = PB;
	pb(a_head, b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	pa(a_head, b_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = SB;
	sb(*b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	sb(*b_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = RA;
	ra(a_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	rra(a_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = RB;
	rb(b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	rrb(b_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = RRA;
	rra(a_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	ra(a_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = RRB;
	rrb(b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	rb(b_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = PA;
	pa(a_head, b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	pb(a_head, b_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = SS;
	ss(*a_head, *b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	ss(*a_head, *b_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = RR;
	rr(a_head, b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	rrr(a_head, b_head);
	op_arr[depth - 1] = 0;
	
	op_arr[depth - 1] = RRR;
	rrr(a_head, b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size, op_arr))
		return (1);
	rr(a_head, b_head);
	op_arr[depth - 1] = 0;
	return (0);
}

int	main(int argc, char *argv[])
{
	int		*args_arr;
	t_list	*a_head;
	t_list	*b_head;
	
	a_head = NULL;
	b_head = NULL;
	if (argc <= 1)
		return (1);
	if (!setup(argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&a_head, argc, argv, args_arr);
	print_lst(a_head, b_head);
	// if (is_sort(a_head, ft_lstsize(a_head)))
	// 	ft_printf("\nOK\n");
	// else 
	// 	ft_printf("KO\n\n");
	// alg_sort_list(a_head);
	//	if (is_ascending(a_head))
	int	lstsize = ft_lstsize(a_head);
	int	depth_max = 0;
	int op_arr[11];
	int	i = -1;
	while (++i < 11)
		op_arr[i] = 0;
	while (!rec(&a_head, &b_head, 0, depth_max, lstsize, op_arr))	
		depth_max++;			
	print_lst(a_head, b_head);
	//	print_tab(op_arr);
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