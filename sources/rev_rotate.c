/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:18:40 by marvin            #+#    #+#             */
/*   Updated: 2023/11/12 20:18:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate_utils.h"
#include <unistd.h>

int	rra(t_list **la, t_list **lb)
{
	write(1, "rra\n", 4);
	return (rev_rotate(la));
}

int	rrb(t_list **la, t_list **lb)
{
	write(1, "rrb\n", 4);
	return (rev_rotate(lb));
}

int	rrr(t_list **la, t_list **lb)
{
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