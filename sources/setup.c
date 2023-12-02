/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:30:47 by marvin            #+#    #+#             */
/*   Updated: 2023/11/12 19:30:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "setup_utils.h"
#include <stdlib.h>

int	flag_detect(char **argv[])
{
	return ((**((*argv) + 1) == '-' && *(*((*argv) + 1) + 1) == 'v' 
		&& (*argv)++));
}

void init_list(t_list **lst, int argc, int *args_arr)
{
	static int *args_arr_stat;
	int *args_arr_save;
	t_list *new;
	
	if (args_arr)
		args_arr_stat = args_arr;
	args_arr_save = args_arr_stat;
	while (--argc)
	{
		new = ft_lstnew((void *)args_arr_stat++);
		if (!new)
		{
			free(args_arr_save);
			ft_lstclear(lst, NULL);
			exit(1);
		}
		ft_lstadd_back(lst, new);
	}
	args_arr_stat = args_arr_save;
}

void init_op_arr(int (*op_arr[])(t_list **, t_list **, int))
{
	op_arr[PA] = pa;
	op_arr[PB] = pb;
	op_arr[SA] = sa;
	op_arr[SB] = sb;
	op_arr[SS] = ss;
	op_arr[RA] = ra;
	op_arr[RB] = rb;
	op_arr[RR] = rr;
	op_arr[RRA] = rra;
	op_arr[RRB] = rrb;
	op_arr[RRR] = rrr;
}

void init_op_char_arr(char **op_char_arr)
{
	op_char_arr[PA] = "pa\n";
	op_char_arr[PB] = "pb\n";
	op_char_arr[SA] = "sa\n";
	op_char_arr[SB] = "sb\n";
	op_char_arr[SS] = "ss\n";
	op_char_arr[RA] = "ra\n";
	op_char_arr[RB] = "rb\n";
	op_char_arr[RR] = "rr\n";
	op_char_arr[RRA] = "rra\n";
	op_char_arr[RRB] = "rrb\n";
	op_char_arr[RRR] = "rrr\n";
}

int setup(int *argc, char *argv[], char *argv_save[], int **args_arr)
{
	char *s;
	int i;
	
	argv = make_stdargv(argc, argv, argv);	
	argv_save = argv;
	while (*++argv)
	{
		s = *argv;
		if ((*s == '-' || *s == '+') && ft_isdigit(*(s + 1)))
			s++;
		while (*s++)
			if (!ft_isdigit(*(s - 1)))
				return (free_stdargv(argv_save), 0);
		if (is_overflow(*argv) || !**argv)
			return (free_stdargv(argv_save), 0);
	}
	init_args_arr(*argc, argv_save, args_arr);
	i = 0;
	argv = argv_save;
	while (*++argv)
		if (has_twins(*argc - 1, *args_arr, (*args_arr)[i++]))
			return (free(*args_arr), free_stdargv(argv_save), 0);
	free_stdargv(argv_save);
	return (1);
}
