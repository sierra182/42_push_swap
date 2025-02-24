/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:51:42 by svidot            #+#    #+#             */
/*   Updated: 2023/12/04 06:51:42 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate_utils.h"
#include <unistd.h>

int	ra(t_list **la, t_list **lb, int wflag)
{
	(void) lb;
	if (wflag)
		write(1, "ra\n", 3);
	return (rotate(la));
}

int	rb(t_list **la, t_list **lb, int wflag)
{
	(void) la;
	if (wflag)
		write(1, "rb\n", 3);
	return (rotate(lb));
}

int	rr(t_list **la, t_list **lb, int wflag)
{
	if (wflag)
		write(1, "rr\n", 3);
	if (rotate(la))
	{
		if (rotate(lb))
			return (1);
		else
		{
			rev_rotate(la);
			return (0);
		}
	}
	return (0);
}
