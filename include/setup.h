/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:31:26 by marvin            #+#    #+#             */
/*   Updated: 2023/11/12 19:31:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
 #define SETUP_H

int		setup(int *argc, char *argv[], char *argv_save[], int **args);
void	init_list(t_list **lst, int argc, int *args_arr);
void	init_op_arr(int (*op_arr[]) (t_list **la, t_list **lb, int wflag));
void	init_op_arr_simpl(int (*op_arr[]) (t_list **la, t_list **lb, int wflag));
void	init_op_char_arr(char **op_char_arr);
void	init_op_char_arr_simpl(char **op_char_arr);

#endif