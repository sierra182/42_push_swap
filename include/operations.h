/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:46:50 by svidot            #+#    #+#             */
/*   Updated: 2023/11/19 11:27:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "libft.h"
#define OP 12

// typedef enum e_op
// {
// 	NONE,
	
// 	SS,
	
// 	SA,
// 	SB,
	
// 	PA,
// 	PB,
// 	RR,
// 	RRR,
	
// 	RA,
// 	RB,
// 	RRA,
// 	RRB,
// } t_eop;

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
	int	(*un_sp)(t_list *lst);
	int	(*un_dp)(t_list **lst);
	int	(*bi_sp)(t_list *la, t_list *lb);
	int	(*bi_dp)(t_list **la, t_list **lb);
};

typedef struct s_op
{	
	union u_op	op;
} t_sop;

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