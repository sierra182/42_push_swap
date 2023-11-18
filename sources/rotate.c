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

int	ra(t_list **lst)
{
	//write(1, "ra\n", 3);
	return (rotate(lst));
}

int	rb(t_list **lst)
{
	//write(1, "rb\n", 3);
	return (rotate(lst));
}

void	rr(t_list **la, t_list **lb)
{
	rotate(la);
	rotate(lb);
	//write(1, "rr\n", 3);
}