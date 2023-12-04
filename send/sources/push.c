/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:51:02 by svidot            #+#    #+#             */
/*   Updated: 2023/12/04 06:51:02 by svidot           ###   ########.fr       */
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
