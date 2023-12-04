/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:53:47 by svidot            #+#    #+#             */
/*   Updated: 2023/12/04 06:53:47 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "libft.h"

int		flag_detect(char **argv[]);
void	init_list(t_list **lst, int argc, int *args_arr);
void	init_op_arr(int (*op_arr[])(t_list **, t_list **, int));
void	init_op_char_arr(char **op_char_arr);
int		setup(int *argc, char *argv[], char *argv_save[], int **args);

#endif