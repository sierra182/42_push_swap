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