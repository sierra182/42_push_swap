/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:06:34 by marvin            #+#    #+#             */
/*   Updated: 2023/11/30 14:06:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_UTILS_H
# define SETUP_UTILS_H

void 	del_arg(char *argv[]);
int 	has_twins(int argc, int *args_arr, int tocheck);
int 	is_overflow(char *s);
void 	free_stdargv(char **stdargv);
char 	**make_stdargv(int *argc, char *argv[], char *argv_save[]);
void 	init_args_arr(int argc, char *argv[], int **args_arr);

#endif