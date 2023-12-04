/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svidot <svidot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 06:50:49 by svidot            #+#    #+#             */
/*   Updated: 2023/12/04 06:50:49 by svidot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_utils.h"
#include "ft_printf.h"

int	is_sort(t_list *la, t_list *lb)
{
	if (ft_lstsize(lb))
		return (0);
	while (la && la->next)
	{
		if (*(int *) la->content > *(int *) la->next->content)
			return (0);
		la = la->next;
	}
	return (1);
}

void	print_lst(t_list *la, t_list *lb)
{
	if (!la && !lb)
		return ;
	ft_printf("\n\033[%dm", 96);
	ft_printf(" ~~~~~~~~~~~~~~~~~~~~ ~~(,,°>\n");
	ft_printf("\033[0m");
	while (la || lb)
	{
		if (la)
		{
			ft_printf(" %d", *(int *) la->content);
			la = la->next;
		}
		ft_printf("\r\t\t\b\b\b|*|  ");
		if (lb)
		{
			ft_printf(" %d", *(int *) lb->content);
			lb = lb->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
