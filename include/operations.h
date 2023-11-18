/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:46:50 by svidot            #+#    #+#             */
/*   Updated: 2023/11/18 22:34:10 by marvin           ###   ########.fr       */
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

// union u_op
// {
// 	int		(*pa)(t_list **la, t_list **lb);
// 	int		(*pb)(t_list **la, t_list **lb);

// 	int		(*sa)(t_list *lst);
// 	int		(*sb)(t_list *lst);
// 	void	(*ss)(t_list *la, t_list *lb);

// 	int		(*ra)(t_list **lst);
// 	int		(*rb)(t_list **lst);
// 	void	(*rr)(t_list **la, t_list **lb);

// 	int		(*rra)(t_list **lst);
// 	int		(*rrb)(t_list **lst);
// 	void	(*rrr)(t_list **la, t_list **lb);
// };

union u_op
{
	int	(*uni_sp[2])(t_list *lst);
	int	(*uni_dp[4])(t_list **lst);
	int	(*bi_sp[1])(t_list *la, t_list *lb);
	int	(*bi_dp[4])(t_list **la, t_list **lb);
};

typedef struct s_op
{	
	union u_op	op;
} t_sop;

int		pa(t_list **la, t_list **lb);
int		pb(t_list **la, t_list **lb);

int		sa(t_list *lst);
int		sb(t_list *lst);
void	ss(t_list *la, t_list *lb);

int		ra(t_list **lst);
int		rb(t_list **lst);
void	rr(t_list **la, t_list **lb);

int		rra(t_list **lst);
int		rrb(t_list **lst);
void	rrr(t_list **la, t_list **lb);

#endif