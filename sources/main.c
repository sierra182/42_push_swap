/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/20 22:58:42 by marvin           ###   ########.fr       */
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

void	rec_qs(t_list **la_start, t_list **la_end, t_list **lb)
{
	t_list	*lstlast;
	t_list	*piv;
	int		flag;
	int		b_len;
	
	flag = 1;
	piv = get_middle(*la_start, *la_end);
	if ((*(int *) piv->content == *(int *) (*la_start)->content))
	{		
		sa(la_start, la_end);
		ft_printf("BZZZREHHHH\n");
		ft_printf("piv :%d\n", *(int *)piv->content);
		ft_printf("las :%d\n", *(int *)(*la_start)->content);
		ft_printf("lae :%d\n", *(int *)(*la_end)->content);		
		
		return ;
	}
	
	ft_printf("piv :%d\n", *(int *)piv->content);
	ft_printf("las :%d\n", *(int *)(*la_start)->content);
	ft_printf("lae :%d\n", *(int *)(*la_end)->content);
	
	while (*la_start != *la_end && flag || flag--)
	{
		// ft_printf("BLOUUUOOUUO\n");
		// ft_printf("las :%d\n", *(int *)(*la_start)->content);
		// ft_printf("lae :%d\n", *(int *)(*la_end)->content);
		//print_lst(*la_start, *lb);
		
		if (*(int *) (*la_start)->content < *(int *) piv->content)
	 		pb(la_start, lb);			
	 	else 
	 		ra(la_start, lb);
	}
	
	ft_printf("AV: ");	
	print_lst(*la_start, *lb);
	piv = *lb;
	//if (!lb_tmp || !lb_end_tmp)
		//return ;
	//t_list lb_tmp = *lb_start;
	//t_list *la_end_tmp = *la_start;
	b_len = ft_lstsize(*lb);
	while (b_len--)
		pa(la_start, lb);
	ft_printf("APRES: ");
	print_lst(*la_start, *lb);
	//piv = get_middle(*la_start, piv);
	
	t_list *la_tmp = *la_start;
	t_list *la_end_tmp = piv;
	t_list *lb_tmp = piv->next;
	t_list *lb_end_tmp = ft_lstlast(*la_start);
	ft_printf("\033[%dm", 96); //turquoise
	if (la_tmp)
		rec_qs(&la_tmp, &la_end_tmp, lb);	 //turquoise
	ft_printf("\033[%dm", 95);	// mauve
	lstlast = ft_lstlast(*la_start);
	//piv = get_middle(*la_start, lstlast);
	if (lb_tmp)
		rec_qs(&lb_tmp, &lb_end_tmp, lb);	// mauve
}

void	alg_quick_sort(t_list **la, t_list **lb)
{
	t_list	*lstlast;
	t_list	*piv;
	
	print_lst(*la, *lb);
	lstlast = ft_lstlast(*la);
	rec_qs(la, &lstlast, lb);
	ft_printf("Avant alg_quickS: ");
	print_lst(*la, *lb);
	//ft_printf("%d\n", *(int *) (*la)->content));
	//ft_printf("len :%d\n", len);
	// while (a_len--)
	// {//ft_printf("%d\n", *(int *) (*la)->content); 
	// 	if (*(int *) (*la)->content < *(int *) piv->content)
	// 		pb(la, lb);				
	// 	else 
	// 		ra(la, lb);			
	// }
	// print_lst(*la, *lb);
	// b_len = ft_lstsize(*lb);
	// while (b_len--)
	// {
	// 	pa(la, lb);
	// }
	//rec(la, lb);
	
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
	//alg_forwarding(&a_head, &b_head, argc);
	int	lstsize = ft_lstsize(a_head);	
	ft_printf(" len: %d\n", lstsize);
	alg_quick_sort(&a_head, &b_head);
			
	print_lst(a_head, b_head);	

	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);
}