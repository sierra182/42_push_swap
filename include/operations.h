/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:46:50 by svidot            #+#    #+#             */
/*   Updated: 2023/11/19 12:26:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "libft.h"
#define OP 12

typedef enum e_op
{
	NONE,
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
} t_eop;

int	pa(t_list **la, t_list **lb);
int	pb(t_list **la, t_list **lb);

int	sa(t_list **la, t_list **lb);
int	sb(t_list **la, t_list **lb);
int	ss(t_list **la, t_list **lb);

int	ra(t_list **la, t_list **lb);
int	rb(t_list **la, t_list **lb);
int	rr(t_list **la, t_list **lb);

int	rra(t_list **la, t_list **lb);
int	rrb(t_list **la, t_list **lb);
int	rrr(t_list **la, t_list **lb);

#endif