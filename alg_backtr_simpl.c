/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused_backtr_simpl.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:59:56 by marvin            #+#    #+#             */
/*   Updated: 2023/11/29 16:59:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_op_simpl
{
	NONE_SIMPL,	
	SB_SIMPL,	
	RB_SIMPL,	
	RRB_SIMPL	
} t_eop_simpl;

void	print_tab_simpl(t_eop_simpl *sol_arr, char **op_char_arr)
{	
	while (*sol_arr)	
		ft_printf("%s", op_char_arr[*sol_arr++]);	
}

void	init_op_char_arr_simpl(char **op_char_arr)
{
	op_char_arr[SB_SIMPL] = "sb\n";
	op_char_arr[RB_SIMPL] = "rb\n";
	op_char_arr[RRB_SIMPL] = "rrb\n";
}

void	init_op_arr_simpl(int (*op_arr[]) (t_list **, t_list **, int))
{			
	op_arr[SB_SIMPL] = sb;	
	op_arr[RB_SIMPL] = rb;
	op_arr[RRB_SIMPL] = rrb;	
}

int	is_sort_simpl(t_list *lst)
{	
	while (lst->next)
	{
		if (*(int *) lst->content > *(int *) lst->next->content)
			return (0);
		lst = lst->next;		
	}	
	return (1);
}

void	init_rev_op_arr_simpl(int (*rev_op_arr[]) (t_list **, t_list **, int))
{		
	rev_op_arr[SB_SIMPL] = sb;
	rev_op_arr[RB_SIMPL] = rrb;
	rev_op_arr[RRB_SIMPL] = rb;	
}


int	rec_simpl(t_list **lst, int depth, int depth_max, t_eop_simpl *sol_arr, int (*op_arr[]) (t_list **, t_list **, int), int (*rev_op_arr[]) (t_list **, t_list **, int))
{	
	t_eop_simpl op;
	
	if (is_sort_simpl(*lst))
		return (1);					
	else if (depth >= depth_max)						
		return (0);		
	depth++;
	op = NONE_SIMPL;
	while (++op <= RRB_SIMPL)
	{
		if (op_arr[op](lst, lst, 0))
		{			
			sol_arr[depth - 1] = op;
			if (rec_simpl(lst, depth, depth_max, sol_arr, op_arr, rev_op_arr))		
				return (1);
			rev_op_arr[op](lst, lst, 0);		
		}	
	}	
	sol_arr[depth - 1] = 0;
	return (0);
}

void	launch_backtr_simpl(t_list **lst)
{
	char		*op_char_arr[OP];
	t_eop_simpl	sol_arr[MX_DEPTH];
	int			depth_max;

	depth_max = 0;	
	int	i = -1;
	while (++i < MX_DEPTH)
		sol_arr[i] = 0;
	int (*op_arr[OP]) (t_list **, t_list **, int);
	int (*rev_op_arr[OP]) (t_list **, t_list **, int);
	init_op_arr_simpl(op_arr);
	init_rev_op_arr_simpl(rev_op_arr);	
	while (!rec_simpl(lst, 0, depth_max, sol_arr, op_arr, rev_op_arr))
		depth_max++;	
	init_op_char_arr_simpl(op_char_arr);
	print_tab_simpl(sol_arr, op_char_arr);			
}