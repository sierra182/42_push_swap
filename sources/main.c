/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/16 22:53:26 by marvin           ###   ########.fr       */
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

int	rec(t_list **a_head, t_list **b_head, int depth, int depth_max, int a_size, int **op_arr)
{
	if (is_sort(*a_head, a_size))
	{
		ft_printf("depth: %d\n", depth);
		return (1);		
	}	
	else if (depth >= depth_max)	
		return (0);	
	depth++;
		
	sa(*a_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
	{
		op_arr[depth - 1] = 
		return (1);
	}
	sa(*a_head);
	
	pb(a_head, b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	pa(a_head, b_head);
	
	sb(*b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	sb(*b_head);
	
	ra(a_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	rra(a_head);
	
	rb(b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	rrb(b_head);
	
	rra(a_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	ra(a_head);
	
	rrb(b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	rb(b_head);
	
	pa(a_head, b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	pb(a_head, b_head);
	
	ss(*a_head, *b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	ss(*a_head, *b_head);
	
	rr(a_head, b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	rrr(a_head, b_head);
	
	rrr(a_head, b_head);
	if (rec(a_head, b_head, depth, depth_max, a_size))
		return (1);
	rr(a_head, b_head);
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
	while (!rec(&a_head, &b_head, 0, depth_max, lstsize))
	{
		ft_printf("\nKO\n");
		depth_max++;
	}			
	print_lst(a_head, b_head);
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