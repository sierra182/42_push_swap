/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_turk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:29:43 by svidot            #+#    #+#             */
/*   Updated: 2023/11/30 12:34:59 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_list	*get_target(int value, t_list *lst)
{	
	t_list *target;

	target = get_max_item(lst);
	if (value > *(int *) target->content)
	 	target = get_min_item(lst);
	else
	{
		while (lst)
		{
			if (*(int *) lst->content < *(int *) target->content
					&& *(int *) lst->content > value)
				target = lst;
			lst = lst->next;
		}
	}
	return (target);
}