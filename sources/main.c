/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/30 11:49:00 by svidot           ###   ########.fr       */
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

#include <stdio.h>

void	alg_forwarding(t_list **la, t_list **lb, int argc, int *args_arr, int flag)
{
	if (argc - 1 <= 6)
	{
		if (flag)
			ft_printf("\nwelcome to backtracking\n");
		launch_backtr(la, lb, flag);
	}
	else
	{
		pre_sort(la, lb, argc, args_arr);
		alg_turk(la, *lb, lb, 0);
		if (flag)
			ft_printf("\n    .- ¨\n    }    \n   °\n °*       .!*¨****°\n**       **°    *)\n+: +:+         +°\n \
		+#  -+.+       +|'\n+=1=+=1=1=-   +-\n     #+#    °°<...-.\n     °#+   °%%%%%%%%%%°%%%%$  <~°~~-~~°-°-\n");
	}
	if (flag)
		print_lst(*la, *lb);
}

int	main(int argc, char *argv[])
{ 
	int		*args_arr;
	int 	range;
	int		flag;
	t_list	*la;
	t_list	*lb;
	
	la = NULL;
	lb = NULL;
	flag = 0;
	if (argc <= 1)
		return (1);
	if (argv[1][0] == '-' && argv[1][1] == 'v' && ++flag)
		del_arg(argv); ///!!!!!
	if (!setup(&argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&la, argc, args_arr);
	if (!is_sort(la, lb))
	 	alg_forwarding(&la, &lb, argc, args_arr, flag);		
	free(args_arr);
	ft_lstclear(&la, NULL);
	ft_lstclear(&lb, NULL);
	return (0);
}
