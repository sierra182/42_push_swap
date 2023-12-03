/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/12/03 22:32:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "setup_utils.h"
#include "ps_utils.h"
#include "alg_backtr.h"
#include "alg_turk.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static void	alg_forwarding(t_list **la, t_list **lb, int argc, int flag)
{
	if (!is_sort(*la, *lb))
	{
		if (argc - 1 <= 5)
		{
			if (flag)
				ft_printf("\nwelcome to backtracking\n");
			launch_backtr(la, lb, flag);
		}
		else
		{
			pre_sort(la, lb, argc, NULL);
			alg_turk(la, *lb, lb, 0);
		}
	}
	if (flag)
		print_lst(*la, *lb);
}

int	main(int argc, char *argv[])
{
	int		*args_arr;
	int		flag;
	t_list	*la;
	t_list	*lb;

	la = NULL;
	lb = NULL;
	if (argc <= 1 || (argc <= 2 && **(argv + 1) == '-' \
		&& *(*(argv + 1) + 1) == 'v'))
		return (1);
	flag = flag_detect(&argv);
	if (!setup(&argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&la, argc, args_arr);
	alg_forwarding(&la, &lb, argc, flag);
	free(args_arr);
	ft_lstclear(&la, NULL);
	ft_lstclear(&lb, NULL);
	return (0);
}
