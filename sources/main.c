/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/23 21:01:29 by marvin           ###   ########.fr       */
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
#include <stdio.h>
#define GROUP 5

double	get_range(t_list *lst)
{
	double	range;
	int		min_value;
	int		max_value;
	
	range = 1;
	min_value = get_min_value(lst);
	max_value = get_max_value(lst);
	while (min_value != max_value--)
		range++;
	//printf("range: %f\n", range);
	return (range / GROUP);
}

int	is_in_actualpiece(int min_value, int actual_piece, int nbr, double range)
{	
	//printf("range: %f\n", range);
	//printf("range: %d, %f\n", (int) (min_value + (range * (actual_piece - 1))), (min_value + (range * actual_piece)));
	return (nbr >= min_value + (range * (actual_piece - 1)) && nbr <= min_value + (range * actual_piece));	
}
t_list	*get_top_item(t_list *lst, double range, int actual_piece)
{	
	int	min_value;
	
	min_value = get_min_value(lst);
	while (lst)
	{
		if (is_in_actualpiece(min_value, actual_piece, *(int *) lst->content, range))
			return (lst); 
		lst = lst->next;
	}
	return (NULL);		
}

t_list	*get_bot_item(t_list *lst, double range, int actual_piece)
{	
	int		min_value;
	t_list	*bot_item;
	
	bot_item = NULL; 
	min_value = get_min_value(lst);
	while (lst)
	{
		if (is_in_actualpiece(min_value, actual_piece, *(int *) lst->content, range))
			bot_item = lst; 
		lst = lst->next;
	}
	return (bot_item);
}
int	get_item_index(t_list *lst, t_list *item)
{
	int	i;

	i = 0;
	while (lst && ++i)
	{
		if (lst == item)
			return (--i);
		lst = lst->next;
	}
	return (--i);
}

t_list	*choose_one(t_list **la, t_list **lb, int lstsize, t_list *top_item, t_list *bot_item)
{
	t_list	*one;
	int		top_ind;
	int		bot_ind;
	
	top_ind = 0;
	bot_ind = 0;
	one = NULL;
	if (!top_item && !bot_item)
		return (NULL);
	if (top_item)
		top_ind = get_item_index(*la, top_item);
	if (bot_item) 
		bot_ind = get_item_index(*la, bot_item);	
	if (lstsize - bot_ind >= top_ind)
	{
		one = top_item;
		while (top_ind--)
			ra(la, lb, 1);
		//pb(la, lb, 1);	
	}
	else if (lstsize - bot_ind < top_ind)
	{
		one = bot_item;
		while (lstsize-- - bot_ind)
			rra(la, lb, 1);
		//pb(la, lb, 1);
	}
	return (one);
}
void	set_second_list(t_list *one, t_list **lst)
{
	while (*lst)
	{
		if (*(int *) (*lst)->content > *(int *) one->content)
			
		*lst = (*lst)->next;
	}
}
void	alg(t_list **la, t_list **lb)
{
	t_list	*top_item;
	t_list	*bot_item;
	t_list	*one;	
	int 	actual_piece;
	double	range;
	
	range = get_range(*la);
	actual_piece = 0;
	while (++actual_piece <= 5)
	{
		while (*la)
		{			
			top_item = get_top_item(*la, range, actual_piece);
			if (top_item)
				ft_printf("top item: %d, actual p : %d\n", *(int *) top_item->content, actual_piece);
			else
				break;//ft_printf("null top\n");
			bot_item = get_bot_item(*la, range, actual_piece);
			if (bot_item)
				ft_printf("bot item: %d, actual p : %d\n", *(int *) bot_item->content, actual_piece);
			else
				ft_printf("null bot\n");
			one = choose_one(la, lb, ft_lstsize(*la), top_item, bot_item);
			if (one)
			{
				set_secondlist(one, lb);
				pb(la, lb, 1);
				ft_printf("%d\n", *(int *) one->content);
			}
			else
				ft_printf("NULL\n");
			print_lst(*la, *lb);		
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
	int 	range;
	t_list	*a_head;
	t_list	*b_head;
	
	a_head = NULL;
	b_head = NULL;
	if (argc <= 1)
		return (1);
	if (!setup(&argc, argv, argv, &args_arr))
		return (write(2, "Error\n", 6));
	init_list(&a_head, argc, args_arr);
	//_printf("%d\n", range);	
	//ft_printf("%d\n", is_in_actualpiece(4, 580, range));
	alg(&a_head, &b_head);
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