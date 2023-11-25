/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/25 11:42:45 by svidot           ###   ########.fr       */
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

t_list	*get_max_item(t_list *lst)
{
	t_list	*max_item;
	
	max_item = lst;
	while (lst)
	{
		if (*(int *) lst->content > *(int *) max_item->content)
			max_item = lst;
		lst = lst->next;
	}
	return (max_item);
}

t_list	*get_min_item(t_list *lst)
{
	t_list	*min_item;
	
	min_item = lst;
	while (lst)
	{
		if (*(int *) lst->content < *(int *) min_item->content)
			min_item = lst;
		lst = lst->next;
	}
	return (min_item);
}
#include <stdio.h>
#define GROUP 5

double	get_range(t_list *lst)
{
	double	range;
	int		min_value;
	int		max_value;
	
	range = 1;
	min_value = *(int *) get_min_item(lst)->content;
	max_value = *(int *) get_max_item(lst)->content;
	while (min_value != max_value--)
		range++;	
	return (range / GROUP);
}

int	is_in_actualpiece(int min_value, int actual_piece, int nbr, double range)
{	
	return (nbr >= min_value + (range * (actual_piece - 1)) && nbr <= min_value + (range * actual_piece));	
}
t_list	*get_top_item(t_list *lst, double range, int actual_piece)
{	
	int	min_value;
	
	min_value = *(int *) get_min_item(lst)->content;
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
	min_value = *(int *) get_min_item(lst)->content;
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

t_list	*choose_one(t_list **la, t_list **lb, int lstsize, t_list *top_item, t_list *bot_item, t_eop **sol_arr)
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
		{			
			ra(la, lb, 0);		
			*(*sol_arr)++ = RA;
		}		
	}
	else if (lstsize - bot_ind < top_ind)
	{	
		one = bot_item;
		while (lstsize-- - bot_ind)	
		{			
			rra(la, lb, 0);		
			*(*sol_arr)++ = RRA;
		}		
	}
		
	return (one);
}

void	set_secondlist(t_list **la, t_list **lb, t_list *one, int lstsize, t_eop **sol_arr)
{
	t_list	*to_up;
	t_list	*tmp;
	int		to_up_ind;

	tmp = *lb;
	to_up =  get_min_item(*lb);
	if (to_up && *(int *) to_up->content > *( int *) one->content)	
		to_up = get_max_item(*lb);	
	else 
	{
		while (tmp)
		{	
			if (*(int *) tmp->content > *(int *) to_up->content && *(int *) tmp->content < *(int *) one->content)
				to_up = tmp;
			tmp = tmp->next;
		}
	}	
	to_up_ind = get_item_index(*lb, to_up);
	if (to_up_ind > 0 && lstsize - to_up_ind >= to_up_ind)
	{	
		while (to_up_ind-- > 0)
		{			
			rb(la, lb, 0);				
			*(*sol_arr)++ = RB;
		}
	}
	else if (to_up_ind > 0)
	{		
		while (lstsize-- - to_up_ind)
		{
			rrb(la, lb, 0);				
			*(*sol_arr)++ = RRB;
		}
	}
}

void	rewind_secondlist(t_list **la, t_list **lb, int lstsize, t_eop *sol_arr[])
{	
	t_list	*to_up;
	int		to_up_ind;

	to_up =  get_max_item(*lb);	
	to_up_ind = get_item_index(*lb, to_up);
	if (to_up_ind > 0 && lstsize - to_up_ind >= to_up_ind) 
	{	
		while (to_up_ind-- > 0)
		{
			rb(la, lb, 0);				
			*(*sol_arr)++ = RB;
		}
	}
	else if (to_up_ind > 0)
	{		
		while (lstsize-- - to_up_ind)
		{		
			rrb(la, lb, 0);	
			*(*sol_arr)++ = RRB;
		}
	}
}
void	delone_sol(t_eop **sol_arr)
{//ft_printf("del deb\n");
	t_eop	*sol_sav;
	
	sol_sav = *sol_arr;
	while (*(*sol_arr + 1))
	{//ft_printf("del deb\n");
		**sol_arr = *(*sol_arr + 1); 
		(*sol_arr)++;
	}
	**sol_arr = 0;
	*sol_arr = sol_sav;
	//ft_printf("del fin\n");
}

void	sol_optim(t_eop **sol_arr)
{
	int		n_ra;
	int		n_rb;
	
	n_ra = 0;
	n_rb = 0;
	while (**sol_arr)
	{	
		n_ra = 0;	
		while (**sol_arr == RA)
		{		
			n_ra++;			
			(*sol_arr)++;
		}
		n_rb = 0;
		while ((**sol_arr == RB && n_ra--))
		{		
			*(*sol_arr - (++n_rb)) = RR;				
			delone_sol(sol_arr);			
		}
		n_ra = 0;
		while (**sol_arr == RRA)
		{		
			n_ra++;			
			(*sol_arr)++;
		}
		n_rb = 0;
		while ((**sol_arr == RRB && n_ra--))
		{		
			*(*sol_arr - (++n_rb)) = RRR;				
			delone_sol(sol_arr);			
		}				
		(*sol_arr)++;
	}
	
}
void	alg(t_list **la, t_list **lb)
{
	t_list	*top_item;
	t_list	*bot_item;
	t_list	*one;	
	int 	actual_piece;
	double	range;
	
	t_eop sl_arr[20000];
	
	int	i = -1;
	while (++i < 20000)
		sl_arr[i] = 0;
	t_eop *sol_arr = sl_arr;		
	range = get_range(*la);	
	actual_piece = 0;
	
	while (++actual_piece <= 5)
	{
		while (*la)
		{			
			top_item = get_top_item(*la, range, actual_piece);
			if (!top_item)		
				break;
			bot_item = get_bot_item(*la, range, actual_piece);		
			one = choose_one(la, lb, ft_lstsize(*la), top_item, bot_item, &sol_arr);
			if (one)
			{		
				set_secondlist(la, lb, one, ft_lstsize(*lb), &sol_arr);		
				pb(la, lb, 0);	
				*sol_arr++ = PB;					
			}					
			
		}	
	}
	rewind_secondlist(la, lb, ft_lstsize(*lb), &sol_arr);

	while (pa(la, lb, 0))
		*sol_arr++ = PA;
	
	sol_arr = sl_arr;
	char	*op_char_arr[OP];
	init_op_char_arr(op_char_arr);
	//print_tab(sol_arr, op_char_arr);
	sol_optim(&sol_arr);
//	ft_printf("choose another alg\n");
	sol_arr = sl_arr;
	print_tab(sol_arr, op_char_arr);
	//print_lst(*la, *lb);
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