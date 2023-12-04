/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:51:25 by svidot            #+#    #+#             */
/*   Updated: 2023/12/04 06:51:25 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rotate(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		ft_lstadd_back(lst, *lst);
		tmp = (*lst)->next;
		(*lst)->next = NULL;
		*lst = tmp;
		return (1);
	}
	return (0);
}

int	rev_rotate(t_list **lst)
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
		return (1);
	}
	return (0);
}
