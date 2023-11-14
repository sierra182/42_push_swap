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

#include <strings.h>

int		has_error(char *argv[], char *argv_save[], int **args, int argc);
void	*init_list(t_list **lst, int argc, char *argv[], int *args);

#endif