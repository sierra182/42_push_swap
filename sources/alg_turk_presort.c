/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_turk_presort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:58:44 by svidot            #+#    #+#             */
/*   Updated: 2023/11/30 12:10:42 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	pre_sort(t_list **la, t_list **lb, int argc, int *args_arr)
{
	int	median;
	
	sort_list(*la);
	median = *(int *) get_middle(*la)->content;
	ft_lstclear(la, NULL);
	init_list(la, argc, args_arr);
	sort_by_pivot(la, lb, median);	
}

