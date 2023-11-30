/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bubblesrt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:38:11 by svidot            #+#    #+#             */
/*   Updated: 2023/11/29 17:01:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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