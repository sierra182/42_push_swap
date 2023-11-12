/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/12 21:04:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "include/setup.h"
#include <unistd.h>
#include <stdlib.h>

#include "ft_printf/ft_printf.h"
#include "include/operation.h"
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
void	print_lst(t_list *lst)
{
	while (lst)
	{
		ft_printf("%d\n", *(int *) lst->content);
		lst = lst->next;
	}	
}

int	main(int argc, char *argv[])
{
	t_list	*a_head;
	t_list	*b_head;
	int		*args;
	
	a_head = NULL;
	b_head = NULL;
	if (argc <= 1)
		return (1);
	if (has_error(argv, argv, &args, argc))
		return (write(2, "Error\n", 6));
	init_list(&a_head, argc, argv, args);
	print_lst(a_head);
	// swap(a_head);
	// ft_printf("\n");
	// print_lst(a_head);
	// ft_printf("\n");
	// rot(&a_head);

	// print_lst(a_head);
	// ft_printf("\nb\n");
	// print_lst(b_head);
	// ft_printf("\n");

	// ft_printf("\n");
	// push(&a_head, &b_head);
	// print_lst(a_head);
	// ft_printf("\nb\n");
	// print_lst(b_head);
	// ft_printf("\n");
	// del_link(a_head->next, &a_head, a_head);
	// ft_printf("\n");
	// print_lst(a_head);
	// rot(&a_head);
	// ft_printf("\n");
	// print_lst(a_head);
	// rev_rot(&a_head);
	// ft_printf("\n");
	// print_lst(a_head);
	// push(&a_head, &b_head);
	// ft_printf("\n");
	// print_lst(a_head);
	// ft_printf("b\n\n");
	// print_lst(b_head);
	// 	push(&a_head, &b_head);
	// ft_printf("\n");
	// print_lst(a_head);
	// ft_printf("b\n\n");
	// print_lst(b_head);
	// 	push(&a_head, &b_head);
	// ft_printf("\n");
	// print_lst(a_head);
	// ft_printf("b\n\n");
	// print_lst(b_head);

	free(args);
	ft_lstclear(&a_head, NULL);
	// ft_lstclear(&b_head, NULL);
	return (0);
}