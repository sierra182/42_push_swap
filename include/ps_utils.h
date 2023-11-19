/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:25:37 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 21:25:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_UTILS_H
 #define PS_UTILS_H

#include "libft.h"
#include "operations.h"

int		is_sort(t_list *la, t_list *lb);
void	print_lst(t_list *la, t_list *lb);
void	print_tab(t_eop *sol_arr, char **op_char_arr);

#endif