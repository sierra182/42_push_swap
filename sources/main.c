/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/19 21:38:37 by marvin           ###   ########.fr       */
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

void	del_link(t_list *link, t_list **lst, t_list *lstsave)
{
	t_list	*lstnext;

	while (*lst)
	{
		if (*lst == link)
		{
			lstnext = (*lst)->next;
			free(*lst);
			*lst = lstnext;
			break ;
		}
		else if ((*lst)->next == link)
		{
			lstnext = (*lst)->next->next;
			free((*lst)->next);
			(*lst)->next = lstnext;
			*lst = lstsave;
			break ;
		}
		*lst = (*lst)->next;
	}	
}

// t_list	*sort_list(t_list* lst)
// {
// 	t_list *tmp;
	
// 	tmp = lst;
// 	while (tmp->next)
// 	{
// 		if (*(int *) tmp->content > *(int *) tmp->next->content)
// 		{
// 			sa(tmp);
// 			tmp = lst;
// 		}
// 		else		
// 			tmp = tmp->next;		
// 	}
// 	return (lst);
// }

// t_list	*alg_sort_list(t_list *lst)
// {
// 	t_list *tmp;
// 	int		i;
// 	int		j;	
// 	int		len;
	
// 	len  = ft_lstsize(lst);
// 	i = 0;
// 	j = 0;
// 	tmp = lst;
// 	while (j++ < len - 1)
// 	{
// 		if (*(int *) tmp->content > *(int *) tmp->next->content)
// 		{
// 			j = 0;		
// 			sa(tmp);
// 			while (i && i--)			
// 				rra(&tmp);			
// 		}
// 		else
// 		{		
// 			ra(&tmp);			
// 			i++;				
// 		}
// 	}
// 	ra(&tmp);
// 	return (lst);
// }

int	main(int argc, char *argv[])
{
	int		*args_arr;
	t_list	*a_head;
	t_list	*b_head;
	char	*op_char_arr[OP];
	
	a_head = NULL;
	b_head = NULL;
	if (argc <= 1)
		return (1);
	if (!setup(&argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&a_head, argc, args_arr);

	//int	lstsize = ft_lstsize(a_head);	
	//ft_printf(" len: %d\n\n", lstsize);
	
	int	depth_max = 0;
	t_eop sol_arr[42]; 
	int	i = -1;
	while (++i < 42)
		sol_arr[i] = 0;
	int (*op_arr[OP]) (t_list **, t_list **);
	int (*rev_op_arr[OP]) (t_list **, t_list **);
	init_op_arr(op_arr);
	init_rev_op_arr(rev_op_arr);
	init_op_char_arr(op_char_arr);
	while (!rec(&a_head, &b_head, 0, depth_max, sol_arr, op_arr, rev_op_arr))
		depth_max++;	
	print_tab(sol_arr, op_char_arr);	

	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);
}