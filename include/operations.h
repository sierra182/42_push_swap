/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:46:50 by svidot            #+#    #+#             */
/*   Updated: 2023/11/18 00:46:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "libft.h"

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