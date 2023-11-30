/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_turk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:05:35 by marvin            #+#    #+#             */
/*   Updated: 2023/11/30 15:05:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALG_TURK_H
# define ALG_TURK_H

#include "libft.h"

void	alg_turk(t_list	**la, t_list *lb_sav, t_list **lb, int ind_lb);
void	pre_sort(t_list **la, t_list **lb, int argc, int *args_arr);

#endif