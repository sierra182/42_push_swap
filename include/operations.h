/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:46:50 by svidot            #+#    #+#             */
/*   Updated: 2023/11/22 20:17:25 by marvin           ###   ########.fr       */
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

typedef enum e_op_simpl
{
	NONE_SIMPL,	
	SB_SIMPL,	
	RB_SIMPL,	
	RRB_SIMPL	
} t_eop_simpl;

int	pa(t_list **la, t_list **lb, int wflag);
int	pb(t_list **la, t_list **lb, int wflag);

int	sa(t_list **la, t_list **lb, int wflag);
int	sb(t_list **la, t_list **lb, int wflag);
int	ss(t_list **la, t_list **lb, int wflag);

int	ra(t_list **la, t_list **lb, int wflag);
int	rb(t_list **la, t_list **lb, int wflag);
int	rr(t_list **la, t_list **lb, int wflag);

int	rra(t_list **la, t_list **lb, int wflag);
int	rrb(t_list **la, t_list **lb, int wflag);
int	rrr(t_list **la, t_list **lb, int wflag);

#endif