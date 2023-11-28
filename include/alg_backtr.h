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

#define MX_DEPTH 420

#include "operations.h"

void	launch_backtr(t_list **la, t_list **lb, int flag);
void	launch_backtr_simpl(t_list **la);

#endif