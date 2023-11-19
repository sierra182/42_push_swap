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

void	init_op_char_arr(char **op_char_arr)
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

int	is_valid_op(char *s, char **op_char_arr)
{
	t_eop	op;

	op = 0;
	while (op++ < RRR)
		if (!ft_strcmp(op_char_arr[op], s))
			return (op);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*op_char_arr[OP];//[OP][5];
	char 	buffer[5];
	size_t	rd;

	init_op_char_arr(op_char_arr);
	int i = 0;
	while (i++ < OP)
		printf("%s", op_char_arr[i]);
	rd = 1;
	while (rd)
	{
		rd = read(0, buffer, 4);
		if (!rd)
			break;
		buffer[rd] = 0;
		printf("%s", buffer);
		if (is_valid_op(buffer, op_char_arr))
			
		else
			printf("Error\n");
		//printf("op: %d\n", is_valid_op(buffer, op_char_arr));
	}
	printf("%s\n", "fin");
}