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

# include "operations.h"
# define MX_DEPTH 42

typedef struct s_listpack
{
	t_list	**la;
	t_list	**lb;
}	t_slistpack;

typedef struct s_depth
{
	int	depth;
	int	depth_max;
}	t_sdepth;

typedef struct s_backtr_utils
{
	t_eop	sol_arr[MX_DEPTH];
	int		(*op_arr[OP])(t_list **, t_list **, int);
	int		(*rev_op_arr[OP])(t_list **, t_list **, int);
}	t_sbacktr_utils;

void	launch_backtr(t_list **la, t_list **lb, int flag);
void	launch_backtr_simpl(t_list **la);

#endif