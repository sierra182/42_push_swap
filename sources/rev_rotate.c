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

void	rra(t_list **lst)
{
	rev_rotate(lst);
	//write(1, "rra\n", 4);
}

void	rrb(t_list **lst)
{
	rev_rotate(lst);
	//write(1, "rrb\n", 4);
}

void	rrr(t_list **la, t_list **lb)
{
	rev_rotate(la);
	rev_rotate(lb);
	//write(1, "rrr\n", 4);
}