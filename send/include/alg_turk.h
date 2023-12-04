/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_turk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:52:55 by svidot            #+#    #+#             */
/*   Updated: 2023/12/04 06:52:55 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALG_TURK_H
# define ALG_TURK_H

# include "libft.h"

void	alg_turk(t_list	**la, t_list *lb_sav, t_list **lb, int ind_lb);
void	pre_sort(t_list **la, t_list **lb, int argc, int *args_arr);

#endif