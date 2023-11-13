/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:54:13 by marvin            #+#    #+#             */
/*   Updated: 2023/11/12 19:54:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate_utils.h"
#include <unistd.h>

void	ra(t_list **lst)
{
	rotate(lst);
	write(1, "ra\n", 3);
}

void	rb(t_list **lst)
{
	rotate(lst);
	write(1, "rb\n", 3);
}

void	rr(t_list **la, t_list **lb)
{
	rotate(la);
	rotate(lb);
	write(1, "rr\n", 3);
}