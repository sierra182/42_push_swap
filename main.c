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
#include <limits.h>

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

int	has_twins(int *args, int argc, int tocheck)
{	
	int res;

	res = 0;
	while (argc--)
	{   
		if (args[argc] == tocheck)
			res++;
		if (res >= 2)
			return (res);	
	}
	return (0);
}

int	is_overflow(char *s)
{
	long	nbr;
	int		isneg;

	nbr = 0;
	isneg = 0;	
	if (*s == '-' && ++isneg)
		s++;
	else if (*s == '+')
		s++;
	while (*s)
	{
		nbr = nbr * 10 + *s++ - 48;
		if (nbr - isneg > INT_MAX)
			return (1);
	}
	return (0);
}

int	ft_isspace(int c)
{
	return (c >= 9 && c <= 13 || c == 32);
}

int	init_args_arr(int **args, char *argv[],  int argc)
{
	*args = (int *) malloc(sizeof(int) * (argc - 1));
	
	while (*++argv)	
		*(*args)++ = ft_atoi(*argv);
	*args = (*args) - (argc - 1);	
}

int	has_error(char *argv[], char *argv_save[], int **args, int argc)
{
	char	*s;	
	int		i;

	while (*++argv)
	{ 
		s = *argv;		
		if ((*s == '-' || *s == '+') && ft_isdigit(*(s + 1)))
			s++;
		while (*s++)		
			if (!ft_isdigit(*(s - 1)))
				return (1);
		if (is_overflow(*argv))
			return (1);		
	}
	init_args_arr(args, argv_save, argc);
	i = 0;
	argv = argv_save;
	while (*++argv)	
		if (has_twins(*args, argc - 1, (*args)[i++]))
			return (free(*args), 1);	
	return (0);
}

int	*init_list(t_list **lst, int argc, char *argv[], int *args)
{
	t_list	*new;
	
	while (*++argv)
	{			
		new = ft_lstnew((void *) args++);
		ft_lstadd_back(lst, new);
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