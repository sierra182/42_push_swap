/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:59:33 by svidot            #+#    #+#             */
/*   Updated: 2023/10/11 16:23:25 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;		
		ft_lstdelone(*lst, del);		
		*lst = temp;
	}
}
