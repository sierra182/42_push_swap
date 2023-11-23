/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/23 07:42:03 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "setup.h"
#include "ps_utils.h"
#include "alg_backtr.h"
#include <unistd.h>
#include <stdlib.h>

#include "ft_printf.h"
#include "operations.h"
#include <stdio.h>

void	

void	alg_forwarding(t_list **la, t_list **lb, int argc)
{
	if (argc - 1 <= 7) 
		launch_backtr(la, lb);
	else
		ft_printf("choose another alg\n");
}

int	main(int argc, char *argv[])
{ 
	int		*args_arr;
	t_list	*a_head;
	t_list	*b_head;
	
	a_head = NULL;
	b_head = NULL;
	if (argc <= 1)
		return (1);
	if (!setup(&argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&a_head, argc, args_arr);
	//int	lstsize = ft_lstsize(a_head);	
	//ft_printf(" len: %d\n", lstsize); 	
	//print_lst(a_head, b_head);	
	//alg_forwarding(&a_head, &b_head, argc);
	//alg_quick_sort(&a_head, &b_head);

	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);
}