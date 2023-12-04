/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:53:39 by svidot            #+#    #+#             */
/*   Updated: 2023/12/04 06:53:39 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_UTILS_H
# define SETUP_UTILS_H

int		has_twins(int argc, int *args_arr, int tocheck);
int		is_overflow(char *s);
void	free_stdargv(char **stdargv);
char	**make_stdargv(int *argc, char *argv[], char *argv_save[]);
void	init_args_arr(int argc, char *argv[], int **args_arr);

#endif