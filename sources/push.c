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

static int	push(t_list **tolow, t_list **toup)
{	
	t_list	*tmp;
	
	if (*tolow)
	{		
		tmp = (*tolow)->next;
		ft_lstadd_front(toup, *tolow);
		*tolow = tmp;
		return (1);
	}
	return (0);
}

int	pa(t_list **la, t_list **lb, int wflag)
{
	if (wflag)	
		write(1, "pa\n", 3);
	return (push(lb, la));
}

int	pb(t_list **la, t_list **lb, int wflag)
{
	if (wflag)	
		write(1, "pb\n", 3);
	return (push(la, lb));
}