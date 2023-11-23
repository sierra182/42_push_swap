/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_quicksrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 07:37:13 by svidot            #+#    #+#             */
/*   Updated: 2023/11/23 07:37:15 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			
	flag = 0;
	sort = is_sort_range(*la_start, *la_end);
	if (sort > 2)
		while (sort-- && ++flag)
			ra(la_start, la_end, 1);
	if (is_sort(*la_start, *lb))				
			return(1);		
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
			return(1);		
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
	t_list *new_lb_end = ft_lstlast(*la_start);
	if (first_play)
	{
		while (ra_count--)
			rra(la_start, lb, 1);
	}	
	else
		first_play = 1;	
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