/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:45:00 by svidot            #+#    #+#             */
/*   Updated: 2023/11/26 12:08:39 by marvin           ###   ########.fr       */
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

double	get_range(t_list *lst, int n_piece)
{
	double	range;
	int		min_value;
	int		max_value;
	
	range = 1;
	min_value = *(int *) get_min_item(lst)->content;
	max_value = *(int *) get_max_item(lst)->content;
	while (min_value != max_value--)
		range++;	
	return (range / n_piece);
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
// void	delone_sol(t_eop **sol_arr)
// {//ft_printf("del deb\n");
// 	t_eop	*sol_sav;
	
// 	sol_sav = *sol_arr;
// 	while (*(*sol_arr + 1))
// 	{//ft_printf("del deb\n");
// 		**sol_arr = *(*sol_arr + 1); 
// 		(*sol_arr)++;
// 	}
// 	**sol_arr = 0;
// 	*sol_arr = sol_sav;
// 	//ft_printf("del fin\n");
// }
void	delone_sol(t_eop *sol_arr)
{//ft_printf("del deb\n");

	while (*sol_arr)
	{//ft_printf("del deb\n");
		*sol_arr = *(sol_arr + 1); 
		sol_arr++;
	}
	
	//ft_printf("del fin\n");
}
void	try_rr(t_eop **sol_arr, int n_ra, int n_rb, int seclst_size)
{
	int	need;
	int gain;
	//ft_printf("TRYRR\n");
	need = seclst_size - n_rb;// need = 2;
	gain = n_ra - need;
	// ft_printf("TRY need:%d, gain: %d\n", need, gain);	
	// ft_printf("TRY AVANT MY INSIDE gain:%d, -gain: %d, n_rb: %d\n", gain, -gain, n_rb);
	if (gain >= 0 || -gain < n_rb)
	{
		//ft_printf("TRY INSIDEMAN  gain: %d, -gain: %d n_rb: %d\n", gain, -gain, n_rb);	
		// les cas ou il y a sudffisamment dans nra pour combler need act ou que meme avec le manque n_ra est quand meme superieur en action
		//	replby_rr(need_act);
		(*sol_arr)--;
		while (**sol_arr == RRB) // suppr tous les rrb et autant de ra quil y aura de rr 
		{	//	ft_printf("JE SUPPRIME UN RRB\n"); 
			delone_sol(*sol_arr);
			//ft_printf("JAI FINIT DE LE SUPPRIMER\n"); 
			//*(*sol_arr - (++n_rb)) = RRR;
			//ft_printf("OPERATE\n");	
				(*sol_arr)--;
		}
		while (**sol_arr == RA && need) 
		{   //ft_printf("JREMPLACE UN RA PAR UN RR, need: %d\n", need);
			**sol_arr = RR;	
			need--;	
			(*sol_arr)--;
		}
		while (**sol_arr != PB)
			(*sol_arr)++;//ft_printf("javance jusquau pb\n");
		t_eop tmp;	
		t_eop tmp2;
	//	ft_printf("AVAVAVAVAVANT need: %d solarr actuel: %d , plus un %d \n", need, **sol_arr, (*sol_arr)++);
	t_eop *sol_arr_sav; 
			sol_arr_sav = *sol_arr;
		while (need > 0)
		{	//ft_printf("jinsere un rb\n");
			tmp = RB;//**sol_arr; // pb
			//**sol_arr = RB;		// rb	
	
			while (*(*sol_arr))
			{	
				tmp2 = **sol_arr;
				**sol_arr = tmp;	
			//	tmp = *(*sol_arr + 1)	
			//	*(*sol_arr + 1) = tmp;//**sol_arr; // rb
				tmp = tmp2;
				(*sol_arr)++;
			}
			*(*sol_arr)++ = tmp;
			**sol_arr = 0;
			*sol_arr = sol_arr_sav;		
			need--;
		}
	while (**sol_arr != PB)
			(*sol_arr)++;
		//ft_printf("jai finit walllaradim\n");
	}
}
void	try_rr1(t_eop **sol_arr, int n_ra, int n_rb, int seclst_size)
{
	int	need;
	
	need = seclst_size - n_rb; 

	(*sol_arr)--;
	while (**sol_arr == RRB) 
	{	
		delone_sol(*sol_arr);	
		(*sol_arr)--;
	}
	while (**sol_arr != PB)
		(*sol_arr)++;		
	t_eop tmp;	
	t_eop tmp2;
	t_eop *sol_arr_sav; 
	sol_arr_sav = *sol_arr;
	while (need > 0)
	{
		tmp = RB;
		while (*(*sol_arr))
		{	
			tmp2 = **sol_arr;
			**sol_arr = tmp;	
			tmp = tmp2;
			(*sol_arr)++;
		}
		*(*sol_arr)++ = tmp;
		**sol_arr = 0;
		*sol_arr = sol_arr_sav;		
		need--;
	}
	while (**sol_arr != PB)
		(*sol_arr)++;		
}
void	sol_optim_extrem(t_eop **sol_arr)
{
	int		seclst_size;
	int		n_ra;
	int		n_rb;

	t_eop	*sol_arr_sav;
	sol_arr_sav = *sol_arr;
	t_eop	*sol_arr_sav2;
	
//	ft_printf("EXTREM\n");
	seclst_size = 0;
	n_ra = 0;
	n_rb = 0;
	while (**sol_arr)
	{		//ft_printf("EXTREM IN\n");		
		if (**sol_arr == PB)
			seclst_size++;
		n_ra = 0;	
		while (**sol_arr == RA)
		{		
			n_ra++;			
			(*sol_arr)++;
		}
		n_rb = 0;
		while (**sol_arr == RRB)
		{		
			n_rb++;			
			(*sol_arr)++;		
		}
		if (n_ra && n_rb && seclst_size > 0 && n_ra >= n_rb)
		{
			//ft_printf("secsize: %d  RA %d, RRB :%d\n", seclst_size, n_ra, n_rb);		
			//sol_arr_sav = *sol_arr;
			char	*op_char_arr[OP];
		 	init_op_char_arr(op_char_arr);
		//	ft_printf("AV TRY");
			
			// sol_arr_sav2 = *sol_arr;
			// *sol_arr = sol_arr_sav;
			// print_tab(*sol_arr, op_char_arr);			
			// *sol_arr = sol_arr_sav2;
			
			try_rr(sol_arr, n_ra, n_rb, seclst_size);
			//ft_printf("AP TRY");
			
			// sol_arr_sav2 = *sol_arr;
			// *sol_arr = sol_arr_sav;
			// print_tab(*sol_arr, op_char_arr);			
			// *sol_arr = sol_arr_sav2;
			
			//*sol_arr = sol_arr_sav;
		//	ft_printf("EXTREM FIN size:%d, na: %d, nb: %d\n", seclst_size, n_ra, n_rb);		
		}
		if (n_rb || n_ra)
			(*sol_arr)--;
		// if (n_ra && n_rb)
		// 	ft_printf("EXTREM size:%d, na: %d, nb: %d\n", seclst_size, n_ra, n_rb);
		// else
		// try_rrr(sol_arr, n_ra, n_rb);		
		(*sol_arr)++;
	}	
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
		while (**sol_arr == RB && n_ra--)
		{		
			*(*sol_arr - ++n_rb) = RR;				
			delone_sol(*sol_arr);			
		}
		n_ra = 0;
		while (**sol_arr == RRA)
		{		
			n_ra++;			
			(*sol_arr)++;
		}
		n_rb = 0;
		while (**sol_arr == RRB && n_ra--)
		{		
			*(*sol_arr - (++n_rb)) = RRR;				
			delone_sol(*sol_arr);			
		}				
		(*sol_arr)++;
	}	
}

