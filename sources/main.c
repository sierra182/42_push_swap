/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/15 22:17:07 by marvin           ###   ########.fr       */
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

void	*init_list(t_list **lst, int argc, char *argv[], int *args_arr)
{
	t_list	*new;
	
	while (*++argv)
	{			
		new = ft_lstnew((void *) args_arr++);
		ft_lstadd_back(lst, new);
	}		
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;	
}

t_list	*sort_list(t_list* lst)
{
	t_list *tmp;
	
	tmp = lst;
	while (tmp->next)
	{
		if (*(int *) tmp->content > *(int *) tmp->next->content)
		{
			swap((int *) tmp->content, (int *) tmp->next->content);
			tmp = lst;
		}
		else
			tmp = tmp->next;
	}
	return (lst);
}

t_list	*alg_sort_list(t_list* lst)
{
	t_list *tmp;
	int	i;
	
	i = 0;
	tmp = lst;
	while (tmp->next)
	{
		if (*(int *) tmp->content > *(int *) tmp->next->content)
		{
			sa(tmp);
			while (i > 0)	
			{
				ft_printf("%d", i);
				rra(&tmp);
				i--;
			}		
		}
		else
		{
			ra(&tmp);
			i++;
		}
	}
	print_lst(lst, lst);
	return (lst);
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
	alg_sort_list(a_head);
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