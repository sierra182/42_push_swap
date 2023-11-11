/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/11 21:09:33 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

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
	if (lst && lst->next)					
		swap_data(&lst->content, &lst->next->content);	
}
void	rot(t_list **lst)
{		
	t_list	*tmp;	
	
	if (*lst && (*lst)->next)
	{
		ft_lstadd_back(lst, *lst);
		tmp = (*lst)->next;
		(*lst)->next = NULL;
		*lst = tmp;
	}
}

void	rev_rot(t_list **lst)
{		
	t_list	*lstlast;
	int		lstsize;
	
	if (*lst && (*lst)->next)
	{
		lstsize = ft_lstsize(*lst);
		lstlast = ft_lstlast(*lst);
		ft_lstadd_front(lst, lstlast);
		while (--lstsize)
			*lst = (*lst)->next;
		(*lst)->next = NULL;
		*lst = lstlast; 
	}
}

void	push(t_list **tolow, t_list **toup)
{	
	t_list	*tmp;
	
	if (*tolow)
	{		
		tmp = (*tolow)->next;
		ft_lstadd_front(toup, *tolow);
		*tolow = tmp;
	}
}

int	ft_isspace(int c)
{
	return (c >= 9 && c <= 13 || c == 32);
}

int	has_error(char *argv[])
{
	char	*s;

	while (*++argv)
	{ 
		s = *argv;
		while (*s)
		{			
			if (*s == '-')
				s++;
			if (!ft_isdigit(*s++))
				return (1);	
		}
		// while (ft_isspace(*s))
		// 	s++;
		
		//argv++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*a_head;
	t_list	*b_head;
	t_list	*new;
	
	if (argc <= 1)
		return (1);
	if (has_error(argv))
		write(2, "Error\n", 6);
	// a_head = NULL;
	// b_head = NULL;
	// a_head = ft_lstnew((void *) *++argv);	
	// while (*++argv)
	// {
	// 	new = ft_lstnew((void *) *argv);
	// 	ft_lstadd_back(&a_head, new);		
	// }	
	// print_lst(a_head);
	// swap(a_head);
	// ft_printf("\n");
	// print_lst(a_head);
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

	
	return (0);
}