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

#include <unistd.h>
#include <stdio.h>
#include "operations.h"
#include "setup.h"
#include "ps_utils.h"
#include "ft_printf.h"
#include "get_next_line.h"

t_eop	is_valid_op(char *s, char **op_char_arr)
{
	t_eop	op;

	op = 0;
	while (op++ < RRR)
		if (!ft_strcmp(op_char_arr[op], s))
			return (op);
	return (0);
}

void	read_stdin()
{

}
int
int	error_input_handle(char *line, int *args_arr, t_list **la, t_list **lb)
{
	get_next_line(3);
	free(line);
	free(args_arr);
	ft_lstclear(la, NULL);
	ft_lstclear(lb, NULL);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	main(int argc, char *argv[])
{
	int 	(*op_arr[OP]) (t_list **, t_list **);
	char	*op_char_arr[OP];
	t_eop 	sol_input; 
	char 	buffer[5];
	int		*args_arr;
	char	*line;
	t_list	*a_head;
	t_list	*b_head;

	a_head = NULL;
	b_head = NULL;
	if (argc <= 1)
		return (1);
	if (!setup(&argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&a_head, argc, args_arr);	
	init_op_char_arr(op_char_arr);
	init_op_arr(op_arr);
	line = "l";
	while (line)
	{
		line = get_next_line(0);
		if (line)
		{
			sol_input = is_valid_op(line, op_char_arr);
			if (sol_input)			
				op_arr[sol_input](&a_head, &b_head);			
			else							 	
				return (error_input_handle(line, args_arr, &a_head, &b_head));
			free(line);
			line = "l";				
		}
	}
	print_lst(a_head, b_head);
	if (is_sort(a_head, b_head))
		ft_printf("\nOK\n");
	else 
		ft_printf("KO\n");
	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);	
}