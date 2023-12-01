/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:48:15 by marvin            #+#    #+#             */
/*   Updated: 2023/11/19 15:48:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "setup.h"
#include "ps_utils.h"
#include "ft_printf.h"
#include "get_next_line.h"
#include <unistd.h>

int	error_input_handle(char *line, int *args_arr, t_list **la, t_list **lb)
{
	get_next_line(3);
	free(line);
	free(args_arr);
	ft_lstclear(la, NULL);
	ft_lstclear(lb, NULL);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_eop	is_valid_op(char *s)
{
	t_eop	op;
	char	*op_char_arr[OP];

	init_op_char_arr(op_char_arr);
	op = 0;
	while (op++ < RRR) 
		if (!ft_strcmp(op_char_arr[op], s))
			return (op);
	return (0);
}

void	read_stdin(t_list **la, t_list **lb, int *args_arr)
{
	char	*line;
	t_eop 	sol_input;
	int 	(*op_arr[OP]) (t_list **, t_list **, int);

	init_op_arr(op_arr);
	line = "l";
	while (line)
	{
		line = get_next_line(0);
		if (line)
		{
			sol_input = is_valid_op(line);
			if (sol_input)			
				op_arr[sol_input](la, lb, 0);			
			else							 	
				error_input_handle(line, args_arr, la, lb);
			free(line);
			line = "l";				
		}
	}
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
	if (!is_sort(a_head, b_head))
		read_stdin(&a_head, &b_head, args_arr);
	print_lst(a_head, b_head); // !!!!!!!!!!!!!!!!!!!!!!
	if (is_sort(a_head, b_head))
		ft_printf("OK\n");
	else 
		ft_printf("KO\n");
	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);	
}