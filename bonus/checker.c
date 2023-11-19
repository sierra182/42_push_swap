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
#include "ft_printf.h"
#include "get_next_line.h"

void	init_op_arr(int (*op_arr[]) (t_list **, t_list **))
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

t_eop	is_valid_op(char *s, char **op_char_arr)
{
	t_eop	op;
//printf("is valid: %s\n", s);
	op = 0;
	while (op++ < RRR)
		if (!ft_strcmp(op_char_arr[op], s))
			return (op);
	return (0);
}

int	apply_sol(t_eop *sol_arr, int (*op_arr[]) (t_list **, t_list **), t_list **la, t_list **lb)
{
	while (*sol_arr)	
		op_arr[*sol_arr++](la, lb);
}

int	is_sort(t_list *la, t_list *lb)
{
	if (ft_lstsize(lb))
		return (0);
	while (la->next)
	{
		if (*(int *) la->content > *(int *) la->next->content)
			return (0);
		la = la->next;		
	}	
	return (1);
}

void	print_lst(t_list *la, t_list *lb)
{	
	ft_printf("\n\033[%dm", 96);
	ft_printf(" ~~~~~~~~~~~~~~~~~~~~ ~~(,,°>\n");
	ft_printf("\033[0m");
	while (la || lb)
	{
		if (la)
		{
			ft_printf(" %d", *(int *) la->content);
			la = la->next;
		}
		ft_printf("\r\t\t\b\b\b|*|  ");
		if (lb)
		{
			ft_printf(" %d", *(int *) lb->content);
			lb = lb->next;			
		}
		ft_printf("\n");		
	}
	ft_printf("\n");	
}

int	main(int argc, char *argv[])
{
	int 	(*op_arr[OP]) (t_list **, t_list **);
	char	*op_char_arr[OP];
	t_eop 	sol_arr[1]; 
	char 	buffer[5];
	size_t	rd;//
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

	line = "1";
	while (line)
	{
		line = get_next_line(0);
		if (line)
		{
			sol_arr[0] = is_valid_op(line, op_char_arr);
			if (sol_arr[0])
			{
				apply_sol(sol_arr, op_arr, &a_head, &b_head);
				//print_lst(a_head, b_head);		
			}
			else
			{		 	
				printf("Error\n");
			}
		}
	}
	// int i = 0;
	// while (i++ < OP)
	// 	printf("%s", op_char_arr[i]);

	//rd = 1;
	// while (rd)
	// { get_next_line(0);
	// 	rd = read(0, buffer, 4);
	// 	if (!rd)
	// 		break;
	// 	buffer[rd] = 0;
	// 	//printf("%s", buffer);		
	// 	sol_arr[0] = is_valid_op(buffer, op_char_arr);
	// //	if (sol_arr[0])
	// //	{
	// 		apply_sol(sol_arr, op_arr, &a_head, &b_head);
	// 		//print_lst(a_head, b_head);		
	// //	}
	// 	// else
	// 	// {
	// 	// 	printf("solarr :%d\n", sol_arr[0]);
	// 	// 	printf("Error\n");
	// 	// }
	// 	//printf("op: %d\n", is_valid_op(buffer, op_char_arr));
	//}
	print_lst(a_head, b_head);
	if (is_sort(a_head, b_head))
		ft_printf("\nOK\n");
	else 
		ft_printf("KO\n");
	ft_printf("%s\n", "fin");
}