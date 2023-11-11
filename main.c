/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/11 16:45:18 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
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
		ft_printf("%s\n", ((char *) lst->content));
		lst = lst->next;
	}	
}
void	swap_data(void **a, void **b)
{
	void	*tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;	
}
void	swap(t_list *lst)
{						
	swap_data(&lst->content, &lst->next->content);	
}

int	main(int argc, char *argv[])
{
	t_list	*a_head;
	t_list	*b_head;
	t_list	*new;

	a_head = ft_lstnew((void *) *++argv);	
	while (*++argv)
	{
		new = ft_lstnew((void *) *argv);
		ft_lstadd_back(&a_head, new);		
	}	
	print_lst(a_head);
	swap(a_head);
	ft_printf("\n");
	print_lst(a_head);
	del_link(a_head->next, &a_head, a_head);
	ft_printf("\n");
	print_lst(a_head);
	return (0);
}