void	alg(t_list **la, t_list **lb, int n_piece, int ok)
{
	t_list	*top_item;
	t_list	*bot_item;
	t_list	*one;	
	int 	actual_piece;
	double	range;
	
	t_eop sl_arr[42000];
	
	
	
	int	i = -1;
	while (++i < 42000)
		sl_arr[i] = 0;
	t_eop *sol_arr = sl_arr;
		
	range = get_range(*la, n_piece);	
	actual_piece = 0;	
	while (actual_piece++ <= n_piece)
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
	sol_arr = sl_arr;
	sol_optim_extrem(&sol_arr);
//	ft_printf("choose another alg\n");
	sol_arr = sl_arr;
//	ft_printf("group: %d\n", n_piece);
	if(!ok)
	{
		i = 0;
		while (*sol_arr++)	
			i++;		
	}
//	ft_printf("sol: %d\n", i);
	// if (ok)
	 	print_tab(sol_arr, op_char_arr);
	// print_lst(*la, *lb);
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


// t_eop sl_arr[42000];	
// 	int	i = -1;
// 	while (++i < 42000)
// 		sl_arr[i] = 0;
// 	t_eop *sol_arr = sl_arr;
// 	sol_arr[0] = RA;
// 	sol_arr[1] = RA;
// 	sol_arr[2] = PB;
// 	sol_arr[3] = RA;
// 	sol_arr[4] = RA;
// 	sol_arr[5] = RA;
// 	sol_arr[6] = RRB;
// 	sol_arr[7] = RRB;
// 	sol_arr[8] = PB;
// sol_optim_extrem(&sol_arr);
// sol_arr = sl_arr;
// 	char	*op_char_arr[OP];
// 	init_op_char_arr(op_char_arr);
	
//  	print_tab(sol_arr, op_char_arr);
// 	return 0;



	//int	lstsize = ft_lstsize(a_head);	
	//ft_printf(" len: %d\n", lstsize); 	
	//alg_forwarding(&a_head, &b_head, argc);
	//alg_quick_sort(&a_head, &b_head);
	int	n_piece = 11;
	//while (++n_piece < 7)
//	{
		// alg(&a_head, &b_head, n_piece, 0);
		// ft_lstclear(&a_head, NULL);
		// ft_lstclear(&b_head, NULL);
		// init_list(&a_head, argc, args_arr);
//	}
	//	ft_lstclear(&a_head, NULL);
	//	ft_lstclear(&b_head, NULL);
		//init_list(&a_head, argc, args_arr);
	alg(&a_head, &b_head, n_piece, 1);
	//print_lst(a_head, b_head);	
	free(args_arr);
	ft_lstclear(&a_head, NULL);
	ft_lstclear(&b_head, NULL);
	return (0);
}