/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_backtr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:33:48 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 12:33:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALG_BACKTR_H
# define ALG_BACKTR_H

#include "operations.h"

void	init_op_arr(int (*op_arr[]) (t_list **, t_list **));
void	init_rev_op_arr(int (*rev_op_arr[]) (t_list **, t_list **));
int		rec(t_list **a_head, t_list **b_head, int depth, int depth_max, t_eop *sol_arr, int (*op_arr[]) (t_list **, t_list **), int (*rev_op_arr[]) (t_list **, t_list **));

#endif