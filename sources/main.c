/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/23 10:03:55 by svidot           ###   ########.fr       */
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

int	get_max_value(t_list *lst)
{
	int	max_value;
	
	max_value = *(int *) lst->content;
	while (lst)
	{
		if (*(int *) lst->content > max_value)
			max_value = *(int *) lst->content;
		lst = lst->next;
	}
	return (max_value);
}

int	get_min_value(t_list *lst)
{
	int	min_value;
	
	min_value = *(int *) lst->content;
	while (lst)
	{
		if (*(int *) lst->content < min_value)
			min_value = *(int *) lst->content;
		lst = lst->next;
	}
	return (min_value);
}

int	calculate_maxrange(t_list *lst)
{
	int	range;
	int	min_value;
	int	max_value;
	
	range = 1;
	min_value = get_min_value(lst);
	max_value = get_max_value(lst);
	while (min_value != max_value--)
		range++;
	return (range);
}

int	is_in_actualpiece(int actualpiece, int nbr, int range)
{	
	return (nbr >= (actualpiece - 1) * range && nbr <= (actualpiece) * range);	
}

void	alg(t_list *la, t_list *lb)
{
	int 	actual_piece;
	t_list	*lstlast;
	
	lstlast = ft_lstlast(la);
	actual_piece = 0;
	while (++actual_piece <= 5)
	{
		while (la)
		{
			
			la = la->next;
		}
	}
}

void	alg_forwarding(t_list **la, t_list **lb, int argc)
{
	if (argc - 1 <= 7) 
		launch_backtr(la, lb);
	else
		ft_printf("choose another alg\n");
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
	
	//ft_printf("%d\n", calculate_maxrange(a_head) / 5);	
	ft_printf("%d\n", is_in_actualpiece(4, 580, calculate_maxrange(a_head) / 5));
	
	//int	lstsize = ft_lstsize(a_head);	
	//ft_printf(" len: %d\n", lstsize); 	
	//print_lst(a_head, b_head);	
	//alg_forwarding(&a_head, &b_head, argc);
	//alg_quick_sort(&a_head, &b_head);

	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);
}