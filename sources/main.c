/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/23 05:06:43 by marvin           ###   ########.fr       */
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

int	get_range_size(t_list *la, t_list *lb)
{
	int i;
	
	i = 0;
	while (la != lb)
	{
		i++;
		la = la->next;
	}
	return (i);
}

int	is_sort_range(t_list *la, t_list *lb)
{	
	int	i;
	
	i = 1;	
	while (la->next && la != lb)
	{
		if (*(int *) la->content > *(int *) la->next->content)	
			return (0);		
		la = la->next;
		i++;		
	}	
	return (i);
}

t_list	*get_middle(t_list *l_start, t_list *l_end)
{
	int	len;
	int	middle;
	t_list	*tmp;
	
	tmp = l_start;
	middle = 0;
	while ( tmp && tmp != l_end) 
	{
		middle++;
		tmp = tmp->next;
	}
	middle /= 2;
	while (middle--)
		l_start = l_start->next;			
	return (l_start);
}

int	rec_qs(t_list **la_start, t_list **la_end, t_list **lb)
{
	static int first_play = 0;
	t_list	*lstlast;
	t_list	*piv;
	int		flag;
	int		b_len;
	int		ra_count;
	int		sort;
	
	static int mycount = 0;
	//ft_printf("%d\n\n\n\n\n", get_range_size(*la_start, *la_end));
		
	flag = 0;
	sort = is_sort_range(*la_start, *la_end);
	if (sort > 2)
		while (sort-- && ++flag)
			ra(la_start, la_end, 1);
	if (is_sort(*la_start, *lb))
		{
			//ft_printf("AAAAAAA :%d\n", mycount);
			return(1);
		}
	if (flag)
		return (0);
		
	piv = *la_start;
	if (*la_start == *la_end || (*la_start)->next == *la_end)
	{			
		if (*(int *) (*la_start)->content > *(int *) (*la_end)->content)
		{			
			sa(la_start, lb, 1);
			ra(la_start, la_end, 1);			
		}
		else if (*(int *) (*la_start)->content < *(int *) (*la_end)->content)
			ra(la_start, la_end, 1);
		ra(la_start, la_end, 1);
		
		if (is_sort(*la_start, *lb))
		{
			//ft_printf("AAAAAAA :%d\n", mycount);
			return(1);
		}
		return (0);
	}
	flag = 1;
	ra_count = 0;
	while (*la_start != *la_end && flag || flag--)
	{		
		if (*(int *) (*la_start)->content < *(int *) piv->content)				
	 		pb(la_start, lb, 1);				
	 	else 
		{
	 		ra(la_start, lb, 1);
			ra_count++;	
		}	
	}
//print_lst(*la_start, *lb);
	
//	print_lst(*la_start, *lb);
	t_list *new_lb_end = ft_lstlast(*la_start);
	if (first_play)
	{
		while (ra_count--)
			rra(la_start, lb, 1);
	}	
	else
		first_play = 1;	
	// if (ft_lstsize(*lb) < 7 && ft_lstsize(*lb) > 2)
	// {
	// 	launch_backtr_simpl(lb);
	// }
	t_list *new_lb_start = piv->next;
	t_list *new_la_end = piv;
	b_len = ft_lstsize(*lb);
	while (b_len--)
		pa(la_start, lb, 1);
	t_list *new_la_start = *la_start;
	if (rec_qs(&new_la_start, &new_la_end, lb))	 
		return (1);	
	if (rec_qs(&new_lb_start, &new_lb_end, lb))
		return (1);
	return (0);	
}

void	alg_quick_sort(t_list **la, t_list **lb)
{
	t_list	*lstlast;
	t_list	*piv;
	
	lstlast = ft_lstlast(*la);
	rec_qs(la, &lstlast, lb);	
}

void	alg_forwarding(t_list **la, t_list **lb, int argc)
{
	if (argc - 1 <= 7) 
		launch_backtr(la, lb);
	else
		ft_printf("choose another alg\n");
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
	if (!setup(&argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&a_head, argc, args_arr);
	//print_lst(a_head, b_head);
	//alg_forwarding(&a_head, &b_head, argc);
	//int	lstsize = ft_lstsize(a_head);	
	//ft_printf(" len: %d\n", lstsize); 
	//int sort = is_sort_range(a_head, b_head);
	//ft_printf("%d", sort);
//	launch_backtr_simpl(&a_head);
	// ft_printf("%d", get_range_size(a_head, b_head));//
	alg_quick_sort(&a_head, &b_head);
//	print_lst(a_head, b_head);
	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);
}