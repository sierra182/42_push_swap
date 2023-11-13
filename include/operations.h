/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:46:50 by svidot            #+#    #+#             */
/*   Updated: 2023/11/13 20:52:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "libft.h"

void	pa(t_list **la, t_list **lb);
void	pb(t_list **la, t_list **lb);

void	sa(t_list *lst);
void	sb(t_list *lst);
void	ss(t_list *la, t_list *lb);

void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **la, t_list **lb);

void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **la, t_list **lb);

#endif