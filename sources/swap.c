/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:52:26 by marvin            #+#    #+#             */
/*   Updated: 2023/11/12 19:52:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

static void	swap_data(void **a, void **b)
{
	void	*tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;	
}

static int	swap(t_list *lst)
{	
	if (lst && lst->next)					
		swap_data(&lst->content, &lst->next->content);	
}

int	sa(t_list *lst)
{
	//write(1, "sa\n", 3);
	return (swap(lst));
}

int	sb(t_list *lst)
{
	//write(1, "sb\n", 3);
	return (swap(lst));
}

void	ss(t_list *la, t_list *lb)
{
	swap(la);
	swap(lb);
	//write(1, "ss\n", 3);
}
