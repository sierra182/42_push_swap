/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:51:42 by marvin            #+#    #+#             */
/*   Updated: 2023/11/12 19:51:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	push(t_list **tolow, t_list **toup)
{	
	t_list	*tmp;
	
	if (*tolow)
	{		
		tmp = (*tolow)->next;
		ft_lstadd_front(toup, *tolow);
		*tolow = tmp;
	}
}

void	pa(t_list **la, t_list **lb)
{
	push(lb, la);
	//write(1, "pa\n", 3);
}

void	pb(t_list **la, t_list **lb)
{
	push(la, lb);
	//write(1, "pb\n", 3);
}