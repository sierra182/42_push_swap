/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:51:14 by svidot            #+#    #+#             */
/*   Updated: 2023/12/04 06:51:14 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate_utils.h"
#include <unistd.h>

int	rra(t_list **la, t_list **lb, int wflag)
{
	(void) lb;
	if (wflag)
		write(1, "rra\n", 4);
	return (rev_rotate(la));
}

int	rrb(t_list **la, t_list **lb, int wflag)
{
	(void) la;
	if (wflag)
		write(1, "rrb\n", 4);
	return (rev_rotate(lb));
}

int	rrr(t_list **la, t_list **lb, int wflag)
{
	if (wflag)
		write(1, "rrr\n", 4);
	if (rev_rotate(la))
	{
		if (rev_rotate(lb))
			return (1);
		else
		{
			rotate(la);
			return (0);
		}
	}
	return (0);
}
