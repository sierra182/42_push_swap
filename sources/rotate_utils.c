/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:51:12 by marvin            #+#    #+#             */
/*   Updated: 2023/11/12 19:51:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate(t_list **lst)
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

void	rev_rotate(t_list **lst)
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