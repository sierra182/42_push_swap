/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:06:54 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 21:06:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"
#include "ft_printf.h"

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

void	print_tab(t_eop *sol_arr, char **op_char_arr)
{	
	while (*sol_arr)	
		ft_printf("%s", op_char_arr[*sol_arr++]);	
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

void	apply_sol(t_list **la, t_list **lb, int *sol)
{
	t_eop	op;
	static int 	(*op_arr[OP]) (t_list **, t_list **, int); 
	
	if (!op_arr[PA])	
		init_op_arr(op_arr);	
	op = 0;
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

void	rewind_lst(t_list **la, t_list **lb, int lstsize)
{
	int		target_ind;

	target_ind = get_item_index(*la, get_min_item(*la));
	if (target_ind > 0 && lstsize - target_ind >= target_ind)
		while (target_ind--)
			ra(la, lb, 1);
	else if (target_ind)
		while (lstsize-- - target_ind)
			rra(la, lb, 1);
}

void	swap_data(void **a, void **b);

void	sort_list(t_list* lst)
{
	t_list *ref;
	
	ref = lst;
	while (lst)
	{
		if (*(int *) lst->content < *(int *) ref->content)		
			swap_data(&lst->content, &ref->content);	
		else if (!lst->next)
		{
			ref = ref->next;
			lst = ref;
		}
		else		
			lst = lst->next;		
	}	
}